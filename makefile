
sourcepath = sources
headerpath = headers
out: $(headerpath)/Dictionary.h $(headerpath)/Graph.h $(sourcepath)/Dictionary.cpp $(sourcepath)/Graph.cpp $(sourcepath)/main.cpp
	g++ -I$(headerpath) -o out $(sourcepath)/main.cpp $(sourcepath)/Dictionary.cpp $(sourcepath)/Graph.cpp
	./out
clean:
	rm out
