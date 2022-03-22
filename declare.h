#include <functional>

#ifndef DECLARE_H
#define DECLARE_H

//free function
int half(int x) {return x/2;}

//function object class
struct third_t{
    int operator()(int x) {return x/3;}
};

#endif
