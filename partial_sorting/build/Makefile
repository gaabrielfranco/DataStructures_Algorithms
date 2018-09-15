FLAGS= -std=c++17 -O3
multiset: main.o
	g++ $(FLAGS) main.o -o sort

main.o: ../main.cpp ../sort.h
	g++ $(FLAGS) -c ../main.cpp

clean:
	find -not -name '.' -not -name '.gitignore' -not -name 'Makefile' -delete