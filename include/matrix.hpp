#ifndef LINEAR_H
#define LINEAR_H

#include<vector>
#include <fstream>

using std::vector;

typedef vector<int> ROW;
typedef ROW COL;

typedef vector<ROW> MATRIX;

class Matrix{
	public:
		// No default constructor
		Matrix() = delete;

		// Read from file
		Matrix( std::ifstream& file);

		// Already made MATRIX
		Matrix( MATRIX &matrix );

		// Copy constructor
		Matrix( const Matrix &matrix);

		void swap_rows(int r1, int r2);
		const ROW get_row(long unsigned int r);

		void print();

	private:
		MATRIX m;
};

#endif
