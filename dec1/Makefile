.PHONY: all, clean
PROGNAME := dec1

CXX := g++
RM := rm -f
LDFLAGS += -g

default:all

all: exec

exec: main.cpp
	$(CXX) $(LDFLAGS) -o exec main.cpp

clean:
	rm exec
