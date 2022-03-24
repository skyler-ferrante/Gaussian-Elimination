#include<matrix.hpp>

#include<string>
#include<iostream>
#include<fstream>
#include<sstream>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void read_line(std::ifstream& file, MATRIX &matrix){
	string s;

	// Go through lines
	while( std::getline(file, s) ){
		vector<int> current_line;
		
		std::istringstream ss {s};
		int n;
		
		// Go through ints in line
		while( ss >> n)
			current_line.push_back(n);
		
		matrix.push_back( current_line );
	}
}

void print_matrix( MATRIX const &matrix){
	for( auto r : matrix ){
		for( auto e : r ){
			cout << e << " ";
		}
		cout << endl;
	}
}
