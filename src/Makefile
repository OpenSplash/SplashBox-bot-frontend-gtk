all: splashbox-bot-frontend-gtk

main.o: main.c
	gcc -c -Wall -O3 main.c -o main.o `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`

splashbox-bot-frontend-gtk: main.o
	gcc -Wall -O3 main.o -o splashbox-bot-frontend-gtk `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`

clean:
	rm *.o
