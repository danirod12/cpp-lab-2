#include <iostream>

long double fraq(long double origin) {
    long double result = 1;
    while (origin > 0) {
        result *= origin;
        origin -= 2;
    }
    return result;
}

long double pow(long double origin, int power) {
    long double result = 1;
    while (power > 0) {
        power--;
        result *= origin;
    }
    return result;
}

long double t(long double origin) {
    long double up = 0, down = 0;
    for (int k = 0; k <= 10; ++k) {
        up += pow(origin, 2 * k + 1) / fraq(2 * k + 1);
        down += pow(origin, 2 * k) / fraq(2 * k);
    }
    return up / down;
}

long double f(long double y) {
    return (7 * t(0.25) + 2 * t(1 + y)) / (6 - t(y * y - 1));
}

int main()
{
    int y;
    std::cin >> y;
    std::cout << f(y);
}
