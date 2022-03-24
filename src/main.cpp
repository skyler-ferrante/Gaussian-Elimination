#include<matrix.hpp>

#include<iostream>
#include<fstream>

using std::cout;
using std::endl;

int main(int argc, char** argv){
	if(argc != 2){
		cout<<"Usage: "<<argv[0]<< " data-file"<<endl;
		return 1;
	}

	std::ifstream file {argv[1]};
	if( not file ){
		cout << "Can't open file" << endl;
		return 1;
	}

	Matrix m(file);
	m.print();
}
