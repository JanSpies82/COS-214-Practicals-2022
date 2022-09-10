#include <limits.h>
#include <stdexcept>
#include "Root.h"
#include "SynchronousDirectory.h"
#include "AsynchronousDirectory.h"
#include "File.h"
#include "gtest/gtest.h"

class RootTest : public testing::Test
{
public:
    virtual void SetUp() override
    {
        root = new Root();
        d11 = new SynchronousDirectory("d11");
        d12 = new AsynchronousDirectory("d12");
        d21 = new AsynchronousDirectory("d21");
        d31 = new AsynchronousDirectory("d31");
        d32 = new AsynchronousDirectory("d32");

        d21->addDirectory(d31);
        d21->addDirectory(d32);

        d11->addFile(new File("f21.txt"));
        d11->addDirectory(d21);

        d12->addFile(new File("f22.txt"));

        root->addDirectory(d11);
        root->addFile(new File("f11.txt"));
        root->addFile(new File("f12.txt"));
        root->addDirectory(d12);
    }
    virtual void TearDown() override
    {
        delete root;
    }
    Root *root;
    Directory *d11;
    Directory *d12;
    Directory *d21;
    Directory *d31;
    Directory *d32;
};
namespace
{
    TEST_F(RootTest, TestConstructor)
    {
        EXPECT_EQ("root", root->getName());
        EXPECT_EQ("Directory", root->getType());
        EXPECT_EQ(true, root->isSynchronous());
        EXPECT_EQ(4, root->getChildrenCount());
    }
}
namespace
{
    TEST_F(RootTest, AddChildren)
    {
        EXPECT_EQ(4, root->getChildrenCount());
        EXPECT_EQ(2, d11->getChildrenCount());
        EXPECT_EQ(1, d12->getChildrenCount());
        EXPECT_EQ(2, d21->getChildrenCount());
        EXPECT_EQ(0, d31->getChildrenCount());
        EXPECT_EQ(0, d32->getChildrenCount());
    }
}
namespace
{
    TEST_F(RootTest, RemoveChildren)
    {
        EXPECT_EQ(4, root->getChildrenCount());
        EXPECT_EQ(2, d11->getChildrenCount());
        EXPECT_EQ(1, d12->getChildrenCount());
        EXPECT_EQ(2, d21->getChildrenCount());
        EXPECT_EQ(0, d31->getChildrenCount());
        EXPECT_EQ(0, d32->getChildrenCount());

        root->removeChild("d11");

        EXPECT_EQ(3, root->getChildrenCount());

        root->removeChild("d12");

        EXPECT_EQ(2, root->getChildrenCount());

        root->removeChild("f11.txt");

        EXPECT_EQ(1, root->getChildrenCount());

        try
        {
            root->removeChild("f11.txt");
            FAIL();
        }
        catch (std::invalid_argument &err)
        {
            EXPECT_EQ(err.what(), std::string("No child with name f11.txt found"));
        }
        catch (...)
        {
            FAIL();
        }

        root->removeChild("f12.txt");

        EXPECT_EQ(0, root->getChildrenCount());
    }
}

namespace
{
    TEST_F(RootTest, TestDoubleSnapshotRestore)
    {
        root->createSnapshot();
        root->removeAllChildren();
        ASSERT_EQ(0, root->getChildrenCount());
        root->restoreSnapshot();
        root->createSnapshot();
        ASSERT_EQ(4, root->getChildrenCount());
        Directory *nd11 = (Directory *)root->getChild(0);
        Directory *nd12 = (Directory *)root->getChild(3);
        Directory *nd21 = (Directory *)nd11->getChild(1);
        Directory *nd31 = (Directory *)nd21->getChild(0);
        Directory *nd32 = (Directory *)nd21->getChild(1);

        EXPECT_EQ(2, nd11->getChildrenCount());
        EXPECT_EQ(1, nd12->getChildrenCount());
        EXPECT_EQ(2, nd21->getChildrenCount());
        EXPECT_EQ(0, nd31->getChildrenCount());
        EXPECT_EQ(0, nd32->getChildrenCount());

        EXPECT_EQ("d11", root->getChild(0)->getName());
        EXPECT_EQ("f11.txt", root->getChild(1)->getName());
        EXPECT_EQ("f12.txt", root->getChild(2)->getName());
        EXPECT_EQ("d12", root->getChild(3)->getName());

        EXPECT_EQ("f21.txt", nd11->getChild(0)->getName());
        EXPECT_EQ("d21", nd11->getChild(1)->getName());

        EXPECT_EQ("d31", nd21->getChild(0)->getName());
        EXPECT_EQ("d32", nd21->getChild(1)->getName());

        EXPECT_EQ("f22.txt", nd12->getChild(0)->getName());

        root->addFile(new File("newfile.txt"));
        nd11->addDirectory(new SynchronousDirectory("newdir"));

        root->restoreSnapshot();

        ASSERT_EQ(4, root->getChildrenCount());
        nd11 = (Directory *)root->getChild(0);
        nd12 = (Directory *)root->getChild(3);
        nd21 = (Directory *)nd11->getChild(1);
        nd31 = (Directory *)nd21->getChild(0);
        nd32 = (Directory *)nd21->getChild(1);

        EXPECT_EQ(2, nd11->getChildrenCount());
        EXPECT_EQ(1, nd12->getChildrenCount());
        EXPECT_EQ(2, nd21->getChildrenCount());
        EXPECT_EQ(0, nd31->getChildrenCount());
        EXPECT_EQ(0, nd32->getChildrenCount());

        EXPECT_EQ("d11", root->getChild(0)->getName());
        EXPECT_EQ("f11.txt", root->getChild(1)->getName());
        EXPECT_EQ("f12.txt", root->getChild(2)->getName());
        EXPECT_EQ("d12", root->getChild(3)->getName());

        EXPECT_EQ("f21.txt", nd11->getChild(0)->getName());
        EXPECT_EQ("d21", nd11->getChild(1)->getName());

        EXPECT_EQ("d31", nd21->getChild(0)->getName());
        EXPECT_EQ("d32", nd21->getChild(1)->getName());

        EXPECT_EQ("f22.txt", nd12->getChild(0)->getName());

        try
        {
            root->access("newfile.txt");
            FAIL();
        }
        catch (std::invalid_argument &err)
        {
            EXPECT_EQ(err.what(), std::string("No child with name newfile.txt found"));
        }
        catch (...)
        {
            FAIL();
        }

        try
        {
            nd11->removeDirectory("newdir");
            FAIL();
        }
        catch (std::invalid_argument &err)
        {
            EXPECT_EQ(err.what(), std::string("No child with name newdir found"));
        }
        catch (...)
        {
            FAIL();
        }
    }
}

namespace
{
    TEST_F(RootTest, TestNoSnapshotRestore)
    {
        try
        {
            root->restoreSnapshot();
            FAIL();
        }
        catch (std::runtime_error &err)
        {
            EXPECT_EQ(err.what(), std::string("No Snapshots available"));
        }
        catch (...)
        {
            FAIL();
        }

        root->createSnapshot();
        root->clearAll();

        try
        {
            root->restoreSnapshot();
            FAIL();
        }
        catch (std::runtime_error &err)
        {
            EXPECT_EQ(err.what(), std::string("No Snapshots available"));
        }
        catch (...)
        {
            FAIL();
        }
    }
}
