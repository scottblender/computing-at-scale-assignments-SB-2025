#include <iostream>
#include <vector>
#include <sstream>
#include "Integrate.hpp"

int main(int argc, char* argv[]) {
    // Check if the required number of arguments are passed
    if (argc < 6) {
        std::cerr << "Insufficient arguments. Please provide integrator type, case type, number of points, bounds a and b, followed by the polynomial coefficients." << std::endl;
        return 1;  // Exit the program if not enough arguments
    }

    // Parse the integrator type (1 for Gauss-Legendre, 2 for Gauss-Lobatto, 3 for Gauss-Chebyshev)
    int integrator_type = std::stoi(argv[1]);
    
    // Parse the case type (for Gauss-Chebyshev, choose case 1 or case 2)
    int case_type = std::stoi(argv[2]);
    
    // Parse the number of points to use in the integration (for example, 3, 4, etc.)
    int num_points = std::stoi(argv[3]);
    
    // Parse the bounds of the integration (a and b)
    double a = std::stod(argv[4]);
    double b = std::stod(argv[5]);

    // Read the polynomial coefficients from the command line arguments (after the first 5 arguments)
    std::vector<double> coeffs;
    for (int i = 6; i < argc; ++i) {
        coeffs.push_back(std::stod(argv[i]));  // Convert each argument to double and store it in the vector
    }

    // Perform the integration using the parsed arguments
    double result = integrate(integrator_type, coeffs, a, b, num_points, case_type);

    // Output the integration result to the console
    std::cout << "The integral result is: " << result << std::endl;

    return 0;  // Return 0 to indicate successful completion
}
