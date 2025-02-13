#ifndef INTEGRATION_RULE_HPP
#define INTEGRATION_RULE_HPP

#include <iostream>
#include <vector>
#include "ScalarFunction.hpp"

template<typename T1, typename T2>
class IntegrationRule {
public:
    // Getter methods to access the weights and nodes
    const std::vector<T1>& getWeights() const { return wi_; }
    const std::vector<T2>& getNodes() const { return xi_; }

    // Helper method to set weights and nodes
    void setWeightsAndNodes(const std::vector<T1>& weights, const std::vector<T2>& nodes) {
        wi_ = weights;
        xi_ = nodes;
    }

protected:
    std::vector<T1> wi_; // weights
    std::vector<T2> xi_; // sampling locations
};

#endif // INTEGRATION_RULE_HPP
