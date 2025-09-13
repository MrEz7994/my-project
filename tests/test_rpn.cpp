#include <gtest/gtest.h>
#include "rpn.h"
#include <stdexcept>

TEST(RPNTest, BasicAddition) {
    EXPECT_DOUBLE_EQ(eval_rpn("2 3 +"), 5.0);
}

TEST(RPNTest, WikipediaExample) {
    EXPECT_DOUBLE_EQ(eval_rpn("15 7 1 1 + - / 3 * 2 1 1 + + -"), 5.0);
}

TEST(RPNTest, DivisionByZero) {
    EXPECT_THROW(eval_rpn("1 0 /"), std::runtime_error);
}

TEST(RPNTest, InvalidExpression) {
    EXPECT_THROW(eval_rpn("2 +"), std::runtime_error);
}
