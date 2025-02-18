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
        for(auto j = 1; j <= num_points; ++j){
            if(case_ == 1) {
                // Compute the weights and nodes for Chebyshev Type 1
                weights[j-1] = M_PI / num_points;
                nodes[j-1] = std::cos(M_PI * (2.0 * j - 1.0) / (2.0 * num_points));
            }
            else if (case_ == 2){
                 // Compute the weights and nodes for Chebyshev Type 2
                 weights[j-1] = (M_PI / (num_points + 1.0)) * std::pow(std::sin(M_PI * j / (num_points + 1.0)), 2);
                 nodes[j-1] = std::cos((j * M_PI) / (num_points + 1.0));
            }
            else {
                std::cerr << "Invalid case type!" << std::endl;
            }
        }
         // Reverse the vectors to match the correct order
         std::reverse(weights.begin(), weights.end());
         std::reverse(nodes.begin(), nodes.end());
         // Set the calculated weights and nodes using the base class method
         setWeightsAndNodes(weights, nodes);
    }
};

#endif // GAUSSCHEBYSHEV_HPP