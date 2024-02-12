// C++ allows specifying default parameter values!
#include <iostream>
#include <string>
#include <queue>

int half(int x, int division = 2) {
    return x / division;
}

double half(double x, double division = 2.0) {
    return x / division;
}

half(10); // 5
half(10, 3); // 3
half(10.0); // 5.0