FLAGS= -std=c++17 -O3
multiset: main.o
	g++ $(FLAGS) main.o -o bst

main.o: ../main.cpp ../bst.h
	g++ $(FLAGS) -c ../main.cpp

clean:
	find -not -name '.' -not -name '.gitignore' -not -name 'Makefile' -delete