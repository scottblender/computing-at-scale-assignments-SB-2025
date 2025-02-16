#include <iostream>
#include <vector>
#include "Polynomial.hpp"
#include "GaussLegendre.hpp"
#include "GaussLobatto.hpp"
#include "GaussChebyshev.hpp"
#include "Integrate.cpp" // Assuming the polynomial_integrate function is in this file

// Test for Gauss-Legendre integration
int test_gauss_legendre(std::vector<double> coeffs, double expected_result) {
    std::vector<double> coeffs_ = coeffs;  // Polynomial x^2
    double result = integrate(1, coeffs_, 0.0, 1.0, 3);  // Integrating x^2 from 0 to 1
    double expected_result_ = expected_result;  // Integral of x^2 from 0 to 1 is 1/3
    if (std::abs(result - expected_result_) < 1e-6) {
        std::cout << "Gauss-Legendre test passed!" << std::endl;
        return 0;
    } else {
        std::cout << "Gauss-Legendre test failed!" << std::endl;
        return 1;
    }
}

// Test for Gauss-Lobatto integration
int test_gauss_lobatto(std::vector<double> coeffs, double expected_result) {
    std::vector<double> coeffs_ = coeffs;  // Polynomial x^2
    double result = integrate(2, coeffs_, 0.0, 1.0, 3);  // Integrating x^2 from 0 to 1
    double expected_result_ = expected_result;  // Integral of x^2 from 0 to 1 is 1/3
    if (std::abs(result - expected_result_) < 1e-6) {
        std::cout << "Gauss-Lobatto test passed!" << std::endl;
        return 0;
    } else {
        std::cout << "Gauss-Lobatto test failed!" << std::endl;
        return 1;
    }
}

// Test for Gauss-Chebyshev integration (case 1)
int test_gauss_chebyshev_case1(std::vector<double> coeffs, double expected_result) {
    std::vector<double> coeffs_ = coeffs;  // Polynomial x^2
    double result = integrate(3, coeffs_, -1.0, 1.0, 3, 1);  // Integrating x^2/sqrt(1-x^2) from 0 to 1 using Gauss-Chebyshev case 1
    double expected_result_ = expected_result;  // Integral of x^2 from 0 to 1 is pi/4
    if (std::abs(result - expected_result_) < 1e-6) {
        std::cout << "Gauss-Chebyshev case 1 test passed!" << std::endl;
        return 0;
    } else {
        std::cout << "Gauss-Chebyshev case 1 test failed!" << std::endl;
        return 1;
    }
}

// Test for Gauss-Chebyshev integration (case 2)
int test_gauss_chebyshev_case2(std::vector<double> coeffs, double expected_result) {
    std::vector<double> coeffs_ = coeffs;  // Polynomial x^2
    double result = integrate(3, coeffs_, -1.0, 1.0, 3, 2);  // Integrating x^2*sqrt(1-x^2) from 0 to 1 using Gauss-Chebyshev case 1
    double expected_result_ = expected_result;  // Integral of x^2 from 0 to 1 is pi/16
    if (std::abs(result - expected_result_) < 1e-6) {
        std::cout << "Gauss-Chebyshev case 2 test passed!" << std::endl;
        return 0;
    } else {
        std::cout << "Gauss-Chebyshev case 2 test failed!" << std::endl;
        return 1;
    }
}

// Main function to run all tests
int main() {
    int total_tests = 0;
    // x^2
    total_tests += test_gauss_legendre({0, 0, 1},1.0/3.0);
    total_tests += test_gauss_lobatto({0, 0, 1},1.0/3.0);
    total_tests += test_gauss_chebyshev_case1({0, 0, 1},M_PI/2.0);
    total_tests += test_gauss_chebyshev_case2({0, 0, 1},M_PI/8.0);
    
    // x
    total_tests += test_gauss_legendre({0, 1, 0},1.0/2.0);
    total_tests += test_gauss_lobatto({0, 1, 0},1.0/2.0);
    total_tests += test_gauss_chebyshev_case1({0, 1, 0},0);
    total_tests += test_gauss_chebyshev_case2({0, 1, 0},0);
    std::cout << "Total tests failed: " << total_tests << std::endl;
    return total_tests;  // Return total failed tests
}
