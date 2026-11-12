#include "Stepper.h"

namespace {
    double F(double u) { return -u; }
}

inline double RK4::step(double u, double h) {
    const double k1 = F(u);
    const double k2 = F(u + h * k1 / 2.0);
    const double k3 = F(u + h * k2 / 2.0);
    const double k4 = F(u + h * k3);
    return u + h * (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
}

inline const char *RK4::name() const {
    return "RK4";
}

double errorCheck(Stepper& stepper, double h) {
    double u = 1;
    unsigned int N = std::roundl(1/h);
    while (N != 0) {
        u = stepper.step(u, h);
        --N;
    }
    return std::abs(u - std::exp(-1.0));
}