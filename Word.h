#ifndef __word_h_included__
#define __word_h_included__

#include <string>
#include "Token.h"
#include "Tag.h"

using namespace std;

class Word : public Token {

public:
	string lexeme = "";
	Word(string s, int tag) ;
	string toString();
	string printTag();
	static const Word And;
	static const Word Or;
	static const Word eq;
	static const Word ne;
	static const Word le;
	static const Word ge;
	static const Word minus;
	static const Word True;
	static const Word False;
	static const Word temp;
};

#endif