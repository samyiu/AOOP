#include <string>
#include "Token.h"
#include "Tag.h"
#include "Word.h"

using namespace std;


Word::Word(string s, int tag) : Token(tag)
{
	
	lexeme = s;
}
string Word::toString()
{
	return lexeme;
}
string Word::printTag()
{
	switch(tag){
		case Tag::AND:
			return string("AND");
		case Tag::OR:
			return string("OR");
		case Tag::EQ:
			return string("EQ");
		case Tag::NE:
			return string("NE");
		case Tag::LE:
			return string("LE");
		case Tag::GE:
			return string("GE");
		case Tag::MINUS:
			return string("MINUS");
		case Tag::TRUE:
			return string("TRUE");
		case Tag::FALSE:
			return string("FALSE");
		case Tag::WHILE:
			return string("WHILE");
		case Tag::IF:
			return string("IF");
		case Tag::BASIC:
			return string("BASIC");
		case Tag::BREAK:
			return string("BREAK");
		case Tag::DO:
			return string("BASIC");
		case Tag::ID:
			return string("ID");
		default:
			return string(" ");
	}
	
}
const Word Word::And = Word("&&", Tag::AND);
const Word Word::Or = Word("||", Tag::OR);
const Word Word::eq = Word("==", Tag::EQ);
const Word Word::ne = Word("!=", Tag::NE);
const Word Word::le = Word("<=", Tag::LE);
const Word Word::ge = Word(">=", Tag::GE);
const Word Word::minus = Word("minus", Tag::MINUS);
const Word Word::True = Word("true", Tag::TRUE);
const Word Word::False = Word("false", Tag::FALSE);
const Word Word::temp = Word("t", Tag::TEMP);
