#ifndef _NORMALIZATION_ALGS_H_
#define _NORMALIZATION_ALGS_H_

#include <cmath>

bool detect_negative_one_edge(double edge_cost, int n);
bool detect_positive_one_edge(double edge_cost, int n);
bool detect_zero_edge(double edge_cost, int n);
double get_fractional_part(double edge_cost);
int truncate(double edge_cost);

#endif