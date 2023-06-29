LIB_SOURCES := $(wildcard ./DtStr/*.cpp)
LIB_OBJECTS := $(patsubst ./DtStr/%.cpp, ./Objs/%.o, $(LIB_SOURCES))

CPPFLAGS = -Wall -Wextra

all:main.exe

main.exe: $(LIB_OBJECTS) main.o 
	g++ $(CPPFLAGS) $^ -o $@

main.o: main.cpp
	g++ $(CPPFLAGS) -c $^

./Objs/%.o: ./DtStr/%.cpp
	g++ $(CPPFLAGS) -c $< -o $@

clean:
	rm ./Objs/* ./*.exe *.o
