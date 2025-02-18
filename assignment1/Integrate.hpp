#ifndef INTEGRATOR_HPP
#define INTEGRATOR_HPP

#include <iostream>
#include <vector>
#include "Polynomial.hpp"       // Include the header file for Polynomial class
#include "GaussLegendre.hpp"    // Include the header for GaussLegendre integration
#include "GaussLobatto.hpp"     // Include the header for GaussLobatto integration
#include "GaussChebyshev.hpp"   // Include the header for GaussChebyshev integration

// Function declaration for polynomial_integrate
// This function performs the integration of a polynomial using the specified integration method.
double integrate(int integrator_type,    // Type of the integration method (1 for Gauss-Legendre, 2 for Gauss-Lobatto, 3 for Gauss-Chebyshev)
                 std::vector<double> coeffs,  // Coefficients of the polynomial to be integrated
                 double a,              // Lower bound of the integration interval
                 double b,              // Upper bound of the integration interval
                 int num_points,        // Number of integration points
                 int case_ = 1);        // Optional parameter for Gauss-Chebyshev case (default is 1)

#endif // INTEGRATOR_HPP
