CC = g++
CFLAGS = -Wall -Wextra -std=c++11

all: bible

bible: main.o helper.o tools.o
	$(CC) $(CFLAGS) main.o helper.o tools.o -o bible

main.o: main.cpp helper.h tools.h
	$(CC) $(CFLAGS) -c main.cpp

helper.o: helper.cpp helper.h 
	$(CC) $(CFLAGS) -c helper.cpp

tools.o: tools.cpp helper.h tools.h
	$(CC) $(CFLAGS) -c tools.cpp

clean:
	del -f *.o *.exe bible