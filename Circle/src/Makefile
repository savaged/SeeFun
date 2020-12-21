EXE = circle.app
IDIR = ../include
ODIR=../obj
LDIR =../lib
CC = gcc
LD = gcc
DEBUG = -g
WARN = -Wall
CFLAGS = -I$(IDIR) $(DEBUG) $(WARN)
LIBS=-lm

_DEPS = circle.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o circle.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJ)
	$(LD) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
