#!make -f


ed: main.o Document.o Editor.o
	g++ -o ed main.o Document.o Editor.o
main.o: main.cpp
	g++ -c main.cpp -o main.o
Document.o: Document.cpp Document.h
	g++ -c Document.cpp -o Document.o
Editor.o: Editor.cpp Editor.h 
	g++ -c Editor.cpp -o Editor.o


clean:
	rm -f  *.o ed
