#include "library.h"
#include <cstdio>
#include <stdio.h>

void printVertex(VERTEX ver) { cout << ver; }

// Xuất cạnh e ra màn hình
void printEdge(EDGE e) { cout << "(" << e.org << ", " << e.des << ")"; }
// Xuất danh sách đỉnh ra màn hình
void printArrayVertex(arrayVertex av) {
  for (int i = 0; i < av.count; i++) {
    printVertex(av.list[i]);
    cout << "\t";
  }
}
// Xuất danh sách cạnh ra màn hình
void printArrayEdge(ArrayEdge ae) {
  for (int i = 0; i < ae.count; i++) {
    printEdge(ae.list[i]);
    cout << "\t";
  }
}
// Đọc file từ văn bản
int read(char *fileName, AdjacencyMatrix &g) {
  FILE *f;
  fopen_s(&f, fileName, "rt");
  if (f == NULL) {
    return 0;
  }
  fscanf_s(f, "%d", &g.n);
  for (int i = 0; i < g.n; i++) {
    for (int j = 0; j < g.n; j++)
      fscanf_s(f, "%d", &g.matrix[i][j]);
  }
  fclose(f);
  return 1;
}

// Ghi ma trận kề vào file text
int write(char *fileName, AdjacencyMatrix g) {
  FILE *f;
  fopen_s(&f, fileName, "wt");
  if (f == NULL) {
    return 0;
  }
  fprintf(f, "%d", g.n);
  for (int i = 0; i < g.n; i++) {
    for (int j = 0; i < g.n; j++)
      fprintf(f, "%d\t", g.matrix[i][j]);
  }
  fclose(f);
  return 1;
}

void printAdjacencyMaTrix(AdjacencyMatrix g) {
  cout << "\nGia tri trong file la:";
  cout << "\n" << g.n << "\n";
  for (int i = 0; i < g.n; i++) {
    for (int j = 0; j < g.n; j++)
      cout << g.matrix[i][j] << " ";
    cout << "\n";
  }
}

// Tính bậc vào của đồ thị có hướng
int calculatorInDegress(AdjacencyMatrix g, int vertex) {
  int count;
  for (int i = 0; i < g.n; i++) {
    if (g.matrix[i][vertex] != 0) {
      count++;
    }
  }
  return count;
}

// Hàm trả về tập cạnh của đồ thị có hướng
ArrayEdge getEdgeList(AdjacencyMatrix g) {
  ArrayEdge edges;
  edges.count = 0;
  for (int i = 0; i < g.n; i++) {
    for (int j = 0; j < g.n; j++) {
      if (g.matrix[i][j] != 0) {
        EDGE e;
        e.org = i;
        e.des = j;
        e.wei = g.matrix[i][j];
        edges.list[edges.count++] = e;
      }
    }
  }

  return edges;
}
