#include "QuadraticEquationSolver.h"
#include <cmath>
#include <limits>
#include <stdexcept>

std::vector<double> QuadraticEquationSolver::solve(double a, double b, double c)
{
    if (std::isnan(a) || std::isnan(b) || std::isnan(c)) 
    {
        throw std::invalid_argument("Coefficients cannot be NaN.");
    }
    if (std::isinf(a) || std::isinf(b) || std::isinf(c)) 
    {
        throw std::invalid_argument("Coefficients cannot be infinity.");
    }
    if (std::abs(a) < std::numeric_limits<double>::epsilon())
    {
        throw std::invalid_argument("Coefficient 'a' cannot be zero.");
    }
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
    {
        return std::vector<double>();  // Return an empty vector when there are no real roots
    } 
    else if (std::abs(discriminant) < std::numeric_limits<double>::epsilon())
    {
        // One root with multiplicity 2
        return std::vector<double>{-b / (2 * a)};
    } 
    else 
    {
        // Two distinct roots
        double sqrtDiscriminant = std::sqrt(discriminant);
        return std::vector<double>{(-b + sqrtDiscriminant) / (2 * a), (-b - sqrtDiscriminant) / (2 * a)};
    }
}
