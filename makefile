project : main.o graph.o hash.o vertices.o llist.o heapsort.o checkTriangleInequality.o minimumSpanningTree.o
	gcc -o project main.o graph.o hash.o vertices.o llist.o heapsort.o checkTriangleInequality.o minimumSpanningTree.o
main.o : main.c main.h
	gcc -c main.c  
graph.o : graph.c graph.h 
	gcc -c graph.c
vertices.o : vertices.c hash.h
	gcc -c vertices.c
llist.o : llist.c llist.h 
	gcc -c llist.c
hash.o : hash.c hash.h 
	gcc -c hash.c
heapsort.o : heapsort.c heapsort.h
	gcc -c heapsort.c
checkTriangleInequality.o : checkTriangleInequality.c checkTriangleInequality.h
	gcc -c checkTriangleInequality.c 
minimumSpanningTree.o : minimumSpanningTree.c minimumSpanningTree.h
	gcc -c minimumSpanningTree.c 

clean : 
	rm *.o
	#rm project main.o graph.o hash.o vertices.o llist.o heapsort.o checkTriangleInequality.o minimumSpanningTree.o



