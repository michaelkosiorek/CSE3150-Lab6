#ifndef _MATRIX_ALGS_H_
#define _MATRIX_ALGS_H_

#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> initialize_new_rep(const vector<vector<int>>& dm1, 
                                          const vector<vector<int>>& d0,
                                          const vector<vector<int>>& d1);

vector<vector<double>> matrix_mult_self(const vector<vector<double>>& mtrx);
void check_and_add_zero_cost_paths(const vector<vector<double>>& matrix, vector<vector<int>>& zero_costs);
void check_and_add_pos_one_cost_paths(const vector<vector<double>>& matrix, vector<vector<int>>& pos_one_costs);
void check_and_add_neg_one_cost_paths(const vector<vector<double>>& matrix, vector<vector<int>>& neg_one_costs);
void check_and_add_all_discovered_paths(const vector<vector<double>>& matrix,
                                        vector<vector<int>>& zero_costs,
                                        vector<vector<int>>& pos_one_costs,
                                        vector<vector<int>>& neg_one_costs);
void fill_with_infinity(vector<vector<int>> matrix);

#endif