#ifndef __type_h_included__
#define __type_h_included__

#include <string> 
#include "Word.h"
#include "Tag.h"

using namespace std;


class Type : public Word {

public:
	int width = 0;
	Type(string s, int tag, int w);
	static const  Type Int;
	static const  Type Float;
	static const  Type Char;
	static const  Type Bool;
	
	static bool numeric(Type p);
	static Type max(Type p1, Type p2);

};

static Type TypeNULL = Type("", -1, -1);

#endif