/**
 * @brief Performs matrix-vector multiplication.
 *
 * This function multiplies a matrix `m1` with a vector `v1` and returns the resultant vector.
 * It assumes that the number of columns in the matrix matches the size of the vector.
 *
 * @param m1 The input matrix (n x m).
 * @param v1 The input vector (size m).
 * @return The resultant vector after multiplication (size n).
 */

#include <vector>

using std::vector;

typedef vector<vector<double>> Matrix;
typedef vector<double> Vector;

Vector matrix_vector_product(const Matrix& m1, const Vector& v1){
	int n = m1.size(); // number of rows of m1
	int m = m1[0].size(); // number of columns of m1
	Vector v2(n); // define a vector to return that has the number of rows as m1

	for (int i = 0; i < n; ++i){
		double sum = 0;
		for (int j = 0; j < m; ++j){
			sum = sum + m1[i][j] * v1[j];
		}
		v2[i] = sum;
	}
	return v2;
}
