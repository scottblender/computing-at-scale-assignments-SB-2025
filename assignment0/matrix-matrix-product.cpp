/**
 * @brief Performs matrix-matrix multiplication.
 *
 * This function multiplies two matrices `m1` and `m2` and returns the resultant matrix.
 * It assumes that the dimensions of the matrices are compatible for multiplication,
 * i.e., the number of columns in `m1` equals the number of rows in `m2`.
 *
 * @param m1 The first input matrix (a x b).
 * @param m2 The second input matrix (b x c).
 * @return The resultant matrix after multiplication (a x c).
 *
 * @throws std::exit(1) if either matrix does not have more than one column.
 */
#include <vector>
#include <iostream>

using std::vector;
typedef vector<vector<double>> Matrix;

Matrix matrix_matrix_product(const Matrix& m1, const Matrix& m2){
	int a = m1.size(); // number of rows of m1
	int b = m1[0].size(); // number of columns of m1
	int c = m2[0].size(); // number of columns of m2
	int d = m2.size(); // number of rows of m2
	if (a>1 && b>1 && c>1 && d>1){
		Matrix m3(a, vector<double>(c));

		for (int i = 0; i < a; ++i){
			for (int j = 0; j < c; ++j) {
				double sum = 0;
				for (int k = 0; k < c; ++k) {
					sum = sum + m1[i][k]*m2[k][j];
				}
				m3[i][j] = sum;
			}
		}
		return m3;
	}
	else{
		std::cerr<<"Matrices must have more than one column."<<std::endl;
		std::exit(1);
	}
}
