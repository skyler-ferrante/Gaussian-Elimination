/*
* Testing for matrix class
* 	Assumes file data/test.txt exists,
*	and contains at least three lines with matrix data
*/

#include<matrix.hpp>

#include<iostream>
#include<fstream>
#include<cassert>

#include<utility> //Pair

#define FILENAME "data/test.txt"
#define DEBUG true

using std::cout;
using std::endl;

void print_matrices(const char *step, Matrix &m1, Matrix &m2);

std::pair<Matrix,Matrix> test_read_matrices();
void test_swap_rows(Matrix &m1, Matrix &m2);
void test_scalar_mult(Matrix &m1, Matrix &m2);

int main(){
	auto matrices = test_read_matrices();
	Matrix m1 = matrices.first;
	Matrix m2 = matrices.second;

	test_swap_rows(m1, m2);
	test_scalar_mult(m1, m2);
}

std::pair<Matrix,Matrix> test_read_matrices(){
	std::ifstream file {FILENAME};
	assert(file && "Could not open file");

	Matrix m1(file);
	Matrix m2(m1);

	print_matrices("READ", m1, m2);

	assert( m1.height() == m2.height());
	assert( m1.width() == m2.width());

	for(int i = 0; i < m1.height(); i++){
		// Access rows through operator[]
		assert( m1[i] == m2[i]);
	}

	// Access rows through get_row
	assert( m1.get_row(0) != m1.get_row(1) && "Other tests rely on this unequal rows" );

	return std::make_pair(m1, m2);
}

void test_swap_rows(Matrix &m1, Matrix &m2){
	m1.swap_rows(0, 1);
	print_matrices("M1 SWAP 0 1", m1, m2);

	assert( m1.get_row(0) == m2.get_row(1) );
	assert( m1.get_row(1) == m2.get_row(0) );
	assert( m1.get_row(2) == m2.get_row(2) );
	
	m1.swap_rows(1,0);

	assert( m1.get_row(0) == m2.get_row(0) );
	assert( m1.get_row(1) == m2.get_row(1) );
	assert( m1.get_row(2) == m2.get_row(2) );
}

void test_scalar_mult(Matrix &m1, Matrix &m2){
	// Scalar multiplication
	// Implicitly tests mult_row
	m1 = m1 * 1;
	print_matrices("MULT M1 1", m1, m2);

	for( int i = 0; i < m1.height(); i++){
		assert( m1[i] == m2[i] && "m * 1 != m");
	}

	m2 = 4 * m2;

	print_matrices("MULT M2 4", m1, m2);
	for( int i = 0; i < m1.height(); i++){
		// Check if elements of m1 == elements of m2*4
		for( int j = 0; j < m1.width(); j++){
			assert( m1[i][j] * 4 == m2[i][j] );
		}
	}

	m2 = Matrix(m1);
	print_matrices("RESET M2", m1, m2);
}

void print_matrices(const char *step, Matrix &m1, Matrix &m2){
	if( DEBUG ){
		cout << "Step: " << step << endl;
		cout << "M1" << endl;
		m1.print();
		cout << "M2" << endl;
		m2.print();
		cout << endl;
	}
}
