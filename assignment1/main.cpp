#include <iostream>
#include "GaussLegendre.hpp"  // Include the GaussLegendre header

int main() {
    // Create an instance of GaussLegendre with 2-point quadrature
    GaussLegendre gauss3(3);  // Passing 2 directly, no need for an enum

    // Print the numeric value associated with the "2" case
    std::cout << "Gauss-Legendre points: 3" << std::endl;

    // Access and print the weights and nodes for this case
    for (size_t i = 0; i < gauss3.getWeights().size(); ++i) {
        std::cout << "Weight " << i+1 << ": " << gauss3.getWeights()[i]
                  << ", Node " << i+1 << ": " << gauss3.getNodes()[i] << std::endl;
    }

    return 0;
}
