#include <iostream>
#include <chrono>
#include <fstream>
#include <format>
#include <cmath>

class Stepper {
public:
	virtual double step(double u, double h);
	virtual	const char* name() const = 0;
};

class RK4 : public Stepper {
public:
	virtual double step(double u, double h) override;
	virtual	const char* name() const override;
};

double errorCheck(Stepper& stepper, double h);