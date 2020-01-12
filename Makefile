# -*- Makefile -*-
CXX = c++
CXXFLAGS = -g -std=c++14 -Wall -Wextra -O3
LDLIBS= -lm
INC = bst.h

default: main.x

clean:
	rm -f *~ *# *.x *.o *.out

# Linker rule
main.x: main.o
	$(CXX) -o $@ $(CXXFLAGS) $^ $(LDLIBS)

# Compilation pattern rule for objects
%.o: %.cpp $(INC)
	$(CXX) -c $(CXXFLAGS) $< -o $@

# Run the executable
check: main.x

# Valgrind to check eventual memory leaks
valgrind: main.x
	valgrind ./main_valgind.x
