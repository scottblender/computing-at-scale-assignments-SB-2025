/*
Assumptions:
1. The function must be continuous on the interval [a,b]
2. The function is one-to-one
3. The integration method assumes the user knows how the function they input works
*/

#ifndef SCALAR_FUNCTION_HPP
#define SCALAR_FUNCTION_HPP

// Template class representing a scalar function
template<typename T>
class ScalarFunction {
public:
    // Virtual destructor to ensure proper cleanup for derived classes
    virtual ~ScalarFunction() noexcept = default;

    // Pure virtual function that must be implemented by derived classes
    // It will evaluate the function at a given value 'x'
    virtual T operator()(T x) const = 0; 

};

#endif // SCALAR_FUNCTION_HPP
