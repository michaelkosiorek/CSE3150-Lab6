#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "matrix_algs.h"
#include "normalization_algs.h"
#include "ints_read_matrix.h"
#include "ints_read_vector.h"



TEST_CASE("new matrix algs") {

    SUBCASE("matrix-mult") {
        vector<vector<double>> m1, expected;
        m1 = {{1, 2},
              {3, 4}};
        expected = {{7, 10},
                    {15, 22}};
        vector<vector<double>> actual = matrix_mult_self(m1);
        CHECK_EQ(actual, expected);
    };

    SUBCASE("fill with infinity function") {
        vector<vector<int>> empty_matrix, expected;
        int n = 10;
        expected = {{2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}};
        fill_with_infinity(empty_matrix, n);
        CHECK_EQ(empty_matrix, expected);
    };

    SUBCASE("initialization-alg") {
        std::ifstream d_min_1_stream;
        d_min_1_stream.open("graph_m1.txt");

        std::ifstream d_0_stream;
        d_0_stream.open("graph_0.txt");

        std::ifstream d_1_stream;
        d_1_stream.open("graph_1.txt");

        std::vector<std::vector<int>> d_min_1 = ints_read_matrix(d_min_1_stream);
        std::vector<std::vector<int>> d_0 = ints_read_matrix(d_0_stream);
        std::vector<std::vector<int>> d_1 = ints_read_matrix(d_1_stream);

        vector<vector<double>> new_rep = initialize_new_rep(d_min_1, d_0, d_1);
        vector<vector<double>> expected_new_rep = {{0.06667, 15, 0, 0}, 
                                                   {0, 0, 15, 0}, 
                                                   {0, 0, 0, 15}, 
                                                   {15, 0, 0, 0}};
        int n = new_rep.size();
        for (int i=0; i < n; i++) {
            for (int j=0; j < n; j++) {
                CHECK(new_rep[i][j] < expected_new_rep[i][j] + .001);
                CHECK(new_rep[i][j] > expected_new_rep[i][j] - .001);
            }
        }

    };

}