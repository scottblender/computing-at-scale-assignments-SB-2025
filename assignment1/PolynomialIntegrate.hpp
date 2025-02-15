#ifndef POLYNOMIAL_INTEGRATOR_HPP
#define POLYNOMIAL_INTEGRATOR_HPP

#include <iostream>
#include <vector>
#include "Polynomial.hpp"
#include "GaussLegendre.hpp"
#include "GaussLobatto.hpp"
#include "GaussChebyshev.hpp"

// Function declaration for polynomial_integrate
double polynomial_integrate(int integrator_type, int case_, std::vector<double> coeffs, double a, double b, int num_points);

#endif // POLYNOMIAL_INTEGRATOR_HPP
