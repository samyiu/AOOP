#include <iostream>
#include <fstream>
#include <iomanip>
#include "Lexer.h"

using namespace std;

int main(int argc, char** argv) 
{
	std::ifstream in(argv[1]);
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!
	Lexer lexer;
	try {
		while (true) {
			Token* t = lexer.scan();
			cout << "Token : " <<  setw(10) << left << (t->toString()) ;
			cout <<  "(" <<  t->printTag() << ")" << endl;
			
			delete(t);
		}
	} catch (const char* msg) {
		cout << msg << endl;
	}
	std::cin.rdbuf(cinbuf); 
	return 0;
}
