CC = g++
FLAGS = -Wall -Werror -pedantic -std=c++17 -g
PROGRAM = Encode
DEPS = ShiftRegister.hpp
OBJS = ShiftRegister.o
LIB = -lsfml-system -lsfl-window -lsfml-graphics

all: $(PROGRAM) test

$(PROGRAM):	Encode.o $ (OBJS)
		$(CC) $(FLAGS) -o $@ $^ $(LIB)

test:	test.o $(OBJS)
		$(CC) $(FLAGS) -o $@ $^ $(LIB)

%.o: %.cpp $(DEPS)
		$(CC) $(FLAGS) -c $<

clean:
		rm *.o $(PROGRAM)
