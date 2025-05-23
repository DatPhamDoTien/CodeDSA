#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
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
//bài tập tổng hợp.
//Bài 1
adjacencyMatrix initMatrix(adjacencyMatrix& mt, int numOfVertex);
adjacencyMatrix matrixDecoding(arrayEdge edges, int numOfVertex);
//bài 2
adjacencyMatrix matrixDecodingDeriectional(arrayEdge edges, int numOfVerTex);
//bài 3
VERTEX findLightestVertex(adjacencyMatrix mt, VERTEX verU);
//bài 4
adjacencyMatrix redirectMatrix(adjacencyMatrix& mt);
//Bài 5
arrayVertex breadthFirstSearch(adjacencyMatrix mt, VERTEX v);