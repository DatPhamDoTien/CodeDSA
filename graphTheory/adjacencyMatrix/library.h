#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
// Phân tích toàn bộ cấu trúc.
const int MAXV = 20;           // MAXVERTEX: số lượng đỉnh tối đa
const int MAXE = MAXV * MAXV;  // MAXEDGE: số lượng cạnh tối đa
typedef int VERTEX;
struct EDGE {          // Kiểu dữ liệu struct đại diện cho cạnh
  VERTEX origin;       // đỉnh bắt đầu
  VERTEX destination;  // đỉnh kết thúc
  int weight;          // trọng số
};
struct arrayVertex {  // Kiểu dữ liệu struct danh sách đỉnh
  VERTEX list[MAXV];  // array tên là list chứa đỉnh
  int count;          // Biến lưu số lượng đỉnh đã có trong danh sách
};
struct arrayEdge {  // Kiểu dữ liệu struct danh sách cạnh
  EDGE list[MAXE];  // array lưu cạnh, có kiểu dữ liệu là EDGE
  int count;        // biến lưu số lượng cạnh có trong danh sách
};
struct adjacencyMatrix {   // Ma trận kề
  int matrix[MAXV][MAXV];  // Kích thước ma trận
  int num;                 // Số lượng đỉnh trong đồ thị
};

void printVertex(VERTEX v);
void printArrayVertex(arrayVertex arr);
void printArrayEdge(arrayEdge arr);
int readFile(const char *fileName, adjacencyMatrix &mt);
int writeFile(const char *fileName, adjacencyMatrix &mt);
void printAdjacencyMatrix(adjacencyMatrix mt);
int calDegreeInDirected(adjacencyMatrix mt, VERTEX vertex);
arrayEdge direcredGraphEdge(adjacencyMatrix mt);
// bài tập tổng hợp.
// Bài 1
adjacencyMatrix initMatrix(adjacencyMatrix &mt, int numOfVertex);
adjacencyMatrix matrixDecoding(arrayEdge edges, int numOfVertex);
// bài 2
adjacencyMatrix matrixDecodingDeriectional(arrayEdge edges, int numOfVerTex);
// bài 3
VERTEX findLightestVertex(adjacencyMatrix mt, VERTEX verU);
// bài 4
adjacencyMatrix redirectMatrix(adjacencyMatrix &mt);
// Bài 5
arrayVertex breadthFirstSearch(adjacencyMatrix mt, VERTEX v);
// Bài 6
void DFSUtil(const adjacencyMatrix &mt, VERTEX v, bool visited[], arrayVertex &result);
arrayVertex depthFirstSearch(const adjacencyMatrix &mt, VERTEX start);

// 4/ Bài tập làm thêm:

arrayVertex BFS(adjacencyMatrix mt, VERTEX v);

void BFS_Traversal(adjacencyMatrix mt, VERTEX v, arrayVertex &arr, arrayEdge &edges);

void DFS_fullGraph(adjacencyMatrix mt, arrayVertex &av, arrayEdge &ae);

void depthFirstSearch(const adjacencyMatrix &mt, VERTEX v, bool visited[], arrayVertex &result);
arrayVertex DFS(adjacencyMatrix mt, VERTEX v);

void DFS_visitOrder(adjacencyMatrix mt, VERTEX v, arrayVertex &vertexes, arrayEdge &edges);
void DFS_recursive(const adjacencyMatrix &mt, VERTEX v, bool visited[], arrayVertex &vertexes, arrayEdge &edges);

bool checkGraphConnected(const adjacencyMatrix &mt);
bool checkStrongGraphConnected(const adjacencyMatrix &mt);
arrayVertex topoSort(adjacencyMatrix mt);