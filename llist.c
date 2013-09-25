#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"


/*Return the node of the linked list containing the key. If not fonud, return NULL*/
struct Edge * llGetEdge(struct llEdgeNode *head, struct Edge *key) {
	//struct llEdgeNode *temp = head;
	int c = key->vertexId1;
	int d = key->vertexId2;	
	/*if (c > d) {
		c = d;
		d = key->vertexId1;
	}	*/
	while (head != NULL) {
		int a = head->edgeInfo->vertexId1;
		int b = head->edgeInfo->vertexId2;
		/*if (a > b) {
			a = b;
			b = head->edgeInfo->vertexId1;
		}*/
			
		if ((a == c) && (b == d)) 
			return head->edgeInfo;
		head = head->next;
	}
	return NULL;
}

/*Insert the Type A edge in linked list. Return 0 on success and -1 on failure*/
int llEdgeInsert(struct llEdgeNode **head, struct Edge *edgeData) {
	//Assumes that the edge is not already present
	struct llEdgeNode *temp = (struct llEdgeNode *)malloc(sizeof(struct llEdgeNode));
	temp->edgeInfo = (struct Edge *)malloc(sizeof(struct Edge));
	(temp->edgeInfo)->vertexId1 = edgeData->vertexId1;
	(temp->edgeInfo)->vertexId2 = edgeData->vertexId2;
	(temp->edgeInfo)->weight = edgeData->weight;
	
	if(*head == NULL) {
		*head = temp;		
		(*head)->next = NULL;
	}
	else {
		temp->next = *head;
		*head = temp;
	}
	return 0;
}


/*Return the node of the linked list containing the key. If not found, return NULL*/
struct Vertex * llGetVertex(struct llVertexNode *head,char *vertexName) {
    if (head == NULL)
        return NULL;
	struct llVertexNode *temp = head;
	while (temp != NULL) {
	    if (strcmp((temp->vertexInfo)->vertexName, vertexName) != 0)
			temp = temp->next;
		else
		    return temp->vertexInfo;
	}
	return NULL;
}


/*Insert the Vertex in linked list. Return 0 on success and -1 on failure*/
int llVertexInsert(struct llVertexNode **head,struct Vertex *vertexData) {
	//Assumes the vertex is not already present
	struct llVertexNode *temp = (struct llVertexNode *)malloc(sizeof(struct llVertexNode));
	temp->vertexInfo = (struct Vertex *)malloc(sizeof(struct Vertex));
	strcpy((temp->vertexInfo)->vertexName, vertexData->vertexName);
	(temp->vertexInfo)->vertexId = vertexData->vertexId;	
	if(*head == NULL) {
		*head= temp;
		(*head)->next = NULL;
	}
	else {
		temp->next = *head;
		*head = temp;
	}
	return 0;
}


