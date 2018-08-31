FLAGS= -std=c++17 -g
multiset: main.o
	g++ $(FLAGS) main.o -o multiset

main.o: ../main.cpp ../Multiset.h
	g++ $(FLAGS) -c ../main.cpp

clean:
	find -not -name '.' -not -name '.gitignore' -not -name 'Makefile' -delete