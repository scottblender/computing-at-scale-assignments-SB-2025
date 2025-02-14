#include <iostream>
#include <vector>
#include "Polynomial.hpp"
#include "GaussLegendre.hpp"
#include "GaussLobatto.hpp"
#include "GaussChebyshev.hpp"
#include "PolynomialIntegrate.cpp" // Assuming the polynomial_integrate function is in this file

// Test for Gauss-Legendre integration
int test_gauss_legendre() {
    std::vector<double> coeffs = {1, 0, 0};  // Polynomial x^2
    double result = polynomial_integrate(1, 0, coeffs, 0.0, 1.0, 3);  // Integrating x^2 from 0 to 1
    double expected_result = 1.0 / 3.0;  // Integral of x^2 from 0 to 1 is 1/3
    if (std::abs(result - expected_result) < 1e-6) {
        std::cout << "Gauss-Legendre test passed!" << std::endl;
        return 0;
    } else {
        std::cout << "Gauss-Legendre test failed!" << std::endl;
        return 1;
    }
}

// Test for Gauss-Lobatto integration
int test_gauss_lobatto() {
    std::vector<double> coeffs = {1, 0, 0};  // Polynomial x^2
    double result = polynomial_integrate(2, 0, coeffs, 0.0, 1.0, 3);  // Integrating x^2 from 0 to 1
    double expected_result = 1.0 / 3.0;  // Integral of x^2 from 0 to 1 is 1/3
    if (std::abs(result - expected_result) < 1e-6) {
        std::cout << "Gauss-Lobatto test passed!" << std::endl;
        return 0;
    } else {
        std::cout << "Gauss-Lobatto test failed!" << std::endl;
        return 1;
    }
}

// Test for Gauss-Chebyshev integration (case 1)
int test_gauss_chebyshev_case1() {
    std::vector<double> coeffs = {1, 0, 0};  // Polynomial x^2
    double result = polynomial_integrate(3, 1, coeffs, 0.0, 1.0, 3);  // Integrating x^2/sqrt(1-x^2) from 0 to 1 using Gauss-Chebyshev case 1
    double expected_result = M_PI / 4.0;  // Integral of x^2 from 0 to 1 is pi/4
    if (std::abs(result - expected_result) < 1e-6) {
        std::cout << "Gauss-Chebyshev case 1 test passed!" << std::endl;
        return 0;
    } else {
        std::cout << "Gauss-Chebyshev case 1 test failed!" << std::endl;
        return 1;
    }
}

// Test for Gauss-Chebyshev integration (case 2)
int test_gauss_chebyshev_case2() {
    std::vector<double> coeffs = {1, 0, 0};  // Polynomial x^2
    double result = polynomial_integrate(3, 2, coeffs, 0.0, 1.0, 3);  // Integrating x^2*sqrt(1-x^2) from 0 to 1 using Gauss-Chebyshev case 1
    double expected_result = M_PI / 16.0;  // Integral of x^2 from 0 to 1 is pi/8
    if (std::abs(result - expected_result) < 1e-6) {
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
    total_tests += test_gauss_legendre();
    total_tests += test_gauss_lobatto();
    total_tests += test_gauss_chebyshev_case1();
    total_tests += test_gauss_chebyshev_case2();
    
    std::cout << "Total tests failed: " << total_tests << std::endl;
    return total_tests;  // Return total failed tests
}
