#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <vector>
#include <cmath>
#include "ScalarFunction.hpp"

// Template class to represent a polynomial, derived from ScalarFunction
template<typename T>
class Polynomial : public ScalarFunction<T> {
private:
    std::vector<T> coefficients; // List of polynomial coefficients (e.g., [a0, a1, a2, ..., an] for a_n * x^n + ... + a_1 * x + a_0)

public:
    // Constructor that takes the coefficients for the polynomial and stores them
    Polynomial(const std::vector<T>& coeffs) : coefficients(coeffs) {}

    // Overloading the operator() to evaluate the polynomial at a given point x
    T operator()(T x) const override {
        T result = 0;  // Variable to accumulate the result of the polynomial evaluation
        for (auto i = 0; i < coefficients.size(); ++i) {  // Iterate over the coefficients
            result += coefficients[i] * std::pow(x, i);  // Add the corresponding term of the polynomial
        }
        return result;  // Return the evaluated result
    }
};

#endif // POLYNOMIAL_HPP
