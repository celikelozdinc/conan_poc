#include <iostream>
#include <functional>

//free function
int half(int x) {return x/2;}

//function object class
struct third_t{
    int operator()(int x) {return x/3;}
};

int main() {
    std::function<int(int)> func1 = half;  // function
    std::function<int(int)> func2 = &half;   // function pointer
    std::function<int(int)> func3 = third_t();  // function object
    std::function<int(int)> func4 = [](int x) {return x/4;};  // Lambda expression

    std::cout<< "func1(60) =  " << func1(60) << "\n";
    std::cout<< "func2(60) =  " << func2(60) << "\n";
    std::cout<< "func3(60) =  " << func3(60) << "\n";
    std::cout<< "func4(60) =  " << func4(60) << "\n";
    return 0;
}