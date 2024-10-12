flags = -std=c++17 -Wall -I .

program3functions.o : program3functions.cpp program3functions.h
	g++ $(flags) -c $< -I .

program3 : program3.cpp program3functions.o
	g++ $(flags) $^ -o $@

checkit : checkit.cpp
	g++ $(flags) $^ -o $@

program3test1 : program3 checkit test1-input.txt correct-test1.txt
	./program3 test1-input.txt > student-test1.txt
	./checkit 0

program3test2 : program3 checkit test2-input.txt correct-test2.txt
	./program3 test2-input.txt > student-test2.txt
	./checkit 1

clean :
	rm student-test*txt checkit program3 *.o 

