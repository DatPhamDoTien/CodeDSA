#include "library.h"

int readFile(const char *fileName, AdjacencyList &list, int flag) {
  FILE *f = fopen(fileName, "rt");
  if (f == nullptr)
    return 0;
  fscanf(f, "%d", &list.count);

  for (int i = 0; i < list.count; i++) {
    list.list[i] = {NULL};
  }

  for (int i = 0; i < list.count; i++) {
    int qty; // Số lượng đỉnh kề
    fscanf(f, "%d", &qty);
    for (int j = 0; j < qty; j++) {
      NODE *newNode = new NODE;
      if (flag) {
        fscanf(f, "%d%d", &newNode->adjacentVertex, &newNode->weight);
      } else {
        fscanf(f, "%d", &newNode->adjacentVertex);
      }
      newNode->next = list.list[i];
      list.list[i] = newNode;
    }
  }
  fclose(f);
  return 1;
}

int countNode(NODE *node) {
  int count = 0;
  while (node != nullptr) {
    ++count;
    node = node->next;
  }
  return count;
}

int writeFile(const char *fileName, AdjacencyList &list, int flag) {
  FILE *f = fopen(fileName, "wt");
  if (f == nullptr)
    return 0;
  fprintf(f, "%d", list.count);
  for (int i = 0; i < list.count; i++) {
    NODE *node = list.list[i];
    int qty = countNode(node);
    fprintf(f, "\n%d", qty);
    while (node != nullptr) {
      if (flag) {
        fprintf(f, "%d %d", node->adjacentVertex, node->weight);
      } else {
        fprintf(f, "%d", node->adjacentVertex);
      }
      node = node->next;
    }
  }
  fclose(f);
  return 1;
}

void deleteAdjacencyList(AdjacencyList &list) {
  for (int i = 0; i < list.count; i++) {
    NODE *p = list.list[i];
    while (p != nullptr) {
      NODE *q = p;
      p = p->next;
      delete q;
    }
    list.list[i] = NULL;
  }
}

void printAdjacencyList(const AdjacencyList &list) {
  cout << endl;
  for (int i = 0; i < list.count; i++) {
    cout << endl;
    cout << i << ": ";
    NODE *current = list.list[i];
    while (current != nullptr) {
      cout << "(" << current->adjacentVertex << ", " << current->weight << ")";
      current = current->next;
    }
  }
}

EdgeList takeListOfEdge(AdjacencyList list) {
  EdgeList dec;
  for (int i = 0; i < list.count; i++) {
    NODE *current = list.list[i];
    while (current != nullptr) {
      EDGE e = {i, current->adjacentVertex, current->weight};
      dec.list[dec.count++] = e;
      current = current->next;
    }
  }
  return dec;
}

void printEdge(EDGE edge) {
  cout << "(" << edge.from << "-" << edge.to << ": " << edge.weight << ")";
}

int calcutaleInDegrees(AdjacencyList list, int vertex) {
  int count = 0;
  for (int i = 0; i < list.count; i++) {
    NODE *current = list.list[i];
    while (current != nullptr) {
      if (current->adjacentVertex = vertex) {
        count++;
      }
      current = current->next;
    }
  }
  return count;
}
mutex cout_mutex;
void DowLoad(int index) {
  auto start = chrono::high_resolution_clock::now();
  int dowLoadTime = 1 + rand() % 2;
  this_thread::sleep_for(chrono::seconds(dowLoadTime));
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> elapsed = end - start;
  lock_guard<mutex> lock(cout_mutex);
  std::cout << "Write in " << elapsed.count() << " second.\n";
}

void countDowload() {
  int num = 3;
  vector<std::thread> threads;
  for (int i = 1; i <= num; i++) {
    threads.emplace_back(DowLoad, i);
  }
  for (auto &thread : threads) {
    thread.join();
  }
  cout << "All completed!\n";
}

// 1) Cho số đỉnh và tập cạnh của đồ thị vô hướng.
//  Viết hàm trả về danh sách kề của đồ thị.
AdjacencyList builtAdjacencyList(EdgeList eList, int numOfVer) {
  AdjacencyList adjList;
  adjList.count = numOfVer;
  for (int i = 0; i < eList.count; i++) {
    adjList.list[i] = nullptr;
  }
  for (int i = 0; i < eList.count; i++) {
    int u = eList.list[i].from;
    int v = eList.list[i].to;
    int w = eList.list[i].weight;

    NODE *node1 = new NODE;
    node1->adjacentVertex = v;
    node1->weight = w;
    node1->next = adjList.list[u];
    adjList.list[u] = node1;

    NODE *node2 = new NODE;
    node2->adjacentVertex = u;
    node2->weight = w;
    node2->next = adjList.list[v];
    adjList.list[v] = node2;
  }
  return adjList;
}

// 2) Cho số đỉnh và tập cạnh của đồ thị có hướng. Viết hàm trả về danh sách kề
// của đồ thị.
AdjacencyList buildDirectedAdjList(EdgeList eList, int numOfVer) {
  AdjacencyList adjList;
  adjList.count = numOfVer;
  // Khởi tạo tất cả danh sách kề rỗng
  for (int i = 0; i < numOfVer; ++i) {
    adjList.list[i] = nullptr;
  }
  // Duyệt qua từng cạnh
  for (int i = 0; i < eList.count; ++i) {
    int u = eList.list[i].from;
    int v = eList.list[i].to;
    int w = eList.list[i].weight;
    // Thêm v vào danh sách kề của u (chỉ 1 chiều vì đồ thị có hướng)
    NODE *node = new NODE;
    node->adjacentVertex = v;
    node->weight = w;
    node->next = adjList.list[u];
    adjList.list[u] = node;
  }
  return adjList;
}
