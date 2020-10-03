# Define some constants used throughout the Makefile.
# First line is used to avoid trouble on systems where the SHELL variable 
SHELL = /bin/sh
CC = g++
CFLAGS = -std=c++11 -Wall -g 
INCLUDES = -I../include 
SRC = ../sources
OBJ = Utilityfunc.o Rdcrtfile.o read_create_file.o
EXE = rdcrtfile
OUT_FILE = ../data/loomings-clean.txt

# SRC = read_create_file.cpp
# '$@' is used to represent the target 
# '$<' is used to represent the dependency 

$(EXE): $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ)

# We can also use the below line as it generates the object file corresponding to their source.
%.o: $(SRC)/%.cpp
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ) $(EXE) $(OUT_FILE) File-* 

run:
	./$(EXE) ../data/loomings.txt 
