#include "library.h"

// XuấtJ đỉnh ra màn hình
void printVertex(VERTEX v) {
  cout << v;
}
// Xuất cạnh e ra màn hình
void printEdge(EDGE e) {
  cout << "(" << e.origin << ", " << e.destination << ")";
}

// Xuất danh sách đỉnh ra màn hình
void printArrayVertex(arrayVertex arr) {
  for (int i = 0; i < arr.count; i++) {
    cout << "\t";
    printVertex(arr.list[i]);

  }
}

void printArrayEdge(arrayEdge arr) {
  for (int i = 0; i < arr.count; i++) {
    cout << "\t";
    printEdge(arr.list[i]);
  }
}

// Đọc một ma trận kề từ file văn bản.
int readFile(const char *fileName, adjacencyMatrix &mt) {
  FILE *f = fopen(fileName, "rt");
  if (f == nullptr) return 0;
  fscanf(f, "%d", &mt.num);
  for (int i = 0; i < mt.num; i++) {
    for (int j = 0; j < mt.num; j++) {
      fscanf(f, "%d", &mt.matrix[i][j]);
    }
  }
  fclose(f);
  return 1;
}
// Ghi file ma trận kề lên file văn bản
int writeFile(const char *fileName, adjacencyMatrix &mt) {
  FILE *f = fopen(fileName, "wt");
  if (f == nullptr) {
    cout << "\nKhong the mo file";
    return 0;
  }
  fprintf(f, "%d", mt.num);
  for (int i = 0; i < mt.num; i++) {
    fprintf(f, "\n");
    for (int j = 0; j < mt.num; j++) {
      fprintf(f, "%d\t", mt.matrix[i][j]);
    }
  }
  fclose(f);
  return 1;
}

// Xuất ma trận kề ra màn hình
void printAdjacencyMatrix(adjacencyMatrix mt) {
  cout << "Gia tri trong file la: ";
  cout << "\n" << mt.num << "\n";
  for (int i = 0; i < mt.num; i++) {
    cout << "|  ";
    for (int j = 0; j < mt.num; j++) {
      cout << mt.matrix[i][j] << "  |  ";
    }
    cout << endl << endl;
  }
}

// Hàm tính bậc vào của đỉnh trong đồ thị có hướng
int calDegreeInDirected(adjacencyMatrix mt, int vertex) {
  int count = 0;
  for (int i = 0; i < mt.num; i++) {
    if (mt.matrix[i][vertex] != 0) ++count;
  }
  return count;
}

// Hàm trả về tập cạnh của đồ thị có hướng
arrayEdge direcredGraphEdge(adjacencyMatrix mt) {
  arrayEdge edges;
  edges.count = 0;
  for (int i = 0; i < mt.num; i++) {
    for (int j = 0; j < mt.num; j++) {
      if (mt.matrix[i][j] != 0) {
        EDGE e;
        e.origin = i;
        e.destination = j;
        e.weight = mt.matrix[i][j];
        edges.list[edges.count++] = e;
      }
    }
  }
  return edges;
}

adjacencyMatrix initMatrix(adjacencyMatrix &mt, int numOfVertex) {
  for (int i = 0; i < numOfVertex; i++) {
    for (int j = 0; j < numOfVertex; j++) {
      mt.matrix[i][j] = 0;
    }
  }
  return mt;
}
// 1) Cho số đỉnh và tập cạnh của đồ thị vô hướng. Viết hàm trả về ma trận kề
// của đồ thị.
adjacencyMatrix matrixDecoding(arrayEdge edges, int numOfVertex) {
  adjacencyMatrix mt;
  mt.num = numOfVertex;
  initMatrix(mt, mt.num);
  for (int i = 0; i < edges.count; i++) {
    int org = edges.list[i].origin;
    int des = edges.list[i].destination;
    int wei = edges.list[i].weight;
    mt.matrix[org][des] = wei;
    mt.matrix[des][org] = wei;
  }
  return mt;
}

// 2) Cho số đỉnh và tập cạnh của đồ thị có hướng. Viết hàm trả về ma trận kề
// của đồ thị.

adjacencyMatrix matrixDecodingDeriectional(arrayEdge edges, int numOfVerTex) {
  adjacencyMatrix mt;
  mt.num = numOfVerTex;
  initMatrix(mt, mt.num);
  for (int i = 0; i < edges.count; i++) {
    int org = edges.list[i].origin;
    int des = edges.list[i].destination;
    int wei = edges.list[i].weight;
    mt.matrix[org][des] = wei;
  }
  return mt;
}

// 3) Cho đồ thị trọng số biểu diễn bằng ma trận kề. Viết hàm tìm một đỉnh kề
// với đỉnh u mà có trọng số nhỏ nhất.
// => Trong bài này tôi hướng tới tìm trong ma trận đồ thị có hướng
VERTEX findLightestVertex(adjacencyMatrix mt, VERTEX verU) {
  if (mt.num == 0) {
    cout << "\nMa tran rong!" << endl;
    return 0;
  }
  VERTEX vertex;
  int minWei = 9999999;
  for (int i = 0; i < mt.num; i++) {
    if (i == verU) continue;
    if (mt.matrix[verU][i] != 0 && mt.matrix[verU][i] < minWei) {
      minWei = mt.matrix[verU][i];
      vertex = i;
    }
    if (mt.matrix[i][verU] != 0 && mt.matrix[i][verU] < minWei) {
      minWei = mt.matrix[i][verU];
      vertex = i;
    }
  }
  cout << "Dinh co trong so nho nhat la dinh " << vertex << " va co trong so la " << minWei;
  return vertex;
}

// 4) Đồ thị có hướng G’ được xây dựng từ đồ thị có hướng G bằng cách đổi hướng
// tất cả các cạnh của đồ thị G. Cho ma trận kề của đồ thị G, viết hàm trả về ma
// trận kề của đồ thị G’.
adjacencyMatrix redirectMatrix(adjacencyMatrix &mt) {
  for (int i = 0; i < mt.num; i++) {
    for (int j = i + 1; j < mt.num; j++) {
      swap(mt.matrix[i][j], mt.matrix[j][i]);
    }
  }
  return mt;
}

// 5) Cho ma trận kề của đồ thị. Viết hàm duyệt đồ thị theo chiều rộng (BFS) với
// đỉnh xuất phát v và xuất ra màn hình thứ tự các đỉnh duyệt được.
arrayVertex breadthFirstSearch(adjacencyMatrix mt, VERTEX v) {
  arrayVertex arr;
  if (v < 0 || v >= mt.num) {
    cout << "\nDinh khong hop le!";
    return arr;
  }
  arr.count = 0;
  queue<int> listOfVer;
  bool visited[MAXV] = {false};
  listOfVer.push(v);
  visited[v] = true;
  while (!listOfVer.empty()) {
    VERTEX current = listOfVer.front();
    listOfVer.pop();
    if (arr.count < MAXV) {
      arr.list[arr.count++] = current;
    }
    for (int i = 0; i < mt.num; i++) {
      if (mt.matrix[current][i] != 0 && !visited[i]) {
        listOfVer.push(i);
        visited[i] = true;
      }
    }
  }
  return arr;
}

// 6) Cho ma trận kề của đồ thị. Viết hàm duyệt đồ thị theo chiều sâu (DFS) với
// đỉnh xuất phát v và xuất ra màn hình thứ tự các đỉnh duyệt được.

void DFSUtil(const adjacencyMatrix &mt, VERTEX v, bool visited[], arrayVertex &result) {
  visited[v] = true;
  result.list[result.count++] = v;
  for (int i = 0; i < mt.num; i++) {
    if (mt.matrix[v][i] != 0 && !visited[i]) {
      DFSUtil(mt, i, visited, result);
    }
  }
}
arrayVertex depthFirstSearch(const adjacencyMatrix &mt, VERTEX start) {
  bool visited[MAXV] = {false};
  arrayVertex result;
  result.count = 0;
  DFSUtil(mt, start, visited, result);
  return result;
}

// 4/ Bài tập làm thêm:
//  1) Cho ma trận kề của đồ thị. Viết hàm duyệt đồ thị theo chiều rộng (BFS) và
//  xuất ra màn hình thứ tự các đỉnh duyệt được.
arrayVertex BFS(adjacencyMatrix mt, VERTEX v) {
  arrayVertex arr;
  if (v < 0 || v > mt.num) {
    cout << "Dinh khong hop le";
    return arr;
  }
  arr.count = 0;
  queue<int> listOfver;
  bool visited[MAXV] = {false};
  listOfver.push(v);
  visited[v] = true;
  while (!listOfver.empty()) {
    VERTEX current = listOfver.front();
    listOfver.pop();
    if (arr.count < MAXV) {
      arr.list[arr.count++] = current;
    }
    for (int i = 0; i < mt.num; i++) {
      if (mt.matrix[current][i] != 0 && !visited[i]) {
        listOfver.push(i);
        visited[i] = true;
      }
    }
  }
  return arr;
}

// 2) Cho ma trận kề của đồ thị. Viết hàm duyệt đồ thị theo chiều rộng (BFS) với
// đỉnh xuất phát là v. Thứ tự các đỉnh viếng thăm chứa vào tập đỉnh av và thứ
// tự các cạnh viếng thăm chứa vào chứa vào tập cạnh ae.
void BFS_Traversal(adjacencyMatrix mt, VERTEX v, arrayVertex &arr, arrayEdge &edges) {
  if (v < 0 || v > mt.num) {
    cout << "Dinh khong hop le";
    return;
  }
  edges.count = 0;
  queue<int> listOfVer;
  bool visited[MAXV] = {false};
  listOfVer.push(v);
  visited[v] = true;
  while (!listOfVer.empty()) {
    VERTEX current = listOfVer.front();
    listOfVer.pop();
    if (arr.count < MAXV) {
      arr.list[arr.count++] = current;
    }
    for (int i = 0; i < mt.num; i++) {
      if (mt.matrix[current][i] != 0 && !visited[i]) {
        listOfVer.push(i);
        visited[i] = true;
        edges.list[i].origin = current;
        edges.list[i].destination = i;
        edges.list[i].weight = mt.matrix[current][i];
        edges.count++;
      }
    }
  }
}

// 3) Cho ma trận kề của đồ thị. Viết hàm duyệt đồ thị theo chiều rộng (BFS).
// Thứ tự các đỉnh viếng thăm chứa vào tập đỉnh av và thứ tự các cạnh viếng thăm
// chứa vào chứa vào tập cạnh ae.
void BFS_fullGraph(adjacencyMatrix mt, arrayVertex &av, arrayEdge &ae) {
  bool visited[MAXV] = {false};
  av.count = 0;
  ae.count = 0;
  for (int i = 0; i < mt.num; i++) {
    if (!visited[i]) {
      BFS_Traversal(mt, i, av, ae);
    }
  }
}

// 4) Cho ma trận kề của đồ thị. Viết hàm duyệt đồ thị theo chiều sâu (DFS) và
// xuất ra màn hình thứ tự các đỉnh duyệt được.

void depthFirstSearch(const adjacencyMatrix &mt, VERTEX v, bool visited[], arrayVertex &result) {
  visited[v] = true;
  result.list[result.count++] = v;
  for (int i = 0; i < mt.num; i++) {
    if (mt.matrix[v][i] != 0 && !visited[i]) {
      depthFirstSearch(mt, i, visited, result);
    }
  }
}

arrayVertex DFS(adjacencyMatrix mt, VERTEX v) {
  bool vistited[MAXV] = {false};
  arrayVertex arr;
  arr.count = 0;
  depthFirstSearch(mt, v, vistited, arr);
  return arr;
}

// 5) Cho ma trận kề của đồ thị. Viết hàm duyệt đồ thị theo chiều sâu (DFS) với
// đỉnh xuất phát là v. Thứ tự các đỉnh viếng thăm chứa vào tập đỉnh av và thứ
// tự các cạnh viếng thăm chứa vào chứa vào tập cạnh ae.
void DFS_visitOrder(adjacencyMatrix mt, VERTEX v, arrayVertex &vertexes, arrayEdge &edges) {
  if (v < 0 || v >= mt.num) {
    cout << "Dinh khong hop le";
    return;
  }
  bool visited[MAXV] = {false};
  vertexes.count = 0;
  edges.count = 0;
  DFS_recursive(mt, v, visited, vertexes, edges);
}
void DFS_recursive(const adjacencyMatrix &mt, VERTEX v, bool visited[], arrayVertex &vertexes, arrayEdge &edges) {
  visited[v] = true;
  if (vertexes.count < MAXV) vertexes.list[vertexes.count++] = v;
  for (int i = 0; i < mt.num; i++) {
    if (mt.matrix[v][i] != 0 && !visited[i]) {
      if (edges.count < MAXE) {
        edges.list[edges.count].origin = v;
        edges.list[edges.count].destination = i;
        edges.list[edges.count].weight = mt.matrix[v][i];
        edges.count++;
      }
      DFS_recursive(mt, i, visited, vertexes, edges);
    }
  }
}

// 6) Cho ma trận kề của đồ thị. Viết hàm duyệt đồ thị theo chiều sâu (DFS). Thứ tự các
// đỉnh viếng thăm chứa vào tập đỉnh av và thứ tự các cạnh viếng thăm chứa vào chứa
// vào tập cạnh ae.

void DFS_fullGraph(adjacencyMatrix mt, arrayVertex &av, arrayEdge &ae) {
  bool visited[MAXV] = {false};
  av.count = 0;
  ae.count = 0;
  for (int v = 0; v < mt.num; ++v) {
    if (!visited[v]) {
      DFS_recursive(mt, v, visited, av, ae);
    }
  }
}

// 7) Cho ma trận kề của đồ thị vô hướng. Viết hàm trả về một số nguyên là số thành
// phần liên thông của đồ thị.
bool checkGraphConnected(const adjacencyMatrix &mt) {
  bool visited[MAXV] = {false};
  arrayVertex arr;
  arr.count = 0;
  for (int i = 0; i < mt.num; i++) {
    if (!visited[i]) {
      depthFirstSearch(mt, i, visited, arr);
    }
  }
  return arr.count == mt.num ? true : false;
}

// 8) Cho danh sách kề của đồ thị có hướng. Viết hàm kiểm tra đồ thị có liên thông mạnh hay không.
bool checkStrongGraphConnected(const adjacencyMatrix &mt) {
  bool strongConnected = true;
  for (int start = 0; start < mt.num; ++start) {
    arrayVertex arr;
    bool visited[MAXV] = {false};
    arr.count = 0;
    depthFirstSearch(mt, start, visited, arr);
    if(arr.count < mt.num){
      strongConnected = false;
      break;
    }
  }
  return strongConnected;
}
