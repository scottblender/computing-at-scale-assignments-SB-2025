#include <iostream>
#include <vector>
#include "Polynomial.hpp"
#include "GaussLegendre.hpp"
#include "GaussLobatto.hpp"
#include "GaussChebyshev.hpp"

double polynomial_integrate(int integrator_type, int case_, std::vector<double> coeffs, double a, double b, int num_points) {
    if(integrator_type == 1)
    {
        GaussLegendre gleg(num_points);
        Polynomial<double> poly(coeffs);
        double result = 0.0;
        std::vector<double> weights = gleg.getWeights();
        std::vector<double> nodes = gleg.getNodes();
        double coeff1 = (b-a)/2.0;
        double coeff2 = (a+b)/2.0;
        for(auto i=0; i < num_points; ++i){
            double xi = coeff1*nodes[i]+coeff2;
            result += weights[i]*poly(xi);
        }
        return coeff1*result;
    }
    else if (integrator_type == 2)
    {
        GaussLobatto glob(num_points);
        Polynomial<double> poly(coeffs);
        double result = 0.0;
        std::vector<double> weights = glob.getWeights();
        std::vector<double> nodes = glob.getNodes();
        double coeff1 = (b-a)/2.0;
        double coeff2 = (a+b)/2.0;
        for(auto i=0; i < num_points; ++i){
            double xi = coeff1*nodes[i]+coeff2;
            result += weights[i]*poly(xi);
        }
        return coeff1*result;
    }
    else if (integrator_type == 3) {
        if (case_ == 1){
            GaussChebyshev gcheb(num_points,case_);
            Polynomial<double> poly(coeffs);
            double result = 0.0;
            std::vector<double> weights = gcheb.getWeights();
            std::vector<double> nodes = gcheb.getNodes();
            double coeff1 = (b-a)/2.0;
            double coeff2 = (a+b)/2.0;
            for(auto i=0; i < num_points; ++i){
                double xi = coeff1*nodes[i] + coeff2;
                result += weights[i]*poly(xi);
            }
            return coeff1*result;
            }
        else if (case_ == 2) {
            GaussChebyshev gcheb(num_points,case_);
            Polynomial<double> poly(coeffs);
            double result = 0.0;
            std::vector<double> weights = gcheb.getWeights();
            std::vector<double> nodes = gcheb.getNodes();
            for(auto i=0; i < num_points; ++i){
                result += weights[i]*poly(nodes[i]);
            }
            return result;
            }
        else {
            std::cerr << "Invalid case type!" << std::endl;
            return 0.0; 
        }
    }
    else {
        std::cerr << "Invalid integrator type!" << std::endl;
        return 0.0; // Return 0.0 or another default/error value for invalid input
    }
}

