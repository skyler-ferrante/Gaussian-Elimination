#include<matrix.hpp>

#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<cassert>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void row_index_assert( int r, const Matrix& m){
	assert( r < m.height() && "Row index larger than amount of rows");
}

Matrix::Matrix( std::ifstream& file ){
	string s;

	// Go through lines
	while( std::getline(file, s) ){
		ROW current_line;
		
		std::istringstream ss {s};
		ELEMENT e;
		
		// Go through ints in line
		while( ss >> e)
			current_line.push_back(e);

		m.push_back( current_line );
	}
}

Matrix::Matrix( const Matrix &matrix ){
	m = matrix.m;
}

void Matrix::swap_rows(int r1,  int r2){
	std::swap( m[r1], m[r2] );
}

void Matrix::print(){
	for( auto r : m ){
		for( auto e : r ){
			cout << e << " ";
		}
		cout << endl;
	}
}

const ROW& Matrix::get_row(int r){
	row_index_assert(r, *this);
	return m[r];
}

 int Matrix::height() const{
	return m.size();
}

 int Matrix::width() const{
	return m[0].size();
}

void Matrix::mult_row(int r, ELEMENT mult){
	row_index_assert(r, *this);

	for(auto& e : m[r])
		e *= mult;
}

Matrix operator* (ELEMENT x, const Matrix m){
	Matrix result(m);
	for( int i = 0; i < m.height(); i++){
		result.mult_row(i, x);
	}

	return result;
}

Matrix operator* (const Matrix m, ELEMENT x){
	return x * m;
}
