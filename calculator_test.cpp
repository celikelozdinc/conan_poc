#include <gtest/gtest.h>
#include "declare.h"
#include "car.h"
#include <iostream>

//function object class

class CalculatorTest : public ::testing::Test {
public:
    void SetUp() override {
        std::cout << "CalculatorTest::SetUp()\n";
    }
    void TearDown() override {
        std::cout << "CalculatorTest::TearDown()\n";
    }
};


TEST_F(CalculatorTest, DISABLED_Test) {
    std::cout << "CalculatorTest::operator()\n";
    std::function<int(int)> func3 = third_t();  // function object
    int got = func3(30);
    int expected = 10;

    ASSERT_EQ(expected, got);
}


TEST_F(CalculatorTest, CarTest) {
    Car car{};
    CarWrapper<Car> wrapper_real{car};
    ASSERT_EQ(17, wrapper_real.get_trunk_size());

    MockedCar mockCar{};
    EXPECT_CALL(mockCar, get_trunk_size()).WillOnce(testing::Return(41));
    //MockedCar mockCar{};
    //CarWrapper<MockedCar> wrapper_fake{mockCar};
    //EXPECT_CALL(mockCar, get_trunk_size()).WillOnce(testing::Return(41));
    //ASSERT_EQ(25, wrapper_real.get_trunk_size());
}