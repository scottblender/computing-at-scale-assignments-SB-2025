#ifndef Assignment_0_Read_Matrix_Market_H
#define Assignment_0_Read_Matrix_Market_H
#include <vector>

typedef std::vector<std::vector<double>> Matrix;

Matrix read_matrix_market(const char* filename);

#endif
