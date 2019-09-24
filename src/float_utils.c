#include "float_utils.h"

bool float_equals_epsilon(float a, float b, float epsilon) {
    float diff = fabsf(a - b);
    a = fabsf(a);
    b = fabsf(b);

    float largest = (b > a) ? b : a;

    return (diff <= largest * epsilon);
}

bool float_equals(float a, float b) {
    return float_equals_epsilon(a, b, FLT_EPSILON);
}

float fsign(float x) {
    return (float)((x > 0.0f) - (x < 0.0f));
}

bool double_equals_epsilon(double a, double b, double epsilon) {
    double diff = fabs(a - b);
    a = fabs(a);
    b = fabs(b);

    double largest = (b > a) ? b : a;

    return (diff <= largest * epsilon);
}

bool double_equals(double a, double b) {
    return double_equals_epsilon(a, b, DBL_EPSILON);
}


double sign(double x) {
    return (double)((x > 0.0) - (x < 0.0));
}
