CC = gcc
CFLAGS = -Wall -Wno-implicit-function-declaration -g
SRCS = main.c blackjack.c
OBJS = main.o blackjack.o
TARGET = main.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c blackjack.h
	$(CC) $(CFLAGS) -c main.c -o main.o
blackjack.o: blackjack.c blackjack.h
	$(CC) $(CFLAGS) -c blackjack.c -o blackjack.o
clean:
	rm -rf *.o