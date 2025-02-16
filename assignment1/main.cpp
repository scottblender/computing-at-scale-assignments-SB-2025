#include <iostream>
#include <vector>
#include "GaussChebyshev.hpp"
#include "Integrate.hpp"

int main() {
    std::vector<double> coeffs = {0, 1, 0};  // Corresponds to x
    // Integrate the polynomial 
    double result = integrate(3, coeffs, -1.0, 1.0, 4, 2);

    std::cout << "Integral result: " << result << std::endl;

    // Create a Polynomial object
    Polynomial<double> poly(coeffs);

    // Test the polynomial at x = 0
    double x = 0;
    double result_at_0 = poly(x);
    std::cout << "Polynomial value at x = " << x << " is: " << result_at_0 << std::endl;

    // Test the polynomial at x = 1
    x = 1;
    double result_at_1 = poly(x);
    std::cout << "Polynomial value at x = " << x << " is: " << result_at_1 << std::endl;

    int num_p = 4;
    GaussChebyshev gcheb(num_p,2);

    for(auto i=0; i < num_p; ++i){
        std::cout<<"Weight: " << gcheb.getWeights()[i] << std::endl;
        std::cout<<"Node: " <<gcheb.getNodes()[i] << std::endl;
        x = gcheb.getNodes()[i];
        double result_at_xi = poly(x);
        std::cout << "Polynomial value at x = " << x << " is: " << result_at_xi << std::endl;
    }
    return 0;

}
