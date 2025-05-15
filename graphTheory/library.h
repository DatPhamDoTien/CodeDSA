
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

const int MAXV = 20;
const int MAXE = MAXV * MAXV;
typedef int VERTEX;
struct EDGE {
  VERTEX origin;
  VERTEX destination;
  int weight;
};
struct arrayVertex {
  VERTEX list[MAXV];
  int count;
};
struct arrayEdge {
  EDGE list[MAXE];
  int count;
};
struct adjacencyMatrix {
  int matrix[MAXV][MAXV];
  int num;
};

void printVertex(VERTEX v);
void printArrayVertex(arrayVertex arr);
void printArrayEdge(arrayEdge arr);
int readFile(const char *fileName, adjacencyMatrix& mt);
int writeFile(const char *fileName, adjacencyMatrix& mt);
void printAdjacencyMatrix(adjacencyMatrix mt);
int calDegreeInDirected(adjacencyMatrix mt, int vertex);
arrayEdge direcredGraphEdge(adjacencyMatrix mt);
