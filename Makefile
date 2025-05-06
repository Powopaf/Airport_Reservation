CC=g++
FLAGS=-Wall -Wextra -g
CFLAGS=-g
SRC= main.cpp \
	 airlines/airline.cpp \
	 airlines/booking.cpp \
	 query/query.cpp
OBJ=$(SRC:.cpp=.o)

debug: $(OBJ)
	$(CC) -o airline.out $(CFLAGS) $+

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm $(OBJ) *.out
