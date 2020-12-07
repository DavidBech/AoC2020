.PHONY: all, clean
PROGNAME := dec2

CXX := g++
RM := rm -f
LDFLAGS += -g

default:all

all: exec

exec: main.cpp
	$(CXX) $(LDFLAGS) -o exec main.cpp

run: exec
	./exec

clean:
	rm exec
