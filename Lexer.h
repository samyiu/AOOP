#ifndef __lexer_h_included__
#define __lexer_h_included__
#include "Word.h"
#include "Tag.h"
#include "Type.h"
#include "Token.h"
#include "Real.h"
#include "Num.h"

#include <map>
#include <string>
#include <iostream>


class Lexer{
private:
	char peek = ' ';
	//Hashtable<String, Word> words = new Hashtable<String, Word>();
	map<string,Word> words;
	
	void reserve(Word w);
	void readch();

	bool readch(char c) ;

public: 
	static int line;
	
	Lexer();
	Token* scan() ;
};
#endif