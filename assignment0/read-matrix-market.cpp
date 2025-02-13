/**
 * @brief Reads a matrix from a Matrix Market file.
 *
 * This function reads a matrix stored in the Matrix Market format from a file. 
 * It supports reading sparse matrices stored in coordinate format and returns 
 * the matrix in a dense representation.
 *
 * @param filename The name of the Matrix Market file to be read.
 * @return A dense matrix (2D vector of doubles) representing the data in the file.
 *         The matrix will have dimensions \( M \times N \), with zeros filled in for 
 *         missing entries in the sparse format.
 *
 * @note The function assumes the file exists and follows the Matrix Market format
 *       specifications. It adjusts for 1-based indexing used in Matrix Market files.
 */

#include "mmio.h"
#include <vector>
#include <cstdlib>

using namespace std;
using std::vector;

typedef vector<vector<double>> Matrix;

Matrix read_matrix_market(const char* filename) {
	MM_typecode matcode;
	FILE* f;
	int M, N, nz; 
	
	// Open the file
	if ((f = fopen(filename, "r")) == nullptr) {
		exit(1);
        	printf("Could not open file.");
    	}

    	// Read the banner
    	if (mm_read_banner(f, &matcode) != 0) {
		exit(1);
        	printf("Could not process Matrix Market banner.");
    	}
	
    	// Read matrix dimensions
    	if (mm_read_mtx_crd_size(f, &M, &N, &nz) != 0) {
        	exit(1);
        	printf("Could not read matrix dimensions.");
    	}

    	// Initialize the matrix
    	Matrix matrix(M, vector<double>(N, 0));

    	// Read the entries
    	for (int i = 0; i < nz; ++i) {
        	int row, col; 
		double value;
        	if (fscanf(f, "%d %d %lf\n", &row, &col, &value) != 3) {
            		exit(1);
            		printf("Error reading matrix entries.");
        	}
        	matrix[row - 1][col - 1] = value; // Adjust for 1-based indexing
    	}

    	fclose(f);
    	return matrix;
}
