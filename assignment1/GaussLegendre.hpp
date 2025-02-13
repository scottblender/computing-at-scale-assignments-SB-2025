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
        switch (points) {
            case 1:
                setWeightsAndNodes({2.0}, {0.0});
                break;
            case 2:
                setWeightsAndNodes({1.0, 1.0}, {-std::sqrt(1.0/3.0), std::sqrt(1.0/3.0)});
                break;
            case 3:
                setWeightsAndNodes({5.0/9.0, 8.0/9.0, 5.0/9.0}, {-std::sqrt(3.0/5.0), 0.0, std::sqrt(3.0/5.0)});
                break;
            case 4:
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
                throw std::invalid_argument("Unsupported number of points for Gauss-Legendre quadrature.");
        }
    }
};

#endif // GAUSSLEGENDRE_HPP
