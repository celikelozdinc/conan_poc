#include <iostream>
#include <gtest/gtest.h>

//function object class

class CalculatorTest : public ::testing::Test {
public:
    void SetUp() override {
        std::cout << "CalculatorTest::SetUp()\n";
    }
    void TearDown() override {
        std::cout << "CalculatorTest::TearDown()\n";
    }
    int operator()(int x) {
        std::cout << "CalculatorTest::operator()\n";
        return x/2;
    }
};

/*
TEST_F(CalculatorTest, FreeFunc) {
    int got = this->operator()(40);
    int expected = 20;

    ASSERT_EQ(expected, got);
}
*/
