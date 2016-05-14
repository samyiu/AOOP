#include <sstream>
#include "Num.h"
#include "Token.h"
#include "Tag.h"

Num::Num(int v) : Token(Tag::NUM), value(v)
{
	//super(Tag.NUM);
	//value = v;
}
string Num::toString()
{
	std::ostringstream buff;
	buff<<value;
	return buff.str();
}
string Num::printTag()
{
	return string("NUM");
}
