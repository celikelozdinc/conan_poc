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
    std::unique_ptr<Car> car = std::make_unique<Car>();
    CarWrapper<Car> wrapper_real{std::move(car)};
    ASSERT_EQ(17, wrapper_real.get_trunk_size());

    std::unique_ptr<MockedCar> mockCar = std::make_unique<MockedCar>();
    EXPECT_CALL(*mockCar.get(), get_trunk_size()).WillOnce(testing::Return(41));
    CarWrapper<MockedCar> wrapper_fake{std::move(mockCar)};
    ASSERT_EQ(41, wrapper_fake.get_trunk_size());
}