#include "write-matrix-market.hpp"
#include <vector>

using namespace std;
typedef vector<vector<double>> Matrix;

int main(){
Matrix mat = {
    {1.0, 0.0, 3.0},
    {0.0, 5.0, 0.0},
    {7.0, 0.0, 9.0}
};

write_matrix_market(mat);
return 0;
}
