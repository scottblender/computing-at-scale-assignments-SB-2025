#include <iostream>
#include <vector>
#include <stdexcept> // For std::invalid_argument
#include "Polynomial.hpp"
#include "GaussLegendre.hpp"
#include "GaussLobatto.hpp"
#include "GaussChebyshev.hpp"

// Function to perform numerical integration based on the specified integrator type
double integrate(int integrator_type, std::vector<double> coeffs, double a, double b, int num_points, int case_ = 1) {
    // Gauss-Legendre integration (integrator_type == 1)
    if(integrator_type == 1)
    {
        GaussLegendre gleg(num_points); // Create GaussLegendre object with specified number of points
        Polynomial<double> poly(coeffs); // Create polynomial object with provided coefficients
        double result = 0.0; // Variable to accumulate the integration result
        std::vector<double> weights = gleg.getWeights(); // Get weights for Gauss-Legendre
        std::vector<double> nodes = gleg.getNodes(); // Get nodes for Gauss-Legendre
        double coeff1 = (b-a)/2.0; // Scaling coefficient for the integration interval
        double coeff2 = (a+b)/2.0; // Centering coefficient for the integration interval
        
        // Loop over the nodes to compute the result
        for(auto i = 0; i < num_points; ++i){
            double xi = coeff1*nodes[i] + coeff2; // Transform the nodes to the integration bounds
            result += weights[i] * poly(xi); // Accumulate the result using weights and polynomial evaluation
        }
        return coeff1 * result; // Return the scaled result
    }
    
    // Gauss-Lobatto integration (integrator_type == 2)
    else if (integrator_type == 2)
    {
        GaussLobatto glob(num_points); // Create GaussLobatto object with specified number of points
        Polynomial<double> poly(coeffs); // Create polynomial object with provided coefficients
        double result = 0.0; // Variable to accumulate the integration result
        std::vector<double> weights = glob.getWeights(); // Get weights for Gauss-Lobatto
        std::vector<double> nodes = glob.getNodes(); // Get nodes for Gauss-Lobatto
        double coeff1 = (b-a)/2.0; // Scaling coefficient for the integration interval
        double coeff2 = (a+b)/2.0; // Centering coefficient for the integration interval
        
        // Loop over the nodes to compute the result
        for(auto i = 0; i < num_points; ++i){
            double xi = coeff1*nodes[i] + coeff2; // Transform the nodes to the integration bounds
            result += weights[i] * poly(xi); // Accumulate the result using weights and polynomial evaluation
        }
        return coeff1 * result; // Return the scaled result
    }
    
    // Gauss-Chebyshev integration (integrator_type == 3)
    else if (integrator_type == 3) {
        // Check if the bounds for Gauss-Chebyshev are -1 and 1 (valid bounds)
        if (a != -1.0 || b != 1.0) {
            std::cerr << "Error: Gauss-Chebyshev integration is only valid for bounds [-1, 1]." << std::endl;
            throw std::invalid_argument("Bounds for Gauss-Chebyshev integration must be [-1, 1].");
        }

        // Case 1 for Gauss-Chebyshev (case_ == 1)
        if (case_ == 1){
            GaussChebyshev gcheb(num_points, case_); // Create GaussChebyshev object for case 1
            Polynomial<double> poly(coeffs); // Create polynomial object with provided coefficients
            double result = 0.0; // Variable to accumulate the integration result
            std::vector<double> weights = gcheb.getWeights(); // Get weights for Gauss-Chebyshev
            std::vector<double> nodes = gcheb.getNodes(); // Get nodes for Gauss-Chebyshev
            double coeff1 = (b-a)/2.0; // Scaling coefficient for the integration interval
            double coeff2 = (a+b)/2.0; // Centering coefficient for the integration interval
            
            // Loop over the nodes to compute the result
            for(auto i = 0; i < num_points; ++i){
                double xi = coeff1*nodes[i] + coeff2; // Transform the nodes to the integration bounds
                result += weights[i] * poly(xi); // Accumulate the result using weights and polynomial evaluation
            }
            return coeff1 * result; // Return the scaled result
        }
        // Case 2 for Gauss-Chebyshev (case_ == 2)
        else if (case_ == 2) {
            GaussChebyshev gcheb(num_points, case_); // Create GaussChebyshev object for case 2
            Polynomial<double> poly(coeffs); // Create polynomial object with provided coefficients
            double result = 0.0; // Variable to accumulate the integration result
            std::vector<double> weights = gcheb.getWeights(); // Get weights for Gauss-Chebyshev
            std::vector<double> nodes = gcheb.getNodes(); // Get nodes for Gauss-Chebyshev
            double coeff1 = (b-a)/2.0; // Scaling coefficient for the integration interval
            double coeff2 = (a+b)/2.0; // Centering coefficient for the integration interval
            
            // Loop over the nodes to compute the result
            for(auto i = 0; i < num_points; ++i){
                double xi = coeff1*nodes[i] + coeff2; // Transform the nodes to the integration bounds
                result += weights[i] * poly(xi); // Accumulate the result using weights and polynomial evaluation
            }
            return coeff1 * result; // Return the scaled result
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
