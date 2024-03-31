#include "normalization_algs.h"
#include <iostream>


bool detect_negative_one_edge(double edge_cost, int n) {
    double check = static_cast<double>(3 * (n + 1) * get_fractional_part(edge_cost));
    if (2*n >= check && check >= 1) return true;
    else return false;
}

bool detect_positive_one_edge(double edge_cost, int n) {
    int check = truncate(static_cast<double>(edge_cost/(3*(n+1))));
    // std::cout << "Should be 1.0: " << static_cast<double>(edge_cost/(3*(n+1))) << std::endl;
    // std::cout << "Check: " << check << std::endl;
    if (2*n >= check && check >= 1) return true;
    else return false;
}

bool detect_zero_edge(double edge_cost, int n) {
    int check = truncate(edge_cost) % (3*(n+1));
    if (3*n >= check && check > 0) return true;
    else return false;
}

double get_fractional_part(double edge_cost) {
    return static_cast<double>(edge_cost-truncate(edge_cost));
}

int truncate(double edge_cost) {
    return static_cast<int>(floor(edge_cost));
}