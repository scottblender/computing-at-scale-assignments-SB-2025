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
        switch (points) {
            case 3:
                setWeightsAndNodes({1.0/3.0, 2.0/3.0, 1.0/3.0}, {-1.0, 0.0, 1.0});
                break;
            case 4:
                setWeightsAndNodes({1.0/6.0, 5.0/6.0, 5.0/6.0, 1.0/6.0}, {-1.0, -std::sqrt(1.0/5.0),std::sqrt(1.0/5.0), 1.0});
                break;
            case 5:
                setWeightsAndNodes({1.0/10.0, 49.0/90.0, 32.0/45.0, 49.0/90.0, 1.0/10.0}, {-1.0,-std::sqrt(3.0/7.0), 0.0, std::sqrt(3.0/7.0), 1.0});
                break;
            default:
                throw std::invalid_argument("Unsupported number of points for Gauss-Lobatto quadrature.");
        }
    }
};

#endif // GAUSSLOBATTO_HPP
