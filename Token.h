#ifndef __token_h_included__
#define __token_h_included__

#include <string>
#include "Tag.h"

using namespace std;
class Token {
public:
	const int tag;
	Token(int t);
	virtual string toString();
	virtual string printTag();
	virtual ~Token();
};

#endif
