#include <stdio.h>

#include "hash.h"



/*Allocate the memory and initialize the hash table.*/
void vertexHashInit(struct vertexHashTable *vertexHash) {
	int i;
	for(i = 0; i < MAXBUCKETS; i++)
		vertexHash->buckets[i] = NULL;
}

/*Use your own hash function to calculate the hash value*/
int calcVertexHash(char *vertexName) {
	unsigned int hash = 5381;
	int c;
	while(c = *vertexName++) {
		hash = (hash << 5 + hash) + c; /* hash*33 + c */
	}
	return (int)(hash % MAXBUCKETS);	
}

/*Insert the Type A vertex in hash table. Return 0 on success and -1 on failure*/
int vertexHashInsert(struct vertexHashTable *vertexHash, struct Vertex *vertexdata) {
	int h = calcVertexHash(vertexdata->vertexName);
	struct Vertex *res = llGetVertex(vertexHash->buckets[h], vertexdata->vertexName);
	if(res != NULL)
		return -1;	
	int r = llVertexInsert(&(vertexHash->buckets[h]), vertexdata);
	return r;	
}

/*For the given vertex name calculate the hash value and return the corresponding vertex id from hashtable. Return -1 if vertex name not found*/
int getVertexId(struct vertexHashTable *vertexHash,char *vertexName) {
	int h = calcVertexHash(vertexName);
	if(vertexHash->buckets[h] == NULL)
		return -1;
	else {
		struct llVertexNode *temp = vertexHash->buckets[h];
		while(strcmp(temp->vertexInfo->vertexName, vertexName) != 0 && temp->next != NULL)	
			temp=temp->next;
		if(strcmp(temp->vertexInfo->vertexName, vertexName) == 0)
			return temp->vertexInfo->vertexId;	
		else if(temp->next == NULL)
			return -1;

	}
}


/*For the given vertex id return vertexname from array. Return NULL if vertex id is invalid*/
char *getVertexName(int vertexId) {
	int i;
	//for(i = 0; i < numVertices; i++) 
		//if(i == vertexId)
 			return vertices[vertexId];	
	//return NULL;

}

