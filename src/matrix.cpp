#include<matrix.hpp>

#include<string>
#include<iostream>
#include<fstream>
#include<sstream>

using std::cout;
using std::endl;
using std::vector;
using std::string;

Matrix::Matrix( std::ifstream& file ){
	string s;

	// Go through lines
	while( std::getline(file, s) ){
		vector<int> current_line;
		
		std::istringstream ss {s};
		int n;
		
		// Go through ints in line
		while( ss >> n)
			current_line.push_back(n);

		m.push_back( current_line );
	}
}

void Matrix::swap_rows( int r1, int r2 ){
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
