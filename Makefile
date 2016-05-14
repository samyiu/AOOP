

all : scanner

scanner: Main.o Lexer.o Token.o Type.o Word.o Real.o Num.o
	$(CXX) -std=c++11 -Wall -o $@ Main.o Lexer.o Token.o Type.o Word.o Real.o Num.o
Lexer.o: 
	$(CXX) -std=c++11 -Wall -c Lexer.cpp 

Token.o : Token.cpp
	$(CXX) -std=c++11 -Wall -c Token.cpp 

Type.o : Type.cpp Word.cpp Token.cpp
	$(CXX) -std=c++11 -Wall -c Type.cpp  

Word.o : Word.cpp Token.cpp
	$(CXX) -std=c++11 -Wall -c Word.cpp 
	
Real.o : Real.cpp
	$(CXX) -std=c++11 -Wall -c Real.cpp

Num.o : Num.cpp
	$(CXX) -std=c++11 -Wall -c Num.cpp    
Main.o: Main.cpp
	$(CXX) -std=c++11 -Wall -c Main.cpp    

clean :
	rm -f *.o scanner