#include <limits.h>
#include <stdexcept>
#include "Root.h"
#include "gtest/gtest.h"
namespace
{
    TEST(RootTest, Constructor)
    {
        Root *root = new Root();
        EXPECT_EQ("root", root->getName());
        EXPECT_EQ("Directory", root->getType());
        EXPECT_EQ(true, root->isSynchronous());
        EXPECT_EQ(0, root->getChildrenCount());
        delete root;
    }
} // namespace