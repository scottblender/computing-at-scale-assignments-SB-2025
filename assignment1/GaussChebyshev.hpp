#ifndef GAUSSCHEBYSHEV_HPP
#define GAUSSCHEBYSHEV_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <cmath>
#include "IntegrationRule.hpp"

class GaussChebyshev : public IntegrationRule<double, double> {
public:
    // Constructor accepts an integer for the number of points and a case type (1 or 2) to initialize weights and nodes
    GaussChebyshev(int num_points, int case_) 
        : IntegrationRule<double, double>() 
    {
        // Initialize vectors for weights and nodes based on the number of integration points
        std::vector<double> weights = std::vector<double>(num_points);
        std::vector<double> nodes = std::vector<double>(num_points);

        // Case 1: Chebyshev Type 1 weights and nodes
        if(case_ == 1) {
            for(auto j = 1; j <= num_points; ++j) {
                // Compute the weights and nodes for Chebyshev Type 1
                weights[j-1] = M_PI / num_points;
                nodes[j-1] = std::cos(M_PI * (2.0 * j - 1.0) / (2.0 * num_points));
            }
            // Reverse the vectors to match the correct order
            std::reverse(weights.begin(), weights.end());
            std::reverse(nodes.begin(), nodes.end());
            // Set the calculated weights and nodes using the base class method
            setWeightsAndNodes(weights, nodes);
        }
        // Case 2: Chebyshev Type 2 weights and nodes
        else if (case_ == 2) {
            for(auto k = 1; k <= num_points; ++k) {
                // Compute the weights and nodes for Chebyshev Type 2
                weights[k-1] = (M_PI / (num_points + 1.0)) * std::pow(std::sin(M_PI * k / (num_points + 1.0)), 2);
                nodes[k-1] = std::cos((k * M_PI) / (num_points + 1.0));
            }
            // Reverse the vectors to match the correct order
            std::reverse(weights.begin(), weights.end());
            std::reverse(nodes.begin(), nodes.end());
            // Set the calculated weights and nodes using the base class method
            setWeightsAndNodes(weights, nodes);
        }
        else {
            // Handle invalid case type
            std::cerr << "Invalid case type!" << std::endl;
        }
    }
};

#endif // GAUSSCHEBYSHEV_HPP
