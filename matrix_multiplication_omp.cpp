#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

#define N 1000 // Tamaño de las matrices
#define NUM_THREADS 4 // Número de hilos paralelos

void multiply_matrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    #pragma omp parallel for num_threads(NUM_THREADS)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    vector<vector<int>> A(N, vector<int>(N, 1));
    vector<vector<int>> B(N, vector<int>(N, 2));
    vector<vector<int>> C(N, vector<int>(N, 0));

    multiply_matrices(A, B, C);

    return 0;
}
