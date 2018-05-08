CCX=g++ -std=c++11


a.out: Board.o Pair.o newChar.o IllegalCharException.o IllegalCoordinateException.o
		$(CCX) main.cpp *.o
		
Board.o: Board.cpp Board.h
		$(CCX) -c Board.cpp
		
Coordinate.o: Pair.cpp Pair.h
		$(CCX) -c Coordinate.cpp
		
DerivedChar.o: newChar.cpp newChar.h
		$(CCX) -c newChar.cpp

# Symbol.o: Symbol.h
# 		$(CCX) -c Symbol.h

IllegalCharException.o: IllegalCharException.cpp
		$(CCX) -c IllegalCharException.cpp

IllegalCoordinateException.o: IllegalCoordinateException.cpp
		$(CCX) -c IllegalCoordinateException.cpp
		
Clean:
		rm *.o a.out
