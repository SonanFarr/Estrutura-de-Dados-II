###############################################################################
# File management.  This is where the source, header, and object files are
# defined

#
# source files
srcfiles 	:= $(wildcard *.cpp) $(wildcard src/*.cpp)

#
# object files
objects		:= $(patsubst %.cpp, %.o, $(srcfiles))

################################################################################3

# Compiler and linker
CC = g++
 
# Flags for compiler
CC_FLAGS= -g -I./Headers
# CC_FLAGS= -g -I./include  
 
# Command used at clean target
RM = rm -rf

target     := ./TrabalhoED2.exe 
 
#
# Compilation and linking
#
all: $(target)

# Production rules:  how to make the target - depends on library configuration
$(notdir $(target)): $(objects)
	@echo "Linking "$@"..."
	@$(CC) $(objects) -o $@
 
%.o: %.cpp
	@echo "Compiling C++"$<"..."
	@$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -rf $(objects) $(target) *~


.PHONY: all clean