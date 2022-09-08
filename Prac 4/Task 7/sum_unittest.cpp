#include <limits.h>
#include <stdexcept>
#include "sum.h"
#include "gtest/gtest.h"

namespace {

    // Tests Sum()

    // ============ Precondition 1 Testing ============
    // Test Precondition 1 Negative
    TEST(IsSumTest, TestPreconditionOneNegative) {
        try {
            Sum(-5,5);
            FAIL();
        } catch (std::invalid_argument & err) {
            EXPECT_EQ(err.what(),std::string("a must be greater than zero"));
        } catch(...) {
            FAIL();
        }
    }

    // Test Precondition 1 Positive
    TEST(IsSumTest, TestPreconditionOnePositive) {
        EXPECT_EQ(10, Sum(5,5));
    }

    // Test Precondition 1 Bounds
    TEST(IsSumTest, TestPreconditionOneBounds) {
        try {
            Sum(0,5);
            FAIL();
        } catch (std::invalid_argument & err) {
            EXPECT_EQ(err.what(),std::string("a must be greater than zero"));
        } catch(...) {
            FAIL();
        }
    }

    // ============ Precondition 2 Testing ============
    // Test Precondition 2 Negative
    TEST(IsSumTest, TestPreconditionTwoNegative) {
        try {
            Sum(5,-5);
            FAIL();
        } catch (std::invalid_argument & err) {
            EXPECT_EQ(err.what(),std::string("b must be equal to greater than zero"));
        } catch(...) {
            FAIL();
        }
    }

    // Test Precondition 2 Positive
    TEST(IsSumTest, TestPreconditionTwoPositive) {
        EXPECT_EQ(13, Sum(6,7));
    }

    // Test Precondition 2 Bounds
    TEST(IsSumTest, TestPreconditionTwoBounds) {
        EXPECT_EQ(7, Sum(7,0));
    }

    // ============ Preconditions Bounds Testing ============
    // Test Preconditions Bounds
    TEST(IsSumTest, TestPreconditionsBounds) {
        try {
            Sum(0,0);
            FAIL();
        } catch (std::invalid_argument & err) {
            EXPECT_EQ(err.what(),std::string("a must be greater than zero"));
        } catch(...) {
            FAIL();
        }
    }

    // ============ Positive Testing ============
    // Test Preconditions Bounds
    TEST(IsSumTest, PositiveTesting) {
        EXPECT_EQ(2, Sum(1,1));
        EXPECT_EQ(12, Sum(5,7));
        EXPECT_EQ(101, Sum(100,1));
    }
    
}  // namespace

// Call RUN_ALL_TESTS() in main().
//
// We do this by linking in src/gtest_main.cc file, which consists of
// a main() function which calls RUN_ALL_TESTS() for us.
//
// This runs all the tests you've defined, prints the result, and
// returns 0 if successful, or 1 otherwise.
//
// Did you notice that we didn't register the tests?  The
// RUN_ALL_TESTS() macro magically knows about all the tests we
// defined.  Isn't this convenient?
