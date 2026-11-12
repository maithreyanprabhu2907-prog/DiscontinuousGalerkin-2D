#include "Stepper.h"

int main() {
    RK4 rk4;
    double err = errorCheck(rk4, 0.01);
    std::cout << rk4.name() << ": " << err << '\n';
}