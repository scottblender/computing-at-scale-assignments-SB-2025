#ifndef GAUSSLOBATTO_HPP
#define GAUSSLOBATTO_HPP

#include <vector>
#include <cmath>
#include "IntegrationRule.hpp"

class GaussLobatto : public IntegrationRule<double, double> {
public:
    // Constructor accepts an integer for the number of points and initializes weights and nodes
    GaussLobatto(int points) 
        : IntegrationRule<double, double>() // Initialize base class with empty vectors initially
    {
        // Switch statement to handle different number of points for Gauss-Lobatto quadrature
        switch (points) {
            case 3:
                // For 3 points, set weights and nodes for the roots of degree 3 polynomial
                setWeightsAndNodes({1.0/3.0, 4.0/3.0, 1.0/3.0}, {-1.0, 0.0, 1.0});
                break;
            case 4:
                // For 4 points, set weights and nodes for the roots of degree 4 polynomial
                setWeightsAndNodes({1.0/6.0, 5.0/6.0, 5.0/6.0, 1.0/6.0}, {-1.0, -std::sqrt(1.0/5.0), std::sqrt(1.0/5.0), 1.0});
                break;
            case 5:
                // For 5 points, set weights and nodes for the roots of degree 5 polynomial
                setWeightsAndNodes({1.0/10.0, 49.0/90.0, 32.0/45.0, 49.0/90.0, 1.0/10.0}, 
                                    {-1.0, -std::sqrt(3.0/7.0), 0.0, std::sqrt(3.0/7.0), 1.0});
                break;
            default:
                // Throw an exception if an unsupported number of points is provided
                throw std::invalid_argument("Unsupported number of points for Gauss-Lobatto quadrature.");
        }
    }
};

#endif // GAUSSLOBATTO_HPP
