# Reference: http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# This Makefile should be in the src directory of the project

EXE = hello.app
IDIR = ../include
ODIR=../obj
LDIR =../lib
CC = gcc
LD = gcc
DEBUG = -g
WARN = -Wall
CFLAGS = -I$(IDIR) $(DEBUG) $(WARN)
LIBS=-lm

_DEPS = greeter.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o greeter.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJ)
	$(LD) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
