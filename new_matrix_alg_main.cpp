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

    for (vector<int> i : d_min_1) std::cout << i << std::endl;
    for (vector<int> i : d_0) std::cout << i << std::endl;
    for (vector<int> i : d_1) std::cout << i << std::endl;
    cout << endl;

    vector<vector<double>> new_rep = initialize_new_rep(d_min_1, d_0, d_1);
    for (auto i : new_rep) std::cout << i << std::endl;
    cout << endl;
    vector<vector<double>> matrix_multed = matrix_mult_self(new_rep);
    for (auto i : matrix_multed) std::cout << i << std::endl;


    return 0;
}