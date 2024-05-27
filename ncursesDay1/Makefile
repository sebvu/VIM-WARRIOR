# OBJ_NAME = $(fn)
OBJ_NAME = hello-world # Output file
EXT = .cpp

#OBJS is the.cpp file we make out of our OBJ_Name
OBJS = $(join $(OBJ_NAME),$(EXT))

#CC specifies which compiler we're using
CC = g++

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lncurses

#This is the target that compiles our executable
all : 
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)