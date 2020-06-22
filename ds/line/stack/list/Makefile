all:liststack

liststack:main.o stack.o llist.o
	$(CC) $^ -o $@

clean:
	rm *.o liststack -rf