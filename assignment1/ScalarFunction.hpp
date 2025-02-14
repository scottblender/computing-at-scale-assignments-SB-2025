/*
Assumptions:
1. The function must be continuous on the interval [a,b]
2. The function is one-to-one
3. The integration method assumes the user knows how the function they input works
*/
#ifndef SCALAR_FUNCTION_HPP
#define SCALAR_FUNCTION_HPP

template<typename T>
class ScalarFunction {
public:
    virtual ~ScalarFunction() noexcept = default;

    // Pure virtual function to be implemented by derived classes
    virtual T operator()(T x) const = 0; 

};

#endif // SCALAR_FUNCTION_HPP
