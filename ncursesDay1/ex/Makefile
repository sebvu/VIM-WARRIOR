OBJ_NAME = moving-cursor # Output file
EXT = .cpp

#OBJS is the.cpp file we make out of our OBJ_Name
OBJS = $(join $(OBJ_NAME),$(EXT))

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lncurses

#This is the target that compiles our executable
all : 
	$ g++ $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME)
	$ ./($OBJ_NAME)

file : 
	$ g++ $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME)

exec:
	$ ./$(OBJ_NAME)
