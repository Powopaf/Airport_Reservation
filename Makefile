CC=g++
FLAGS=-Wall -Wextra -g
CFLAGS=-g
SRC= main.cpp \
	 booking/airline.cpp \
	 booking/booking.cpp \
	 query/query.cpp
OBJ=$(SRC:.cpp=.o)

debug: $(OBJ)
	$(CC) -o arline.out $(CFLAGS) $+

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm $(OBJ) *.out
