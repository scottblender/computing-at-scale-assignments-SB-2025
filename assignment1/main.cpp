#include <iostream>
#include "GaussLegendre.hpp"  // Include the GaussLegendre header
#include "GaussChebyshev.hpp"

int main() {
    // Create an instance of GaussLegendre with 3-point quadrature
    GaussLegendre gauss3(3);  // 

    // Print the numeric value associated with the "2" case
    std::cout << "Gauss-Legendre points: 3" << std::endl;

    // Access and print the weights and nodes for this case
    for (size_t i = 0; i < gauss3.getWeights().size(); ++i) {
        std::cout << "Weight " << i+1 << ": " << gauss3.getWeights()[i]
                  << ", Node " << i+1 << ": " << gauss3.getNodes()[i] << std::endl;
    };

    // Number of points (e.g., 10 points) and the case type (0 or 1)
    int points = 5;
    int case_ = 2;  

    // Create an instance of GaussChebyshev with the specified points and case
    GaussChebyshev gaussChebyshev(points, case_);

    std::cout << "Weights and Locations for " << points << " points, Case " << case_ << ":\n";

    const std::vector<double>& weights = gaussChebyshev.getWeights();  
    const std::vector<double>& locations = gaussChebyshev.getNodes();  

    for (int i = 0; i < points; ++i) {
        std::cout << "Point " << i+1 << ": Weight = " << weights[i] << ", Location = " << locations[i] << std::endl;
    }

    return 0;

}
