#include <iostream>
#include "matrix_algs.h"
#include "ints_read_vector.h"
#include "ints_read_matrix.h"




int main() {

    std::ifstream d_min_1_stream;
    d_min_1_stream.open("graph_m1.txt");

    std::ifstream d_0_stream;
    d_0_stream.open("graph_0.txt");

    std::ifstream d_1_stream;
    d_1_stream.open("graph_1.txt");

    
    std::vector<std::vector<int>> d_min_1 = ints_read_matrix(d_min_1_stream);
    std::vector<std::vector<int>> d_0 = ints_read_matrix(d_0_stream);
    std::vector<std::vector<int>> d_1 = ints_read_matrix(d_1_stream);

    // compute_n_matrix(d_0);

    /*
    for (vector<int> i : d_min_1) std::cout << i << std::endl;
    for (vector<int> i : d_0) std::cout << i << std::endl;
    for (vector<int> i : d_1) std::cout << i << std::endl;
    cout << endl;
    */

    // NOTE: these matrices are NOT used for the algorithm;
    // they are used so we can save what paths we have
    // discovered throughout all iterations of
    // the new algorithm
    int n = d_min_1.size();
    vector<vector<int>> zero_costs, neg_one_costs, pos_one_costs;
    fill_with_infinity(zero_costs, n);
    fill_with_infinity(neg_one_costs, n);
    fill_with_infinity(pos_one_costs, n);
    print_discovered_paths(zero_costs, pos_one_costs, neg_one_costs);

    
    vector<vector<double>> new_rep = initialize_new_rep(d_min_1, d_0, d_1);
    for (auto i : new_rep) std::cout << i << std::endl;
    check_and_add_all_discovered_paths(new_rep, zero_costs, pos_one_costs, neg_one_costs);
    cout << "New:" << endl;
    print_discovered_paths(zero_costs, pos_one_costs, neg_one_costs);
    cout << endl;
    vector<vector<double>> matrix_multed = matrix_mult_self(new_rep);
    // for (auto i : matrix_multed) std::cout << i << std::endl;
    check_and_add_all_discovered_paths(matrix_multed, zero_costs, pos_one_costs, neg_one_costs);
    cout << "New:" << endl;
    print_discovered_paths(zero_costs, pos_one_costs, neg_one_costs);
    cout << endl;
    matrix_multed = matrix_mult_self(matrix_multed);
    // for (auto i : matrix_multed) std::cout << i << std::endl;
    check_and_add_all_discovered_paths(matrix_multed, zero_costs, pos_one_costs, neg_one_costs);
    cout << "New:" << endl;
    print_discovered_paths(zero_costs, pos_one_costs, neg_one_costs);
    


    return 0;
}
