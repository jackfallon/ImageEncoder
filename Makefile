CC = g++
FLAGS = -Wall -Werror -pedantic -std=c++17 -g
PROGRAM = PhotoMagic
DEPS = FibLFSR.hpp
OBJS = FibLFSR.o
LIB = -lsfml-graphics -lsfml-window -lsfml-system -lboost_unit_test_framework

all: $(PROGRAM) test

$(PROGRAM):	PhotoMagic.o $ (OBJS)
		$(CC) $(FLAGS) -o $@ $^ $(LIB)

test:	test.o $(OBJS)
		$(CC) $(FLAGS) -o $@ $^ $(LIB)

%.o: %.cpp $(DEPS)
		$(CC) $(FLAGS) -c $<

clean:
		rm *.o $(PROGRAM)
