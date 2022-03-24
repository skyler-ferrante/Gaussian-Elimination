#ifndef LINEAR_H
#define LINEAR_H

#include<vector>
#include <fstream>

using std::vector;

typedef vector<vector<int>> MATRIX;

// Read one line from file
void read_line(std::ifstream& file, MATRIX &m);

// Print matrix
void print_matrix(MATRIX const &m); 

#endif
