CC=g++
CFLAGS= -c -Wall -std=c++11
INCLUDE= -I/home/bkwan/dev/include
#LDFLAGS= -L/home/bkwan/dev/lib -lgsl -lgslcblas -lm
LDFLAGS= -L/home/bkwan/dev/lib -lm
SOURCES=example.cpp
#OBJECTS=$(SOURCES: .cpp=.o)
EXECUTABLE=blas

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): example.o
	$(CC) $(LDFLAGS) example.o -o $@

example.o: example.cpp
	$(CC) $(CFLAGS) $(INCLUDE) example.cpp

clean:
	rm -f *.o *~
