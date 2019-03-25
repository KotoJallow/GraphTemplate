
run: compile
	./graph
compile: graph main
	g++ main.o graph.o -o graph
graph: graph.cpp
	g++ -c graph.cpp 
main: main.cpp
	g++ -c main.cpp
clean:
	rm *.o