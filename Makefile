MAINPROG=Algorithm3.2

SOURCES:=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
FLAGS=-std=c++11 -fsanitize=address,leak  -Wall -fuse-ld=gold

all: $(SOURCES) $(MAINPROG)

$(MAINPROG): $(OBJECTS)
	g++ $(FLAGS) $(OBJECTS) -o $@

.cpp.o:
	g++ $(FLAGS) -c $< -o $@

clean:
	rm *.o $(MAINPROG)