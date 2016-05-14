#include <sstream>
#include <string>
#include "Token.h"
#include "Real.h"
#include "Tag.h"

Real::Real(float v) : Token(Tag::REAL), value(v)
{
	//super(Tag.REAL);
	//value = v;
}
string Real::toString()
{
	std::ostringstream buff;
	buff << value;
	return buff.str();
}
string Real::printTag()
{
	return string("REAL");
}
