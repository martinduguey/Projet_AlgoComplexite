CC = g++
CXX = g++
LIB = -lpthread

CXXFLAGS = -std=c++17 
ifdef DEBUG
CXXFLAGS += -g -O0 -Wall -fbounds-check -pedantic -D_GLIBCXX_DEBUG -DDEBUG
else
CXXFLAGS += -O3 -march=native -Wall
endif

default : test.exe

test.exe: test.o liste.hpp noeud.hpp population.o personne.o fonction.o RND.o 
	$(CXX) $(CXXFLAGS) -o test.exe test.o population.o personne.o fonction.o RND.o 

test.o: test.cpp population.hpp RND.hpp
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

population.o: population.cpp population.hpp personne.hpp liste.hpp 
	$(CXX) $(CXXFLAGS) -c population.cpp -o population.o

personne.o: personne.cpp personne.hpp liste.hpp
	$(CXX) $(CXXFLAGS) -c personne.cpp -o personne.o

fonction.o: fct.cpp declaration_fct.hpp
	$(CXX) $(CXXFLAGS) -c fct.cpp -o fonction.o

RND.o: RND.cpp RND.hpp
	$(CXX) $(CXXFLAGS) -c RND.cpp -o RND.o

clean :
	@rm -fr *.o *.exe 