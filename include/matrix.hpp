#ifndef LINEAR_H
#define LINEAR_H

#include<vector>
#include <fstream>

using std::vector;

typedef vector<vector<int>> MATRIX;

class Matrix{
	public:
		// No default constructor
		Matrix() = delete;

		// Read from file
		Matrix( std::ifstream& file);

		// Already made MATRIX
		Matrix( MATRIX &matrix );

		void print();

	private:
		MATRIX m;
};

#endif
