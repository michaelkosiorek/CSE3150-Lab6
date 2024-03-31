#ifndef _MATRIX_ALGS_H_
#define _MATRIX_ALGS_H_

#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> initialize_new_rep(const vector<vector<int>>& dm1, 
                                          const vector<vector<int>>& d0,
                                          const vector<vector<int>>& d1);

vector<vector<double>> matrix_mult_self(const vector<vector<double>>& mtrx);

#endif