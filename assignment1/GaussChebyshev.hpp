#ifndef GAUSSCHEBYSHEV_HPP
#define GAUSSCHEBYSHEV_HPP

#include <vector>
#include <cmath>
#include "IntegrationRule.hpp"

class GaussChebyshev : public IntegrationRule<double, double> {
public:
    // Constructor accepts an integer for the number of points and initializes weights and nodes
    GaussChebyshev(int points, int case_) 
        : IntegrationRule<double, double>() // Initialize base class with empty vectors initially
    {
        double num_points = static_cast<double>(points);
        std::vector<double> weights = std::vector<double>(points);
        std::vector<double> nodes = std::vector<double>(points);
       if(case_ == 1)
       {
        for(auto j=1; j<points+1;++j){
            double J = static_cast<double>(j);
            weights[j-1] = M_PI/num_points;
            nodes[j-1] = std::cos(M_PI*(2.0*J-1.0)/(2.0*num_points));
        };
        setWeightsAndNodes(weights, nodes);
       }
       else if (case_ == 2)
       {
        for(auto k=1; k<points+1;++k){
            double K = static_cast<double>(k);
            weights[k-1] = (M_PI/(K+1.0))*std::pow(M_PI*K/(num_points+1.0),2);
            nodes[k-1] = std::cos((K*M_PI)/(num_points+1.0));
        };
        setWeightsAndNodes(weights, nodes);
       }
       
    }
};

#endif // GAUSSCHEBYSHEV_HPP
