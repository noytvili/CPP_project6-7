CCX=g++ -std=c++11


a.out: Board.o Pair.o newChar.o IllegalCoordinateException.o IllegalCharException.o 
		$(CCX) main.cpp *.o
		
Board.o: Board.cpp Board.h
		$(CCX) -c Board.cpp
		
Pair.o: Pair.cpp Pair.h
		$(CCX) -c Pair.cpp
		
newChar.o: newChar.cpp newChar.h
		$(CCX) -c newChar.cpp

Exceptions.o: IllegalCoordinateException.cpp IllegalCharException.cpp
		$(CCX) -c Exceptions.cpp
		
Clean:
		rm *.o a.out
