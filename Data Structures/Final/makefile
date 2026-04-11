project: dll.o node.o bst.o tnode.o main.o
	gcc dll.o node.o bst.o tnode.o main.o -o project
dll.o: dll.c
	gcc -c dll.c
node.o: node.c
	gcc -c node.c
bst.o: bst.c
	gcc -c bst.c
tnode.o: tnode.c
	gcc -c tnode.c
main.o: main.c
	gcc -c main.c
clean:
	rm -f project dll.o node.o bst.o tnode.o main.o