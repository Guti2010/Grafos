all: grafo

grafo:
	g++ -o grafo.o main.cpp
	./grafo.o

# docker run -it --rm -v "/c/Users/windows/Documents/grafos:/home" gcc bash