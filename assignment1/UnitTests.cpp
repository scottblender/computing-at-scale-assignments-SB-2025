#include <iostream>
#include <vector>
#include "Polynomial.hpp"
#include "GaussLegendre.hpp"
#include "GaussLobatto.hpp"
#include "GaussChebyshev.hpp"
#include "Integrate.cpp" // Assuming the polynomial_integrate function is in this file

// Test for Gauss-Legendre integration
int test_gauss_legendre(std::vector<double> coeffs, double expected_result, double a, double b, int num_points) {
    std::vector<double> coeffs_ = coeffs;  // Polynomial
    // Integrating polynomial from a to b using Gauss-Legendre method with num_points
    double result = integrate(1, coeffs_, a, b, num_points);  
    double expected_result_ = expected_result;
    
    // Check if the result is close to the expected result
    if (std::abs(result - expected_result_) < 1e-6) {
        std::cout << "Gauss-Legendre test passed!" << std::endl;
        return 0;  // Return 0 if test passes
    } else {
        std::cout << "Gauss-Legendre test failed!" << std::endl;
        return 1;  // Return 1 if test fails
    }
}

// Test for Gauss-Lobatto integration
int test_gauss_lobatto(std::vector<double> coeffs, double expected_result, double a, double b, int num_points) {
    std::vector<double> coeffs_ = coeffs;  // Polynomial
    // Integrating polynomial from a to b using Gauss-Lobatto method with num_points
    double result = integrate(2, coeffs_, a, b, num_points);  
    double expected_result_ = expected_result;
    
    // Check if the result is close to the expected result
    if (std::abs(result - expected_result_) < 1e-6) {
        std::cout << "Gauss-Lobatto test passed!" << std::endl;
        return 0;
    } else {
        std::cout << "Gauss-Lobatto test failed!" << std::endl;
        return 1;
    }
}

// Test for Gauss-Chebyshev integration (case 1)
int test_gauss_chebyshev_case1(std::vector<double> coeffs, double expected_result, int num_points) {
    std::vector<double> coeffs_ = coeffs;
    // Integrating polynomial using Gauss-Chebyshev case 1
    double result = integrate(3, coeffs_, -1.0, 1.0, num_points, 1);  
    double expected_result_ = expected_result;
    
    // Check if the result is close to the expected result
    if (std::abs(result - expected_result_) < 1e-6) {
        std::cout << "Gauss-Chebyshev case 1 test passed!" << std::endl;
        return 0;
    } else {
        std::cout << "Gauss-Chebyshev case 1 test failed!" << std::endl;
        return 1;
    }
}

// Test for Gauss-Chebyshev integration (case 2)
int test_gauss_chebyshev_case2(std::vector<double> coeffs, double expected_result, int num_points) {
    std::vector<double> coeffs_ = coeffs;
    // Integrating polynomial using Gauss-Chebyshev case 2
    double result = integrate(3, coeffs_, -1.0, 1.0, num_points, 2);  
    double expected_result_ = expected_result;
    
    // Check if the result is close to the expected result
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
    int total_tests = 0;  // Variable to keep track of the total failed tests
    
    // Linear polynomial tests (e.g., x)
    total_tests += test_gauss_legendre({0, 1, 0}, 1.0/2.0, 0.0, 1.0, 3);
    total_tests += test_gauss_lobatto({0, 1, 0}, 1.0/2.0, 0.0, 1.0, 3);
    total_tests += test_gauss_chebyshev_case1({0, 1, 0}, 0, 3);
    total_tests += test_gauss_chebyshev_case2({0, 1, 0}, 0, 3);

    // Quadratic polynomial tests (e.g., x^2)
    total_tests += test_gauss_legendre({0, 0, 1}, 1.0/3.0, 0.0, 1.0, 3);
    total_tests += test_gauss_lobatto({0, 0, 1}, 1.0/3.0, 0.0, 1.0, 3);
    total_tests += test_gauss_chebyshev_case1({0, 0, 1}, M_PI/2.0, 3);
    total_tests += test_gauss_chebyshev_case2({0, 0, 1}, M_PI/8.0, 3);

    // Cubic polynomial tests (e.g., x^3)
    total_tests += test_gauss_legendre({0, 0, 0, 1}, 0.25, 0.0, 1.0, 3); // Expected result for x^3 from 0 to 1 is 0.25
    total_tests += test_gauss_lobatto({0, 0, 0, 1}, 0.25, 0.0, 1.0, 3); // Expected result for x^3 from 0 to 1 is 0.25
    
    // Quartic polynomial tests (e.g., x^4)
    total_tests += test_gauss_legendre({0, 0, 0, 0, 1}, 0.2, 0.0, 1.0, 3); // Expected result for x^4 from 0 to 1 is 0.2
    total_tests += test_gauss_lobatto({0, 0, 0, 0, 1}, 0.2, 0.0, 1.0, 4); // Expected result for x^4 from 0 to 1 is 0.2
    
    // Quintic polynomial tests (e.g., x^5)
    total_tests += test_gauss_legendre({0, 0, 0, 0, 0, 1}, 1.0/6.0, 0.0, 1.0, 3); // Expected result for x^5 from 0 to 1 is 1/6
    total_tests += test_gauss_lobatto({0, 0, 0, 0, 0, 1}, 1.0/6.0, 0.0, 1.0, 4); // Expected result for x^5 from 0 to 1 is 1/6
    
    // 6th Order Polynomial Tests (x^6)
    total_tests += test_gauss_legendre({0, 0, 0, 0, 0, 0, 1}, 1.0/7.0, 0.0, 1.0, 4); // Expected result for x^6 from 0 to 1 is 1/7
    total_tests += test_gauss_lobatto({0, 0, 0, 0, 0, 0, 1}, 1.0/7.0, 0.0, 1.0, 5); // Expected result for x^6 from 0 to 1 is 1/7
    
    // 7th Order Polynomial Tests (x^7)
    total_tests += test_gauss_legendre({0, 0, 0, 0, 0, 0, 0, 1}, 1.0/8.0, 0.0, 1.0, 4); // Expected result for x^7 from 0 to 1 is 1/8
    total_tests += test_gauss_lobatto({0, 0, 0, 0, 0, 0, 0, 1}, 1.0/8.0, 0.0, 1.0, 5); // Expected result for x^7 from 0 to 1 is 1/8

    // Polynomial x^7 + 7x^6 + 6x^5 + 5x^4 + 4x^3 + 3x^2 + 2x + 1
    total_tests += test_gauss_legendre({1, 2, 3, 4, 5, 6, 7, 1}, 7.125, 0.0, 1.0, 4);  // Expected result: 7.125
    total_tests += test_gauss_lobatto({1, 2, 3, 4, 5, 6, 7, 1}, 7.125, 0.0, 1.0, 5);  // Expected result: 7.125
    
    // Output the total number of tests that failed
    std::cout << "Total tests failed: " << total_tests << std::endl;
    
    return total_tests;  // Return total number of failed tests as the result
}
