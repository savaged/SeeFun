# Reference1: http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# Reference2: https://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/ 

TARGET = bin/hello.app
CC = gcc
SRCDIR = src
OBJDIR = obj
INCDIR = include
SRCEXT = c
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS = -g # -Wall
LIB = -lm
INC = -I $(INCDIR)

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $(TARGET) $(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@rm -r $(OBJDIR) $(TARGET)

.PHONY: clean
