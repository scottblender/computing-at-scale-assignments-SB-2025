#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <vector>
#include <cmath>
#include "ScalarFunction.hpp"

template<typename T>
class Polynomial : public ScalarFunction<T> {
private:
    std::vector<T> coefficients; // List of polynomial coefficients

public:
    // Constructor that takes the coefficients
    Polynomial(const std::vector<T>& coeffs) : coefficients(coeffs) {}

    // Implementing the operator() to evaluate the polynomial at x
    T operator()(T x) const override {
        T result = 0;
        for (auto i = 0; i < coefficients.size(); ++i) {
            double I = static_cast<double>(i);
            result += coefficients[i] * std::pow(x, I);
        }
        return result;
    }
};

#endif // POLYNOMIAL_HPP