#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <thread>
#include <vector>
#include<chrono>
#include<mutex>
using namespace std;

const int MAXV = 15;          // so dinh toi da
const int MAXE = MAXV * MAXV; // so canh toi da
struct NODE {
  int adjacentVertex;
  int weight = 0;
  NODE* next;
};

struct AdjacencyList {
  NODE* list[MAXV];
  int count = 0;
};

struct EDGE {
  int from;
  int to;
  int weight = 0;
};

struct EdgeList {
  EDGE list[MAXE];
  int count = 0;
};

int readFile(const char* fileName, AdjacencyList& list, int flag);
int countNode(NODE* node);
int writeFile(const char* fileName, AdjacencyList& list, int flag);
void deleteAdjacencyList(AdjacencyList& list);
void printAdjacencyList(const AdjacencyList& list);
EdgeList takeListOfEdge(AdjacencyList list);
void printEdge(EDGE edge);
int calcutaleInDegrees(AdjacencyList list, int vertex);
void DowLoad(int index);
void countDowload();
//Bai 1
