/*
* Testing for matrix class
* 	Assumes file data/test.txt exists,
*	and contains at least three lines with matrix data
*/

#include<matrix.hpp>

#include<iostream>
#include<fstream>
#include<cassert>

#define FILENAME "data/test.txt"
#define DEBUG true

using std::cout;
using std::endl;

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

int main(){
	std::ifstream file {FILENAME};
	if( not file ){
		cout << "Can't open file: " << FILENAME << endl;
		return 1;
	}

	Matrix m1(file);
	Matrix m2(m1);

	assert( m1.height() == m2.height());
	assert( m1.width() == m2.width());

	for(unsigned int i = 0; i < m1.height(); i++){
		// Access rows through operator[]
		assert( m1[i] == m2[i]);
	}

	// Access rows through get_row
	assert( m1.get_row(0) != m1.get_row(1) && "Other tests rely on this unequal rows" );

	print_matrices("READ", m1, m2);

	m1.swap_rows(0, 1);

	assert( m1.get_row(0) == m2.get_row(1) );
	assert( m1.get_row(1) == m2.get_row(0) );
	assert( m1.get_row(2) == m2.get_row(2) );
	
	print_matrices("M1 SWAP 0 1", m1, m2);
}
