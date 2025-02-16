#include <iostream>
#include <vector>
#include <sstream>
#include "Integrate.hpp"

int main(int argc, char* argv[]) {
    // Parse the integrator type, case type, and number of points
    int integrator_type = std::stoi(argv[1]);
    int case_type = std::stoi(argv[2]);
    int num_points = std::stoi(argv[3]);
    double a = std::stod(argv[4]);
    double b = std::stod(argv[5]);

    // Read the polynomial coefficients from the command line arguments
    std::vector<double> coeffs;
    for (int i = 6; i < argc; ++i) {
        coeffs.push_back(std::stod(argv[i]));
    }

    // Perform the integration using the provided parameters
    double result = integrate(integrator_type, coeffs, a, b, num_points, case_type);

    // Output the result
    std::cout << "The integral result is: " << result << std::endl;

    return 0;
}
