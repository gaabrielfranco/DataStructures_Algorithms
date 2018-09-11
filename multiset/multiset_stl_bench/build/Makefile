FLAGS= -std=c++17 -O3
multiset: main.o
	g++ $(FLAGS) main.o -o multiset

main.o: ../main.cpp
	g++ $(FLAGS) -c ../main.cpp

clean:
	find -not -name '.' -not -name '.gitignore' -not -name 'Makefile' -delete