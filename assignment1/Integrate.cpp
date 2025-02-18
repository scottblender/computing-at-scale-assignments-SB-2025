#include <iostream>
#include <vector>
#include <stdexcept> // For std::invalid_argument
#include "Polynomial.hpp"
#include "GaussLegendre.hpp"
#include "GaussLobatto.hpp"
#include "GaussChebyshev.hpp"

// Helper function for integration computation
double performIntegration(std::vector<double>& weights, std::vector<double>& nodes, 
                          const Polynomial<double>& poly, double coeff1, double coeff2, int num_points) {
    double result = 0.0;
    for (int i = 0; i < num_points; ++i) {
        double xi = coeff1 * nodes[i] + coeff2; // Transform the nodes to the integration bounds
        result += weights[i] * poly(xi); // Accumulate the result using weights and polynomial evaluation
    }
    return coeff1 * result; // Return the scaled result
}

// Function to perform numerical integration based on the specified integrator type
double integrate(int integrator_type, std::vector<double> coeffs, double a, double b, int num_points, int case_ = 1) {

    // Determine the order of the polynomial from the coefficients
    int order_of_polynomial = coeffs.size() - 1;

    // Gauss-Legendre integration (integrator_type == 1)
    if (integrator_type == 1) {
        // Check if the polynomial order exceeds the exact integration limit
        if (order_of_polynomial > 2 * num_points - 1) {
            throw std::invalid_argument("Polynomial degree exceeds the maximum degree that can be exactly integrated by Gauss-Legendre.");
        }

        GaussLegendre gleg(num_points); // Create GaussLegendre object with specified number of points
        Polynomial<double> poly(coeffs); // Create polynomial object with provided coefficients
        std::vector<double> weights = gleg.getWeights(); // Get weights for Gauss-Legendre
        std::vector<double> nodes = gleg.getNodes(); // Get nodes for Gauss-Legendre

        // Call the helper function to perform the integration
        return performIntegration(weights, nodes, poly, (b - a) / 2.0, (a + b) / 2.0, num_points);
    }

    // Gauss-Lobatto integration (integrator_type == 2)
    else if (integrator_type == 2) {
        // Check if the polynomial order exceeds the exact integration limit
        if (order_of_polynomial > 2 * num_points - 3) {
            throw std::invalid_argument("Polynomial degree exceeds the maximum degree that can be exactly integrated by Gauss-Lobatto.");
        }

        GaussLobatto glob(num_points); // Create GaussLobatto object with specified number of points
        Polynomial<double> poly(coeffs); // Create polynomial object with provided coefficients
        std::vector<double> weights = glob.getWeights(); // Get weights for Gauss-Lobatto
        std::vector<double> nodes = glob.getNodes(); // Get nodes for Gauss-Lobatto

        // Call the helper function to perform the integration
        return performIntegration(weights, nodes, poly, (b - a) / 2.0, (a + b) / 2.0, num_points);
    }

    // Gauss-Chebyshev integration (integrator_type == 3)
    else if (integrator_type == 3) {
        // Check if the bounds for Gauss-Chebyshev are -1 and 1 (valid bounds)
        if (a != -1.0 || b != 1.0) {
            std::cerr << "Error: Gauss-Chebyshev integration is only valid for bounds [-1, 1]." << std::endl;
            throw std::invalid_argument("Bounds for Gauss-Chebyshev integration must be [-1, 1].");
        }

        // Handle both cases for Gauss-Chebyshev integration
        if (case_ == 1 || case_ == 2) {
            GaussChebyshev gcheb(num_points, case_); // Create GaussChebyshev object for the specified case
            Polynomial<double> poly(coeffs); // Create polynomial object with provided coefficients
            std::vector<double> weights = gcheb.getWeights(); // Get weights for Gauss-Chebyshev
            std::vector<double> nodes = gcheb.getNodes(); // Get nodes for Gauss-Chebyshev

            // Call the helper function to perform the integration
            return performIntegration(weights, nodes, poly, (b - a) / 2.0, (a + b) / 2.0, num_points);
        }
        else {
            // If the case type is invalid (not 1 or 2)
            std::cerr << "Invalid case type!" << std::endl;
            return 0.0; // Return 0.0 as an error result
        }
    }
    else {
        // If the integrator type is invalid (not 1, 2, or 3)
        std::cerr << "Invalid integrator type!" << std::endl;
        return 0.0; // Return 0.0 as an error result
    }
}
