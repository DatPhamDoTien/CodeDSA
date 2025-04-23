#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//MAXV: số đỉnh tối đa
const int MAXV = 20;

//MAXE: số cạnh tối đa
const int MAXE = MAXV * MAXV;

//VERTEX: kiểu của một đỉnh
typedef int VERTEX;

//EDGE: kiểu của một cạnh
struct EDGE{
	VERTEX org; //origin
	VERTEX des; //destination
	int wei;	//weight
};

//Array vertex
struct arrayVertex{
	VERTEX list[MAXV];
	int count;
};

//ArrayEdge
struct ArrayEdge{
	EDGE list[MAXE];
	int count;
};
//Ma trận kề của đồ thị (Adjacency-matrix)
struct AdjacencyMatrix{
	int matrix[MAXV][MAXV];
	int n;
};





