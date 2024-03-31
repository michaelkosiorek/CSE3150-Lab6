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

    SUBCASE("initialization alg") {
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
        // check to see if all elements are within .001 of our expected result
        // that was provided in the pdf
        for (int i=0; i < n; i++) {
            for (int j=0; j < n; j++) {
                CHECK(new_rep[i][j] < expected_new_rep[i][j] + .001);
                CHECK(new_rep[i][j] > expected_new_rep[i][j] - .001);
            }
        }

    };

    SUBCASE("normalization algs") {
        CHECK(detect_positive_one_edge(15.0, 4)); // an edge cost of 15 with n=4 should be TRUE
        CHECK(detect_zero_edge(1, 4)); // 1 should indicate a zero edge
        CHECK(detect_negative_one_edge(.066667, 4)); // 1/15 should indicate a -1 edge

        CHECK_FALSE(detect_positive_one_edge(.066667, 4)); // should indicate a - edge, not +
        CHECK_FALSE(detect_zero_edge(0, 4)); // 0 shouldnt trigger, not close enough
        CHECK_FALSE(detect_negative_one_edge(15.0, 4)); // should indicate +, not - 
        CHECK_FALSE(detect_positive_one_edge(0.0, 4)); // 0 is close to these small fractions but shouldnt trigger
    };

    SUBCASE("check for zero-solutions") {
        vector<vector<double>> new_rep = {{0.06667, 15, 0, 0}, 
                                          {0, 0, 15, 0}, 
                                          {0, 0, 0, 15}, 
                                          {15, 0, 0, 0}};
        new_rep = matrix_mult_self(new_rep);
        // this new AxA matrix should indicate that there
        // is a zero-cost path from 4->1 and from 1->2
        vector<vector<int>> expected_zero_paths = {{2, 0, 2, 2},
                                                   {2, 2, 2, 2},
                                                   {2, 2, 2, 2},
                                                   {0, 2, 2, 2}};
        vector<vector<int>> actual_zero_paths = {{2, 2, 2, 2},
                                                 {2, 2, 2, 2},
                                                 {2, 2, 2, 2},
                                                 {2, 2, 2, 2}};;
        check_and_add_zero_cost_paths(new_rep, actual_zero_paths);
        CHECK_EQ(actual_zero_paths, expected_zero_paths);
    };

    SUBCASE("check for pos-one-solutions") {
        vector<vector<double>> new_rep = {{0.06667, 15, 0, 0}, 
                                          {0, 0, 15, 0}, 
                                          {0, 0, 0, 15}, 
                                          {15, 0, 0, 0}};
        // the new representation should be able to immediately
        // detect the 4 pos-one cost paths
        vector<vector<int>> expected_pos_one_paths = {{2, 1, 2, 2},
                                                      {2, 2, 1, 2},
                                                      {2, 2, 2, 1},
                                                      {1, 2, 2, 2}};
        vector<vector<int>> actual_pos_one_paths = {{2, 2, 2, 2},
                                                    {2, 2, 2, 2},
                                                    {2, 2, 2, 2},
                                                    {2, 2, 2, 2}};
        check_and_add_pos_one_cost_paths(new_rep, actual_pos_one_paths);
        CHECK_EQ(actual_pos_one_paths, expected_pos_one_paths);

        //print_discovered_paths(actual_pos_one_paths, actual_pos_one_paths, actual_pos_one_paths);
    }

    SUBCASE("check for neg-one-solutions") {
        vector<vector<double>> new_rep = {{0.06667, 15, 0, 0}, 
                                          {0, 0, 15, 0}, 
                                          {0, 0, 0, 15}, 
                                          {15, 0, 0, 0}};
        // the new representation should be able to immediately
        // detect the 4 neg-one cost paths
        vector<vector<int>> expected_neg_one_paths = {{-1, 2, 2, 2},
                                                      {2, 2, 2, 2},
                                                      {2, 2, 2, 2},
                                                      {2, 2, 2, 2}};
        vector<vector<int>> actual_neg_one_paths = {{2, 2, 2, 2},
                                                    {2, 2, 2, 2},
                                                    {2, 2, 2, 2},
                                                    {2, 2, 2, 2}};
        check_and_add_neg_one_cost_paths(new_rep, actual_neg_one_paths);
        CHECK_EQ(actual_neg_one_paths, expected_neg_one_paths);
    };

}