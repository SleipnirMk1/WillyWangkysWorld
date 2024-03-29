#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "boolean.h"
#include "../point/point.h"

#define Nil -1

#define MAXVERTEX 40
#define MAXEDGE 40

#define VertexG(G, i) (G).V[(i)]
#define EdgeG(G, i) (G).E[(i)]
#define NbVertex(G) (G).NbVertex
#define NbEdge(G) (G).NbEdge
#define V1Edge(G, i) (G).E[(i)].V1
#define V2Edge(G, i) (G).E[(i)].V2

// #define Area(V) (V).Area
// #define PosX(V) (V).x
// #define PosY(V) (V).y

typedef POINT Vertex;

typedef struct 
{
	Vertex V1;
	Vertex V2;
} Edge;

typedef struct 
{
	Vertex V[MAXVERTEX];
	Edge E[MAXEDGE];
	int NbVertex;
	int NbEdge;
} Graph;



boolean IsEmptyGraph(Graph G);

boolean IsFullEdge(Graph G);

boolean IsFullVertex(Graph G);

boolean IsExistEdge(Graph G, Edge E);


boolean IsExistVertex(Graph G, Vertex V);

void CreateEmpty(Graph *G);

Edge CreateEdge(Vertex V1, Vertex V2);
// V1 merupakan nomor area yang lebih kecil, sedangkan
// V2 merupakan nomor area yang lebih besar

Vertex CreateVertex(int area, float x, float y);

void AddEdge(Graph *G, Edge E);
// Edge *G tidak penuh

void AddVertex(Graph *G, Vertex V);
// V tidak ada di dalam *G sebelumnya

void GetVEdge(Graph G, Vertex V1, Vertex *V2);
// Mengambil Vertex pasangan dari V1 yang membentuk sebuah edge
// V1 pasti merupakan salah satu pasangan edge


boolean IsEQVertex(Vertex V1, Vertex V2);

boolean IsEQEdge(Edge E1, Edge E2);


void PrintVertex(Vertex V);

void PrintEdge(Edge E);

void PrintGraph(Graph G);



#endif