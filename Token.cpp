#include <string>
#include "Token.h"
#include "Tag.h"

using namespace std;


Token::Token(int t) : tag(t)
{
	//this->tag = t;
}
string Token::toString()
{
	return string(1, (char)tag);
}
string Token::printTag()
{
	return toString();
}
Token::~Token(){

}
