LIB_SOURCES := $(wildcard ./DtStr/*.cpp)
LIB_OBJECTS := $(patsubst ./DtStr/%.cpp, ./Objs/%.o, $(LIB_SOURCES))

all:main.exe

main.exe: $(LIB_OBJECTS) main.o 
	g++ $^ -o $@

main.o: main.cpp
	g++ -c $^

./Objs/%.o: ./DtStr/%.cpp
	g++ -c $< -o $@

clean:
	rm ./Objs/* ./*.exe *.o
