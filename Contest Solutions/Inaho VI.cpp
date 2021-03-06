#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
int main()
{
    int x;
    std::cin >> x;
    if (x >= 1000)
    {
        std::cout << 0.4383 << "\n" << 0.3606;
        return 0;
    }
    double a = 1.0, b = 0.0;
    for (int i = 1; i <= x; i++)
    {
        double ta = a, tb = b;
        a = std::exp(-M_PI * tb / 2.0) * std::cos(M_PI * ta / 2.0);
        b = std::exp(-M_PI * tb / 2.0) * std::sin(M_PI * ta / 2.0);
    }
    std::cout << std::setprecision(5) << a << "\n" << b;
    return 0;
}
