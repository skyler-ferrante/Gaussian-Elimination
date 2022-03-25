#ifndef LINEAR_H
#define LINEAR_H

#include<vector>
#include <fstream>

using std::vector;

typedef double ELEMENT;
typedef vector<ELEMENT> ROW;
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

		// Swap r1 and r2
		void swap_rows(int r1, int r2);

		// Mult r by mult
		void mult_row(int r, ELEMENT mult);

		// Add r1*mult to r2
		void add_row_mult(int r1, int r2, ELEMENT mult);

		int height() const;
		int width() const;

		const ROW& get_row(int r);
		const ROW& operator[](int r){ return get_row(r); }

		void print();

	private:
		MATRIX m;
};

Matrix operator*(ELEMENT x, Matrix m);
Matrix operator*(Matrix m, ELEMENT x);

#endif
