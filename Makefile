all: blackjack.o
	gcc blackjack.o main.o -o main.exe
blackjack.o: blackjack.h
	gcc -c blackjack.c main.c
clean:
	rm -rf *.o