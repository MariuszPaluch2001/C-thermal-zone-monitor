
all : cc link
cc :
	$(CC) -no-pie -c -g -O0 src/main.c
link :
	$(CC) -no-pie -o exe main.o 
clean :
	rm *.o
	rm exe
