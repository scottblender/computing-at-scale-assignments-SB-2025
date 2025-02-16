#ifndef POLYNOMIAL_INTEGRATOR_HPP
#define POLYNOMIAL_INTEGRATOR_HPP

#include <iostream>
#include <vector>
#include "Polynomial.hpp"
#include "GaussLegendre.hpp"
#include "GaussLobatto.hpp"
#include "GaussChebyshev.hpp"

// Function declaration for polynomial_integrate
double integrate(int integrator_type, std::vector<double> coeffs, double a, double b, int num_points, int case_);

#endif // POLYNOMIAL_INTEGRATOR_HPP
