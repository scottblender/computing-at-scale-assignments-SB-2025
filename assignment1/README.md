# Code Information
### Base Classes:
1. IntegrationRule.hpp

This class contains three methods. Two getter methods, getWeights() and getNodes() return the weights and nodes of the respective integration rule. The setWeightsAndNodes method sets the weights and nodes for an integration rule based on inputs weights and nodes.
2. ScalarFunction.hpp

This class contains one operator method () to return the function value given an input location. It assumes that the input function is scalar, continuous on the domain [a,b], the function is one-to-one, and the user knows how the function works.

### Derived Classes:
1. GaussLegendre.hpp
2. GaussLobatto.hpp
3. GaussChebyshev.hpp

These classes are baed on the IntegrationRule.hpp class. They each take an integer input for the number of integration points. For Gauss-Legendre, it works for 1-4 integration points. For Gauss-Lobatto, it works for 3-5 integration points. For Gauss-Chebyshev, it works for any number of integration points since weights and nodes are calculated in the class itself. The Gauss-Chebyshev also requires an input for which case the integral falls into. 

4. Polynomial.hpp

This class is based on ScalarFunction.hpp. It initializes a polynomial based on provided coefficients and returns the evaluation of the polynomial at a specific point.

### cpp Files
1. PolynomialIntegrate.cpp

This code takes in an integer for the type of integration to be performed (1 for Gauss-Legendre, 2 for Gauss-Lobatto, and 3 for Gauss-Chebyshev), a vector of coefficients, doubles for the values to integrate to and from, an integer for the number of points, and an integer for the type of Gauss-Chebshev (1 or 2). To run this, input these values into the command line. The last argument is optional if not using Gauss-Chebyshev. 

2. Integrate.cpp

This code performs the integration for all methods of integration based on the Wikipedia page for Gauss Quadrature. It has the same inputs as PolynomialIntegrate.cpp. The header file, Integrate.hpp, allows it to be called in UnitTests.cpp and PolynomialIntegrate.cpp.

3. UnitTests.cpp

This code tests all types of integration for the functions x and x^2. It outputs how many tests passed/failed and which ones in the command line.

4. main.cpp

This code is to test a function indivually. It was used to debug.

# CMake Instructions
To run cmake, make a build directory using 'mkdir build'. Then, run 'cmake ..' to build relevant CMake files. It requires version 3.28.3. Finally, run 'make' to develop all the files and access the results of UnitTests.cpp by running './unit_tests'.
