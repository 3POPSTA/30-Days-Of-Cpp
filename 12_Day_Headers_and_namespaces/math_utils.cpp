#include "math_utils.hpp"
#include <stdexcept>

namespace MathUtils {
    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
    double multiply(double a, double b) { return a * b; }
    double divide(double a, double b) {
        if (b == 0.0) {
            throw std::invalid_argument("Division by zero in MathUtils::divide");
        }
        return a / b;
    }
}
