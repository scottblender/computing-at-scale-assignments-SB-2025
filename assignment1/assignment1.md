### (a) How did you test your code? What are the limitations of your testing?

I created a file called `UnitTests.cpp` to test different cases for each type of integration method. The file outputs `1` if a test passed and `0` if a test failed. Since I only ran two tests, there can be many more types of polynomials tested. The two polynomials I tested were `x` and `x^2`, both of which can be evaluated by hand. The limitation of this testing is that I only tested with simple polynomials, so it may not be fully representative of all possible cases. Additional edge cases and more complex polynomials should be tested for thorough validation.

---

### (b) What approach did you take to document your functions and driver program?

I created a `README.md` file with explicit instructions on how to use the code. The README includes explanations of each integration method, how to run the code, and how to interpret the results. This provides clear guidance to users on setting up and testing the program.

---

### (c) How did you handle errors? How did you test your error handling strategy?

I handled errors using standard C++ exceptions, such as `std::invalid_argument` for invalid inputs. The error handling is tested by ensuring that the program throws exceptions in cases like invalid integration bounds or unsupported input for specific methods For this assignment, this includes using non-[-1, 1] bounds for Gauss-Chebyshev or using the incorrect number of points for Gauss-Legendre or Gauss-Lobatto.

---

### (d) Is your code robust to errors in the input files? How did you test this?

The code is designed to handle common errors like incorrect number of points, out-of-range integration bounds, and unsupported types of integration. I tested this by providing different erroneous inputs through the command line and ensuring that the program correctly reported the errors without crashing. 

---

### (e) Are there any limitations in your implementation you are aware of? Do you have any ideas on how to address them?

One limitation is that the Gauss-Chebyshev integration only works for a specific range of \([-1, 1]\), which restricts its use. To address this, I could consider implementing a domain transformation technique to handle arbitrary intervals for the Gauss-Chebyshev integration. Another limitation is that the code currently only supports 1D integration; extending it to 2D or 3D would require modifications to the polynomial evaluation and integration process. 

---

### (f) If you wanted to optimize the performance of your code, what approach would you take?

To optimize performance, I would focus on the following:
- Implementing memoization or caching techniques to store and reuse calculated values (e.g., nodes and weights) for different integration points.
- Parallelizing the integration process, especially for large polynomials or many integration points, using multithreading.
- Optimizing the polynomial evaluation to minimize redundant calculations.
- Considering more efficient numerical methods like adaptive quadrature when dealing with irregular or highly variable functions.

---

### (g) How would you extend your code to two or more dimensions?

To extend the code to two or more dimensions, I would use tensor product quadrature, which generalizes the 1D quadrature rules to higher dimensions. Specifically:
- For 2D, the weights and nodes would be combinations of 1D Gauss-Legendre or other quadrature points in both the \(x\) and \(y\) directions.
- For each dimension, I would apply the existing 1D integration methods and compute the multidimensional integral as the sum of the products of weights for each dimension.
- The integration method would also need to account for the function being evaluated in multiple dimensions.

This would take the form of a nested for-loop for each additional dimension, ensuring the appropriate weights are multiplied for the respective dimension.
---

### (h) Explain how you would handle a user-defined function that takes additional parameters.

For a user-defined function with additional parameters, I would pass the parameters as additional arguments to the function or store them in a class. The `ScalarFunction` class (or its derived classes like `Polynomial`) could be extended to accept and store these parameters. Then, when evaluating the function at a point, the stored parameters would be used as part of the evaluation.

For example:
```cpp
class UserFunction : public ScalarFunction {
    double param1, param2;
public:
    UserFunction(double p1, double p2) : param1(p1), param2(p2) {}
    double operator()(double x) override {
        return param1 * x + param2; // Example for a linear function
    }
};
