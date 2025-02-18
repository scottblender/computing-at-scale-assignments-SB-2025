#ifndef GAUSSLEGENDRE_HPP
#define GAUSSLEGENDRE_HPP

#include <vector>
#include <cmath>
#include "IntegrationRule.hpp"

class GaussLegendre : public IntegrationRule<double, double> {
public:
    // Constructor accepts an integer for the number of points and initializes weights and nodes
    GaussLegendre(int points) 
        : IntegrationRule<double, double>() // Initialize base class with empty vectors initially
    {
        // Switch statement to handle different number of points for Gauss-Legendre quadrature
        switch (points) {
            case 1:
                // For 1 point, set weight and node for central point
                setWeightsAndNodes({2.0}, {0.0});
                break;
            case 2:
                // For 2 points, set weights and nodes for roots of degree 2 polynomial
                setWeightsAndNodes({1.0, 1.0}, {-std::sqrt(1.0/3.0), std::sqrt(1.0/3.0)});
                break;
            case 3:
                // For 3 points, set weights and nodes for roots of degree 3 polynomial
                setWeightsAndNodes({5.0/9.0, 8.0/9.0, 5.0/9.0}, {-std::sqrt(3.0/5.0), 0.0, std::sqrt(3.0/5.0)});
                break;
            case 4:
                // For 4 points, set weights and nodes for roots of degree 4 polynomial
                setWeightsAndNodes(
                    {(18.0-std::sqrt(30.0))/36.0, (18.0+std::sqrt(30.0))/36.0, 
                     (18.0+std::sqrt(30.0))/36.0, (18.0-std::sqrt(30.0))/36.0},
                    {-std::sqrt((3.0/7.0)+(2.0/7.0)*std::sqrt(6.0/5.0)), 
                     -std::sqrt((3.0/7.0)-(2.0/7.0)*std::sqrt(6.0/5.0)), 
                     std::sqrt((3.0/7.0)-(2.0/7.0)*std::sqrt(6.0/5.0)), 
                     std::sqrt((3.0/7.0)+(2.0/7.0)*std::sqrt(6.0/5.0))}
                );
                break;
            default:
                // Throw an exception if an unsupported number of points is provided
                throw std::invalid_argument("Unsupported number of points for Gauss-Legendre quadrature.");
        }
    }
};

#endif // GAUSSLEGENDRE_HPP
