#include <iostream>
#include "matrix-matrix-product.hpp"
#include "matrix-vector-product.hpp"
#include "read-matrix-market.hpp"
#include "write-matrix-market.hpp"

using namespace std;
typedef vector<vector<double>> Matrix;
typedef vector<double> Vector;

int main(int argc, char* argv[]) {
    const char* file1 = argv[1];
    const char* file2 = argv[2];
    int operation_type = atoi(argv[3]);

    if (operation_type == 0) {
        // Read the matrix and vector
        Matrix m1 = read_matrix_market(file1); // Read in the matrix file.
        cout << "Matrix 1 loaded." << endl; 

        Matrix v1 = read_matrix_market(file2); // Read in the vector file.
        cout << "Vector 1 loaded." << endl;
	cout << "\n";

	if (v1[0].size() != 1) {
        cout << "Error: Input matrix is not a single-column vector." << endl;
        exit(1);
    	}

    	Vector v1_conv(v1.size()); // define vector to store values from v1
    	/*
	 * This loop below takes values from v1 and stores them in a new vector to convert it to a 1D vector
	 */
	for (size_t i = 0; i < v1.size(); ++i) {
        	v1_conv[i] = v1[i][0];
    	} 
	cout << "Input vector:" << endl;
        for (double val : v1_conv) {
            cout << val << endl;
	}
	cout<<"\n";
        // Perform matrix-vector product
        Vector result = matrix_vector_product(m1, v1_conv);

        // Output the result
        cout << "Resultant vector:" << endl;
        for (double val : result) {
            cout << val << endl;
        }
	Matrix result_conv(result.size(), vector<double>(1));  // Define matrix with M rows, one column to write out in matrix market format
    	for (size_t j = 0; j < result.size(); ++j) {
        	result_conv[j][0] = result[j];
    	}
	cout<<"\n";
	write_matrix_market(result_conv);
    }

    else if(operation_type == 1){
    	Matrix m1 = read_matrix_market(file1); // Load in first matrix file
	cout << "Matrix 1 loaded." << endl; 
        Matrix m2 = read_matrix_market(file2); // Load in second matrix file
	cout << "Matrix 2 loaded." << endl;
	cout << "\n";

        Matrix result = matrix_matrix_product(m1, m2); // Perform the matrix-matrix product.
	
	// Output the result
    	cout << "Resultant matrix:" << endl;
    	for (const auto& row : result) {
        	for (double val : row) {
			cout << val << " ";
        	}
		cout << endl;
    	}
	cout<<"\n";
	write_matrix_market(result);
    }
    return 0;
}
