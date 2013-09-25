#ifndef GRAPH_H
#define GRAPH_H

struct Vertex
{
	char vertexName[30];
	int vertexId;
};


//structure for edge
struct Edge
{
	int vertexId1;
	int vertexId2;
	int weight;
};

#include "vertices.h"
#include "hash.h"

struct Edge *edges;
//edges = (struct Edge *)malloc((edgeHash->edge_count)*sizeof(struct Edge));

//extern struct Edge *edges;
int numVertices;
int numEdges;
int b_weight;
int typeA;

/*Read the given file and parse the given input description. 

  Read the number of vertices, initialize 'numVertices' and allocate appropriate array space dynamically. 
  Allocate size of vertex name as 30 characters.

  Initialize edgeHashTable and vertexHashTable

  Extract Type A edges - Get the vertex name1, calculate hash value and check if it is already existing in    
  vertexHashTable. If vertex name doesn't exists, increment the index and insert into vertexHashTable and 
  insert into 'vertices' array at index position. Repeat the same for vertex name 2.
 
  Get the vertex ids and insert 'edge' in edgeHashTable.
  Return 0 on success and -1 on failure*/

struct edgeHashTable;

int parseInputDescription(char *inputFileName,
					 	  struct vertexHashTable *vertexHash,
						  struct edgeHashTable *edgeHash); 

#endif











