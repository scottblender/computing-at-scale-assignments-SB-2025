# Code Information

### Base Classes:

1. **IntegrationRule.hpp**  
   This class contains three methods:
   - `getWeights()`: Returns the weights of the respective integration rule.
   - `getNodes()`: Returns the nodes of the respective integration rule.
   - `setWeightsAndNodes()`: Sets the weights and nodes for an integration rule based on the provided inputs.

2. **ScalarFunction.hpp**  
   This class defines one operator method `()` that returns the function value given an input location. It assumes that the input function is scalar, continuous on the domain \([a, b]\), one-to-one, and that the user knows how the function works.

### Derived Classes:

1. **GaussLegendre.hpp**  
   Derived from `IntegrationRule.hpp`, this class supports Gauss-Legendre integration with 1-4 integration points.

2. **GaussLobatto.hpp**  
   Derived from `IntegrationRule.hpp`, this class supports Gauss-Lobatto integration with 3-5 integration points.

3. **GaussChebyshev.hpp**  
   Derived from `IntegrationRule.hpp`, this class supports Gauss-Chebyshev integration with any number of integration points. The weights and nodes are calculated within the class itself. Additionally, it requires an input for which case the integral falls into (1 or 2).  

4. **Polynomial.hpp**  
   Derived from `ScalarFunction.hpp`, this class initializes a polynomial based on provided coefficients and returns the evaluation of the polynomial at a specific point.

### cpp Files

1. **Integrate.cpp**  
   This file performs the integration using the specified method. It takes in the following arguments:
   - **integrator_type**: 1 for Gauss-Legendre, 2 for Gauss-Lobatto, 3 for Gauss-Chebyshev.
   - **coeffs**: A vector of coefficients for the polynomial. Coefficients are in order of constant, x, x^2, ... 
   - **a, b**: The limits of integration.
   - **num_points**: The number of integration points.
   - **case_**: (Optional, only for Gauss-Chebyshev) Case type (1 or 2).
   
   To run the program, input these values into the command line. If not using Gauss-Chebyshev, the **case_** argument is optional.

2. **PolynomialIntegrate.cpp**  
   This file performs numerical integration based on the specified integration method. It takes in the following arguments:
   - **integrator_type**: 
     - `1` for Gauss-Legendre
     - `2` for Gauss-Lobatto
     - `3` for Gauss-Chebyshev.
   - **case_type**: (Only relevant for Gauss-Chebyshev)
     - `1` or `2` for the two available cases of Gauss-Chebyshev integration.
   - **num_points**: The number of points to be used for the integration (e.g., 3, 4, etc.).
   - **a, b**: The lower and upper bounds of the integration.
   - **coeffs**: A vector of coefficients for the polynomial to be integrated. Coefficients are in order of constant, \(x\), \(x^2\), and so on.
   
   To run the program, input these values into the command line. If not using Gauss-Chebyshev, the **case_type** argument is optional.

### Example Usage:
```bash
./PolynomialIntegrate 1 1 5 0 1 1 2 3 4 5
```
This will compute the integral of the polynomial: \[ 1 + 2x + 3x^2 + 4x^3 + 5x^4 \]
over the range [0, 1] using Gauss-Legendre integration.

3. **UnitTests.cpp**  
   This file tests all types of integration (Gauss-Legendre, Gauss-Lobatto, and Gauss-Chebyshev) for the functions \(x\) and \(x^2\). It outputs how many tests passed/failed and which tests passed/failed on the command line. The tests are designed to ensure the correctness of the integration methods.

4. **main.cpp**  
   This file is used to test functions individually and was primarily used for debugging purposes.

# CMake Instructions

To run cmake, make a build directory using the following command:  
`mkdir build`

After, change into the build directory using the following command:
`cd build`

Then, run `cmake ..` to build the relevant CMake files. This requires CMake version 3.28.3. Finally, run `make` to develop all the files and access the results of `UnitTests.cpp` by running:  
`./unit_tests`
