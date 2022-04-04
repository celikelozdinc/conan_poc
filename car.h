#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <gmock/gmock.h>

class Car {
public:
    Car() {
        std::cout << "Car::Car()\n";
    }

    ~Car() {
        std::cout << "Car::~Car()\n";
    }

    void start_engine() {
        std::cout << "Car::start_engine()\n";
    }

    int get_trunk_size() const {
        std::cout << "Car::get_trunk_size()\n";
        return 17;
    }

    void add_fuel(double quantity) {
        std::cout << "Car::add_fuel() => " << quantity << "\n";
    }
};

class MockedCar {
public:
    MOCK_METHOD(void, start_engine, (), ());
    MOCK_METHOD(int, get_trunk_size, (), (const));
    MOCK_METHOD(void, add_fuel, (double quantity), ());
};

template <typename ConcreteCar>
class CarWrapper {
public:
    explicit CarWrapper(ConcreteCar* cc) : _concreteCar{cc} {
        std::cout << "CarWrapper::CarWrapper()\n";
    }

    void start_engine() {
        std::cout << "CarWrapper::start_engine()\n";
        _concreteCar->start_engine();
    }

    int get_trunk_size() const {
        std::cout << "CarWrapper::get_trunk_size()\n";
        return _concreteCar->get_trunk_size();
    }

    void add_fuel(double quantity) {
        std::cout << "CarWrapper::add_fuel() => " << quantity << "\n";
        _concreteCar->add_fuel(quantity);
    }


private:
    ConcreteCar* _concreteCar;
};

#endif