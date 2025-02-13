/**
 * @brief Writes a dense matrix to the Matrix Market format.
 *
 * This function takes a dense matrix (2D vector of doubles) and writes its data 
 * to standard output in the Matrix Market format. Only non-zero values are included 
 * in the output, making it suitable for sparse representation.
 *
 * @param res A dense matrix (2D vector of doubles) to be written.
 *
 * @note The function uses the Matrix Market coordinate format for sparse matrices.
 *       It will output the matrix dimensions, number of non-zero entries, and 
 *       each non-zero value along with its row and column indices.
 *       Indices are adjusted to be 1-based as required by the Matrix Market format.
 *
 * @warning If the input matrix is empty or uninitialized, the function will print
 *          an error message to `stderr` and return without performing any output.
 */

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "mmio.h"
using namespace std;

typedef vector<vector<double>> Matrix;

void write_matrix_market(const Matrix& res){
	//Check if matrix is empty or not initialized
	if (res.empty() || res[0].empty()) {
        	cerr << "Matrix is empty or uninitialized!" << endl;
        	return;
    	}
	MM_typecode matcode;
	int rows = res.size();
	int columns =  res[0].size();
	int nz = 0;	// Count of non-zero entries
	cout << "Matrix dimensions: " << rows << " x " << columns << endl;
	// Initialize Matrix Market typecode for a real-valued coordinate matrix
	mm_initialize_typecode(&matcode);
    	mm_set_matrix(&matcode);
    	mm_set_coordinate(&matcode);
    	mm_set_real(&matcode);

	// Count non-zero entries
	for (const auto& row : res) {
        	for (double value : row) {
            		if (value != 0.0) {
                		nz+=1;
            		}
        	}
    	}
	cout << "Non-zero count: " << nz << endl;
	// Write the Matrix Market banner and matrix size
	mm_write_banner(stdout, matcode);
	mm_write_mtx_crd_size(stdout, rows, columns, nz);
	 
	// Write each non-zero value with its 1-based row and column indices
	for (int i = 0; i < rows; ++i) {
        	for (int j = 0; j < columns; ++j) {
            		if (res[i][j] != 0.0) {
                		fprintf(stdout, "%d %d %10.3g\n", i + 1, j + 1, res[i][j]); 
			}
		}
	}

}
