FLAGS= -std=c++17 -O3
multiset: main.o
	g++ $(FLAGS) main.o -o binary_search

main.o: ../main.cpp ../binary_search.h
	g++ $(FLAGS) -c ../main.cpp

clean:
	find -not -name '.' -not -name '.gitignore' -not -name 'Makefile' -delete