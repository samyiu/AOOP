#ifndef __real_h_included__
#define __real_h_included__

#include "Token.h"

class Real : public Token {

public:
	const float value;
	Real(float v) ;
	string toString();
	string printTag();
};

#endif