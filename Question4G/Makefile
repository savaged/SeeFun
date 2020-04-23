# Reference 1: https://prognotes.net/2015/07/gtk-3-glade-c-programming-template/
# Reference 2: http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

EXE = question4g.app
# compiler
CC = gcc
DEBUG = -g
# optimisation
OPT = -O0
WARN = -Wall
INC = .
PTHREAD = -pthread

CCFLAGS = -I$(INC) $(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

GTKLIB = `pkg-config --cflags --libs gtk+-3.0`

# linker
LD = gcc
LDFLAGS = $(PTHREAD) $(GTKLIB) -export-dynamic

all: main.o
	$(LD) -o $(EXE) $^ $(LDFLAGS)

main.o: main.c main.h
	$(CC) -c $(CCFLAGS) $< $(GTKLIB) -o $@

clean:
	rm -f *.o $(EXE)
