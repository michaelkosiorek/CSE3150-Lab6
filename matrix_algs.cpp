#include "matrix_algs.h"


vector<vector<double>> initialize_new_rep(const vector<vector<int>>& dm1, 
                                          const vector<vector<int>>& d0,
                                          const vector<vector<int>>& d1){
    int n = dm1[0].size();
    int exponent_total;
    vector<vector<double>> new_rep;

    for (int i=0; i < n; i++) {
        vector<double> empty_vec;
        new_rep.push_back(empty_vec);
        for (int j=0; j < n; j++) {
            new_rep[i].push_back(0);
            exponent_total=0;
            if (dm1[i][j] >= -1 && dm1[i][j] <= 1) exponent_total += dm1[i][j];
            if (d0[i][j] >= -1 && d0[i][j] <= 1) exponent_total += d0[i][j];
            if (d1[i][j] >= -1 && d1[i][j] <= 1) exponent_total += d1[i][j];
            if (exponent_total==-1) new_rep[i][j] = (double)1/(3*(n+1));
            else if (exponent_total==1) new_rep[i][j] = 3*(n+1);
            else new_rep[i][j] = 0;
        }
    }
    return new_rep;
}

vector<vector<double>> matrix_mult_self(const vector<vector<double>>& matrix){
    int n = matrix.size();
    vector<vector<double>> result(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix[i][k] * matrix[k][j];
            }  
        }
    }

    return result;

}