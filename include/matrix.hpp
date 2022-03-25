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
		void mult_row(int r, int mult);

		int height() const;
		int width() const;

		const ROW& get_row(int r);
		const ROW& operator[](int r){ return get_row(r); }

		void print();

	private:
		MATRIX m;
};

Matrix operator*(int x, Matrix m);
Matrix operator*(Matrix m, int x);

#endif
