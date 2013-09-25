#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//struct Edge *edges;
#define BUFLEN 200

int parseInputDescription(char *inputFileName, struct vertexHashTable *vertexHash, struct edgeHashTable *edgeHash) {
	char numbers[] = "0123456789";
	
	
	//READING FILE LINE-BY-LINE
	char line[BUFLEN];
	FILE *fp = fopen(inputFileName, "r");
	if(fgetc(fp) == EOF) {
	    printf("Error...File is empty!\n");
	    exit(1);
	}    
	fgets(line, 30, fp);
	//printf("%s \n",line);
	if (strchr(line, ':') != NULL) {
	    if (strcspn(numbers, line) >6) {
	        printf("Error...value of num_vertices missing!\n");
	        exit(1);
	    }    
	}
	else {
	  printf("Error...whole line of num_vertices field missing!\n");
	  exit(1);  
	}
	    
	char *a = strtok(line, ": ");
	a = strtok(NULL,": ");
	//printf("%s \n", a);
	numVertices = atoi(a);
	printf("\nNumber of vertices: %d \n\n", numVertices);
	int j;
	vertices= (char **)malloc(sizeof(char *)*numVertices);
	for(j = 0;j < numVertices; j++)
	    vertices[j] = (char *)malloc(30);
	int i = 0;
	struct Vertex *vertex = (struct Vertex *)malloc(sizeof(struct Vertex));
	struct Edge *edge = (struct Edge *)malloc(sizeof(struct Edge));
	//First line has been read
	
	
	//READING FROM SECOND TO SECOND LAST LINE, FILLING HASH TABLES
	int flag1 = 0, flag2 = 0, flag3 = 0;
	while (1) {
		fgets(line, 30, fp);
		//printf("hello!\n");
		
		if (strchr(line, ':') != NULL) {
		        flag3 = 1;
		        if (strcspn(numbers, line) >6) {
		            flag1 = 1;
			        break;
			    }   
			    else
			        break; 
		}	
	    if (fgetc(fp) == EOF) {
	        flag2 = 1;
	        break;
	    }    
		char *s = strtok(line, "( )");
		//printf("%s \n", s);
		strcpy(vertex->vertexName, s);
		vertex->vertexId = i;
		//edge->vertexId1 = i;
		int res = vertexHashInsert(vertexHash, vertex);
		if (res == 0) {
		    //printf("Successfully inserted above vertex\n");
		    strcpy(vertices[i], s);
		    i++;
		}
		edge->vertexId1 = getVertexId(vertexHash, vertex->vertexName);    
		s = strtok(NULL, "( )");
		//printf("Hey this is second vertex! %s\n",s);
		if (strspn(s, numbers) != 0) {
		    printf("A vertex name is missing in type A field!\n");
		    exit(1);
		}
		    
		//printf("%s \n", s);
		//strcpy(vertices[i], s);
		strcpy(vertex->vertexName, s);
		vertex->vertexId = i;
		res = vertexHashInsert(vertexHash, vertex);
		//edge->vertexId2 = i;
		if (res == 0) {
		    //printf("Successfully inserted above vertex\n");
		    strcpy(vertices[i], s);
		    i++;
		}  
		edge->vertexId2 = getVertexId(vertexHash, vertex->vertexName);   
		s = strtok(NULL, "( )");
		//printf("Hey this is edge weight! %s\n",s);
		//if (strchr(line, ':') != NULL) {
	        if (strcspn(numbers, s) >= 10) {
	            printf("Error...weight of type A edge missing!\n");
	            exit(1);
	        }    
	    //}
	    //else {
	      //printf("Error...weight of type A edge missing!\n");
	      //exit(1);  
	   // }
		//if(strcspn(numbers, s) == 0) {
		   //printf("Weight of type A edge missing!\n"); 
		  // exit(1);
		//}
		//printf("%s \n", s);
		int w = atoi(s);
		//printf("Edge weight: %d",w);
		edge->weight = w;
		int t;
		if(edge->vertexId1 > edge->vertexId2) {
	        t = edge->vertexId1;
	        edge->vertexId1 = edge->vertexId2;
	        edge->vertexId2 = t;
	    }
		int r = edgeHashInsert(edgeHash, edge);
	}//end of while loop
	
	if((flag2) && (!flag3)) {
	    printf("Error...Whole line of Type B edge weight field missing!\n");
	    exit(1);
	}
	if((flag3) && (flag1)) {
	    printf("Error...value of Type B edge weight field missing!\n");
	    exit(1);
	}
	
	//FILLING THE "EDGES" ARRAY	
	edges = (struct Edge *)malloc((edgeHash->edge_count)*sizeof(struct Edge));
	int g = getArray(edgeHash, edges);
	
	int m, n;
	
	
	//PRINTING "EDGES" ARRAY
    
            printf("Printing edges array... \n");
	        if(edgeHash->edge_count != 0) {
	            
	            printf("\n \nEdges array: \n");
	            for(n = 0; n < edgeHash->edge_count; n++) {
	                printf("%s ", getVertexName(edges[n].vertexId1));    
	                //printf("%d ", edges[n].vertexId1);    
	                printf("%s ", getVertexName(edges[n].vertexId2));  
	                //printf("%d ", edges[n].vertexId2);      
	                printf("%d\n", edges[n].weight);
	            }
	            printf("Printing done! \n\n");
	            //fgets(line, 30, fp);
	       }
           else
                printf("\nIt is empty, there are no type A edges.\n");    
	
	//GETTING LAST LINE OF FILE, TYPE B VERTICES WEIGHT
	char *typeB = strtok(line, ": ");
	typeB = strtok(NULL,": ");
	//printf("Type B: %s\n",typeB);
	/*if(fgetc(fp) == EOF) {
	    printf("Error...weight missing in type B field!\n");
	    exit(1);
	
	}*/
	typeB = strtok(NULL,": ");
	//printf("Type B: %s\n",typeB);
	//if(strtok(NULL, ": ") == NULL) {
	//    printf("Error...weight missing in type B field!\n");
	 //   exit(1);
	//}
	    
	b_weight = atoi(typeB);
	printf("\nWeight of type B edges: %d\n",b_weight);
	printf("No. of type A vertices : %d\n", i);
	typeA = i;
	int no_b = numVertices - i;
	printf("No. of vertices left: %d\n\n", no_b);
	
	
	//CREATING NAMES FOR TYPE B VERTICES AND PRINTING
	char b[] = "vertexB_";
	for(m = 1, n = i; m <= no_b, n < numVertices ; m++, n++) 
		snprintf(vertices[n], 15, "%s%d", b, m);
		
	printf("Printing vertices array after adding type B vertices: \n");	
	for(m = 0; m < numVertices; m++) {
       printf("Vertex %d: ", m);
       puts(vertices[m]);
    }   
    
    printf("\nInserting Type B vertices in vertex hash tables... \n");
    int res;
    for(n = i; n < numVertices; n++) {
        strcpy(vertex->vertexName, vertices[n]);
        vertex->vertexId = n;
        res = vertexHashInsert(vertexHash, vertex);
    }
    
    printf("\nPrinting vertex hash table: \n");
    struct llVertexNode * temp;
    for(m = 0; m < MAXBUCKETS; m++) {
        if(vertexHash->buckets[m] != NULL) {
            temp = vertexHash->buckets[m];
            while(temp != NULL) {
                printf("%d  ", (temp->vertexInfo)->vertexId);
                puts((temp->vertexInfo)->vertexName);
                temp = temp->next;
            }
        }
    }       
    
    if(edgeHash->edge_count != 0) {
        printf("\nPrinting edge hash table: \n");
        struct llEdgeNode * temp1;
        for(m = 0; m < MAXBUCKETS; m++) {
            if(edgeHash->buckets[m] != NULL) {
                temp1 = edgeHash->buckets[m];
                while(temp1 != NULL) {
                    printf("%s  ", getVertexName((temp1->edgeInfo)->vertexId1));
                    printf("%s  ", getVertexName((temp1->edgeInfo)->vertexId2));
                    printf("%d\n", (temp1->edgeInfo)->weight);
                    temp1 = temp1->next;
                }
            }
        } 
     } 
} 
     



    
