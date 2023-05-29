#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex{
    char place[10];
}Vertex;

typedef struct Edge{
    Vertex* moto;
    Vertex* saki;
    int weight;
}Edge;

typedef struct Graph{
    Vertex** verList;
    Edge** edList;
    int verNum;
    int edNum;
}Graph;

Graph* createGraph(int verNum){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->verList = (Vertex**)malloc(verNum*sizeof(Vertex*));
    graph->edList = (Edge**)malloc(verNum*verNum*sizeof(Edge*));
    graph->verNum = verNum;
    graph->edNum = verNum*2;
}

