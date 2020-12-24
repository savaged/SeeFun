# Reference1: http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# Reference2: https://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/ 

CC = gcc
SRCEXT = c
BINDIR = bin
SRCDIR = src
OBJDIR = obj
INCDIR = include
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS = -g # -Wall
LIB = -lm
INC = -I $(INCDIR)

TARGET = $(BINDIR)/hello.app

$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $^ -o $(TARGET) $(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@rm -r $(OBJDIR) $(TARGET)

.PHONY: clean
