#include <stdio.h>
#include "boolean.h"
#include "graph.h"

// #define Nil -1

// #define MAXVERTEX 40
// #define MAXEDGE 40

// #define VertexG(G, i) (G).V[(i)]
// #define EdgeG(G, i) (G).E[(i)]
// #define NbVertex(G) (G).NbVertex
// #define NbEdge(G) (G).NbEdge
// #define V1Edge(G, i) (G).E[(i)].V1
// #define V2Edge(G, i) (G).E[(i)].V2

// #define Area(V) (V).Area
// #define Pos(V) (V).Pos

// typedef struct 
// {
// 	int x;
// 	int y;
// } Point;

// typedef struct 
// {
// 	Point Pos;
// 	int Area;
// } Vertex;

// typedef struct 
// {
// 	Vertex V1;
// 	Vertex V2;
// } Edge;

// typedef struct 
// {
// 	Vertex V[MAXVERTEX];
// 	Edge E[MAXEDGE];
// 	int NbVertex;
// 	int NbEdge;
// } Graph;



boolean IsEmpty(Graph G)
{
	return NbVertex(G) == 0;
}

boolean IsFullEdge(Graph G)
{
	return NbEdge(G) == MAXEDGE;
} 

boolean IsFullVertex(Graph G)
{
	return NbVertex(G) == MAXVERTEX;
}

boolean IsExistEdge(Graph G, Edge E)
{
	boolean found = false;
	int i = 0;
	while(i < NbEdge(G) && !found)
	{
		if (IsEQEdge(EdgeG(G, i), E))
			found = true;
		else
			i++;
	}

	return found;
}


boolean IsExistVertex(Graph G, Vertex V)
{
	boolean found = false;
	int i = 0;
	while(i < NbVertex(G) && !found)
	{
		if (IsEQVertex(VertexG(G, i), V))
			found = true;
		else
			i++;
	}

	return found;
}

boolean IsEQVertex(Vertex V1, Vertex V2)
{
	return Area(V1) == Area(V2) && Absis(V1) == Absis(V2) && Ordinat(V1) == Ordinat(V2);
}

boolean IsEQEdge(Edge E1, Edge E2)
{
	return IsEQVertex(E1.V1, E2.V1) && IsEQVertex(E1.V2, E2.V2);
}

void CreateEmpty(Graph *G)
{
	NbVertex(*G) = 0;
	NbEdge(*G) = 0;
}

Edge CreateEdge(Vertex V1, Vertex V2)
// V1 merupakan nomor area yang lebih kecil, sedangkan
// V2 merupakan nomor area yang lebih besar
{
	Edge E;
	if (Area(V1) < Area(V2))
	{
		E.V1 = V1;
		E.V2 = V2;
	}
	else
	{
		E.V1 = V2;
		E.V2 = V1;
	}

	return E;
}

Vertex CreateVertex(int area, float x, float y)
{
	Vertex V;
	Area(V) = area;
	Absis(V) = x;
	Ordinat(V) = y;

	return V;
}

void AddEdge(Graph *G, Edge E)
// Edge *G tidak penuh
{
	if (!IsExistEdge(*G, E))
	{
		EdgeG(*G, NbEdge(*G)) = E;
		NbEdge(*G) += 1;

		if (!IsExistVertex(*G, E.V1))
			AddVertex(G, E.V1);

		if (!IsExistVertex(*G, E.V2))
			AddVertex(G, E.V2);
	}
}

void AddVertex(Graph *G, Vertex V)
// V tidak ada di dalam *G sebelumnya
{
	VertexG(*G, NbVertex(*G)) = V;
	NbVertex(*G) += 1;
}


void GetVEdge(Graph G, Vertex V1, Vertex *V2)
// Mengambil Vertex pasangan dari V1 yang membentuk sebuah edge
// V1 pasti merupakan salah satu pasangan edge
{
	boolean found = false;
	int i = 0;
	while(i < NbEdge(G) && !found)
	{
		if (IsEQVertex(V1Edge(G, i), V1))
		{
			found = true;
			*V2 = V2Edge(G, i);
		}
		else if (IsEQVertex(V2Edge(G, i), V1))
		{
			found = true;
			*V2 = V1Edge(G, i);
		}
		else
		{
			i++;
		}
	}
}

void PrintVertex(Vertex V)
{
	printf("<%.2f,%.2f,%.2f>", Area(V), Absis(V), Ordinat(V));
}

void PrintEdge(Edge E)
{
	PrintVertex(E.V1);
	printf(" ");
	PrintVertex(E.V2);
}

void PrintGraph(Graph G)
{
	for (int i = 0; i < NbVertex(G); ++i)
	{
		PrintVertex(VertexG(G, i));
		printf("\n");
	}

	for (int i = 0; i < NbEdge(G); ++i)
	{
		PrintEdge(EdgeG(G, i));

		if (i != NbEdge(G)-1)
			printf("\n");
	}
}


