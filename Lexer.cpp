#include "Word.h"
#include "Tag.h"
#include "Type.h"
#include "Token.h"
#include "Real.h"
#include "Num.h"
#include "Lexer.h"

#include <map>
#include <string>
#include <iostream>


void Lexer::reserve(Word w)
{
	words.insert(std::pair<string,Word>(w.lexeme,w));
}
void Lexer::readch()
{

	int i = cin.get();

	if (i != -1)
		peek = (char) i;
	else
		throw "End of file reached";
}
bool Lexer::readch(char c) 
{
	try{
		readch();
	}
	catch(const char* message){
		throw;
	}
	if (peek != c)
		return false;
	peek = ' ';
		return true;
}
	
Lexer::Lexer()
{
	peek= ' ';
	reserve(Word("if", Tag::IF) );
	reserve(Word("else", Tag::ELSE) );
	reserve(Word("while", Tag::WHILE) );
	reserve(Word("do", Tag::DO) );
	reserve(Word("break", Tag::BREAK) );
	reserve(Word::True);
	reserve(Word::False);
	reserve(Type::Int);
	reserve(Type::Char);
	reserve(Type::Bool);
	reserve(Type::Float);
}
Token* Lexer::scan() //throws IOException
{
	try{
		for ( ; ; readch()) {
			if (peek == ' ' || peek == '\t' || peek == '\r')
				continue;
			else if (peek == '\n' )
				line = line + 1;
			else
				break;
		}
		switch (peek) {
			case '&':
				if (readch('&'))
					return new Word("&&", Tag::AND);
				else
					return new Token('&');
			case '|':
				if (readch('|'))
					return new Word("||", Tag::OR);
				else
					return new Token('|');
			case '=':
				if (readch('='))
					return new Word("==", Tag::EQ);
				else
					return new Token('=');
			case '!':
				if (readch('='))
					return new Word("!=", Tag::NE);
				else
					return new Token('!');
			case '<':
				if (readch('='))
					return new Word("<=", Tag::LE);
				else
					return new Token('<');
			case '>':
				if (readch('='))
					return new Word(">=", Tag::GE);
				else
					return new Token('>');
		}
		if (isdigit(peek)) {
			int v = 0;
			do {
				v = 10 * v +  (peek- '0');
				readch();
			} while (isdigit(peek));
			if (peek != '.')
				return new Num(v);
			float x = v;
			float d = 10;
			for (;;) {
				readch();
				if (!isdigit(peek))
					break;
				x = x + (peek- '0') / d;
					d = d * 10;
			}

			return new Real(x);
		}

		if (isalpha(peek)){
			string b = string("");
			do {
				b += peek;
				readch();
			} while (isalnum(peek));
			
			string s = b/*.toString()*/;
			map<string,Word>::iterator it;
			it = words.find(s);
			//Word w = (Word) words.get(s);
			if (it != words.end())
				//return (Word)it->second;
				return new Word(it->second.lexeme,it->second.tag);
			/*if (w != null)
				return w;*/
			Word w = Word(s, Tag::ID);
			words.insert(std::pair<string,Word>(s, w));
			return new Word(s, Tag::ID);
		}
		Token* tok = new Token(peek);
		peek = ' ';
		return tok;
	}
	catch(const char* msg){
		throw;
	}

}
int Lexer::line = 1;