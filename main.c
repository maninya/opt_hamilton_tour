#include "main.h"

#define BUFLEN 200

extern int typeA;
extern int nexcludededges;
//extern struct spanningedge **minSpanningTreeEdges;
int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("Usage:\n\t%s <input-file>\n", argv[0]);
		exit(1);
	}
	struct vertexHashTable *vertexHash = (struct vertexHashTable *)malloc(sizeof(struct vertexHashTable));
	struct edgeHashTable *edgeHash = (struct edgeHashTable *)malloc(sizeof(struct edgeHashTable));
	vertexHashInit(vertexHash);
	edgeHashInit(edgeHash);
	parseInputDescription(argv[1], vertexHash, edgeHash);	
	//printf("Edge_count: %d\n",edgeHash->edge_count);
	if(edgeHash->edge_count != 0) {
	    int a = heapsort(edges, edgeHash->edge_count);
	    int n;
	    //printf("edgeHash->edge_count: %d\n", edgeHash->edge_count);
	    //printf("NumEdges: %d\n", numEdges);
	    
    }
    int c = checkTriangleInequality(edges, edgeHash);
    //printf("\n C: %d",c);
	if(c == 0)
		printf("\nTriangle inequality satisfied.\n");
	else
		printf("\nTriangle inequality not satisfied.\n");
		
	struct Edge *excludededges;	
    struct spanningedge **minSpanningTreeEdges,*temp1;
		
    if (NULL == (minSpanningTreeEdges=(struct spanningedge **)(malloc((numVertices)*sizeof(struct spanningedge*))))) {
        printf("\nmalloc cannot be done!");
	}
	int i, count, n = 1;
	int flag; 
	//printf("\nnexcludededges: %d\n",nexcludededges);
	excludededges=(struct Edge *)(malloc((numEdges)*sizeof(struct Edge)));
	flag=buildMinSpanningTree(edges,minSpanningTreeEdges,excludededges);
	//printf("%s\t%s\t%d\n",getVertexName(excludededges[i].vertexId1),getVertexName(excludededges[i].vertexId2),excludededges[i].weight);
	
		
	printf("\n...............Minimum Spanning Tree Edges................\n\n");
	if(flag == 0)
	{	
		printf("Minimum Spanning Tree could not be constructed!\n");
	    if(typeA == 0) {
	        printf("There are no type A edges.\n");
	        exit(1);
	    }
		printf("\nThe connected components are:\n");
		for(i=0;i<numVertices;i++)
		{	
			count=0;
			temp1=minSpanningTreeEdges[i];
			while(temp1!=NULL)
			{	
				if(count==0)
				{	printf("\nComponent %d:\n",n++);
				}
		
				printf("%s\t%s\t%d\n",vertices[temp1->edge.vertexId1],vertices[temp1->edge.vertexId2],temp1->edge.weight);
				temp1=temp1->next;count++;
			}
		}
		
	}
	else 
	{	
	    printf("Minimum spanning tree constructed.\n");
	    printf("Cost of the minimum spanning tree is: %d\n",sweight);
	    temp1=minSpanningTreeEdges[flag];
		while(temp1!=NULL)
		{
		    printf("%s\t%s\t%d\n",vertices[temp1->edge.vertexId1],vertices[temp1->edge.vertexId2],temp1->edge.weight);
			temp1=temp1->next;
		}
		//nexcludededges=numEdges-numVertices+1;
		//printf("\nnexcludededges: %d\n",nexcludededges);
	    if(nexcludededges <= 0) {
		    printf("\nNo edges excluded from MST\n");
		    exit(1);
		}
		printf("\nExcluded edges are:\n");
		int m;
		for(m=0;m<nexcludededges;m++)
		    printf("%s\t%s\t%d\n",getVertexName(excludededges[m].vertexId1),getVertexName(excludededges[m].vertexId2),excludededges[m].weight);
		
	}
	/*int flag = buildMinSpanningTree(edges, minSpanningTreeEdges, edgeHash->edge_count);
	printf ("\n...............spanning tree edges................\n");
	for (i = 0; i < numVertices; i++) {
		count = 0;
		temp1 = minSpanningTreeEdges[i];
		while (temp1 != NULL) {	
			if(count == 0)
			    printf("component %d\n",n++);		
			printf("%s\t%s\t%d\n",vertices[temp1->edge.vertexId1],vertices[temp1->edge.vertexId2],temp1->edge.weight);
			temp1=temp1->next;count++;
		}
	}
		
	//struct Edge minSpanningTreeEdges=(struct spanningedge **)(malloc((numAVertices+1)*sizeof(struct spanningedge*)	
  //  minSpanningTreeEdges = (struct spanningedge **)(malloc((numVertices)*sizeof(struct spanningedge*)));	
	//int min = buildMinSpanningTree(edges, minSpanningTreeEdges);	
	/*if(min == 0)
		printf("\nMinimum spanning tree exists!\n");
	else
		printf("\nMinimum spanning tree does not exist!\n");*/
	return 0;
}


