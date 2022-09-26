#include <limits.h>
#include <stdexcept>
#include "AsynchronousDirectory.h"
#include "SynchronousDirectory.h"
#include "File.h"
#include "Root.h"
#include "gtest/gtest.h"
namespace
{
    TEST(AsynchronousDirectoryAddChildTest, testAddFile)
    {
        AsynchronousDirectory *d = new AsynchronousDirectory("d");
        File *f = new File("f.txt");

        EXPECT_EQ(0, d->getChildrenCount());
        d->addChild(f);
        EXPECT_EQ(1, d->getChildrenCount());
        EXPECT_EQ("f.txt", d->getChild(0)->getName());
        EXPECT_EQ("File", d->getChild(0)->getType());
        EXPECT_EQ(false, d->getChild(0)->isSynchronous());
        delete d;
    }

    TEST(AsynchronousDirectoryAddChildTest, testAddAsyncDirectory)
    {
        AsynchronousDirectory *d = new AsynchronousDirectory("d");
        AsynchronousDirectory *d2 = new AsynchronousDirectory("d2");

        EXPECT_EQ(0, d->getChildrenCount());
        d->addChild(d2);
        EXPECT_EQ(1, d->getChildrenCount());
        EXPECT_EQ("d2", d->getChild(0)->getName());
        EXPECT_EQ("Directory", d->getChild(0)->getType());
        EXPECT_EQ(false, d->getChild(0)->isSynchronous());
        delete d;
    }

    TEST(AsynchronousDirectoryAddChildTest, testAddSyncDirectory)
    {
        AsynchronousDirectory *d = new AsynchronousDirectory("d");
        SynchronousDirectory *d2 = new SynchronousDirectory("d2");

        EXPECT_EQ(0, d->getChildrenCount());
        try
        {
            d->addChild(d2);
            FAIL();
        }
        catch (std::invalid_argument &e)
        {
            EXPECT_EQ(e.what(), std::string("Cannot add a synchronous node to an asynchronous directory"));
        }
        catch (...)
        {
            FAIL();
        }
        EXPECT_EQ(0, d->getChildrenCount());
        delete d2;
        delete d;
    }

    TEST(AsynchronousDirectoryAddChildTest, testAddRoot)
    {
        AsynchronousDirectory *d = new AsynchronousDirectory("d");
        Root *r = new Root();
        EXPECT_EQ(0, d->getChildrenCount());
        try
        {
            d->addChild(r);
            FAIL();
        }
        catch (std::invalid_argument &e)
        {
            EXPECT_EQ(e.what(), std::string("Cannot add a synchronous node to an asynchronous directory"));
        }
        catch (...)
        {
            FAIL();
        }
        EXPECT_EQ(0, d->getChildrenCount());
        delete d;
        delete r;
    }

    TEST(AsynchronousDirectoryAddChildTest, testAddMultiple)
    {
        AsynchronousDirectory *d = new AsynchronousDirectory("d");
        EXPECT_EQ(0, d->getChildrenCount());
        d->addChild(new File("f1.txt"));
        EXPECT_EQ(1, d->getChildrenCount());
        d->addChild(new File("f2.txt"));
        EXPECT_EQ(2, d->getChildrenCount());
        d->addChild(new AsynchronousDirectory("d1"));
        EXPECT_EQ(3, d->getChildrenCount());
        d->addChild(new AsynchronousDirectory("d2"));
        EXPECT_EQ(4, d->getChildrenCount());
        try
        {
            d->addChild(new SynchronousDirectory("d3"));
            FAIL();
        }
        catch (std::invalid_argument &e)
        {
            EXPECT_EQ(e.what(), std::string("Cannot add a synchronous node to an asynchronous directory"));
        }
        catch (...)
        {
            FAIL();
        }
        EXPECT_EQ(4, d->getChildrenCount());
        delete d;
    }

    TEST(AsynchronousDirectoryAddChildTest, testAddNull)
    {
        AsynchronousDirectory *d = new AsynchronousDirectory("d");
        EXPECT_EQ(0, d->getChildrenCount());
        try
        {
            d->addChild(NULL);
            FAIL();
        }
        catch (std::invalid_argument &e)
        {
            EXPECT_EQ(e.what(), std::string("Cannot add a null node"));
        }
        catch (...)
        {
            FAIL();
        }
        EXPECT_EQ(0, d->getChildrenCount());
        delete d;
    }
}
