#include "library.h"

// XuấtJ đỉnh ra màn hình
void printVertex(VERTEX v) { cout << v; }
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
  if (f == nullptr)
    return 0;
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
    if (mt.matrix[i][vertex] != 0)
      ++count;
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
  int minWei = INT_MAX;
  for (int i = 0; i < mt.num; i++) {
    if (i == verU)
      continue;
    if (mt.matrix[verU][i] != 0 && mt.matrix[verU][i] < minWei) {
      minWei = mt.matrix[verU][i];
      vertex = i;
    }
    if (mt.matrix[i][verU] != 0 && mt.matrix[i][verU] < minWei) {
      minWei = mt.matrix[i][verU];
      vertex = i;
    }
  }
  cout << "Dinh co trong so nho nhat la dinh " << vertex
       << " va co trong so la " << minWei;
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