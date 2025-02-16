#include <iostream>
#include <vector>
#include "GaussChebyshev.hpp"
#include "Integrate.hpp"

int main() {
    // Define the polynomial coefficients for x, corresponding to the polynomial f(x) = x
    std::vector<double> coeffs = {0, 1, 0};  // Polynomial: 0 + 1*x + 0*x^2 = x
    
    // Perform the integration using Gauss-Chebyshev method with 4 points (case 2)
    // Integrate over the range [-1.0, 1.0]
    double result = integrate(3, coeffs, -1.0, 1.0, 4, 2);

    // Output the result of the integration
    std::cout << "Integral result: " << result << std::endl;

    // Create a Polynomial object from the given coefficients
    Polynomial<double> poly(coeffs);

    // Test the polynomial at x = 0
    double x = 0;
    double result_at_0 = poly(x);  // Evaluate polynomial at x = 0
    std::cout << "Polynomial value at x = " << x << " is: " << result_at_0 << std::endl;

    // Test the polynomial at x = 1
    x = 1;
    double result_at_1 = poly(x);  // Evaluate polynomial at x = 1
    std::cout << "Polynomial value at x = " << x << " is: " << result_at_1 << std::endl;

    // Define the number of integration points for Gauss-Chebyshev method
    int num_p = 4;

    // Create a Gauss-Chebyshev object with 4 points (case 2)
    GaussChebyshev gcheb(num_p, 2);

    // Loop over the nodes of Gauss-Chebyshev and evaluate the polynomial at each node
    for(auto i = 0; i < num_p; ++i) {
        std::cout << "Weight: " << gcheb.getWeights()[i] << std::endl;  // Output weight for current node
        std::cout << "Node: " << gcheb.getNodes()[i] << std::endl;  // Output node for current weight

        x = gcheb.getNodes()[i];  // Get the current node
        double result_at_xi = poly(x);  // Evaluate the polynomial at the current node
        std::cout << "Polynomial value at x = " << x << " is: " << result_at_xi << std::endl;
    }

    return 0;  // Return 0 to indicate successful execution
}
