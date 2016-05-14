#ifndef __num_h_included__
#define __num_h_included__

#include "Token.h"

class Num : public Token {
public:
	const int value;
	Num(int v) ;
	string toString();
	string printTag();
};

#endif