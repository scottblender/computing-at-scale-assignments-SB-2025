#include <iostream>
#include <vector>
#include "PolynomialIntegrate.cpp"

int main() {
    std::vector<double> coeffs = {1, 0, 0};  // Coefficients from highest degree to constant term

    // Integrate the polynomial 
    double result = polynomial_integrate(3, 2, coeffs, 0.0, 1.0, 10);

    std::cout << "Integral result: " << result << std::endl;

    return 0;

}
