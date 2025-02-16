#ifndef INTEGRATION_RULE_HPP
#define INTEGRATION_RULE_HPP

#include <iostream>
#include <vector>
#include "ScalarFunction.hpp"  // Include ScalarFunction for integration with functions

// Template class to represent an integration rule
// T1 represents the type of the weights, and T2 represents the type of the nodes.
template<typename T1, typename T2>
class IntegrationRule {
public:
    // Getter method to return the weights (wi_)
    const std::vector<T1>& getWeights() const { return wi_; }

    // Getter method to return the nodes (xi_)
    const std::vector<T2>& getNodes() const { return xi_; }

    // Helper method to set weights and nodes for the integration rule
    // Weights (wi_) and nodes (xi_) are passed as vectors
    void setWeightsAndNodes(const std::vector<T1>& weights, const std::vector<T2>& nodes) {
        wi_ = weights;  // Set the weights for the integration rule
        xi_ = nodes;    // Set the nodes for the integration rule
    }

protected:
    std::vector<T1> wi_; // Vector to store the weights for the integration rule
    std::vector<T2> xi_; // Vector to store the nodes (sampling locations) for the integration rule
};

#endif // INTEGRATION_RULE_HPP
