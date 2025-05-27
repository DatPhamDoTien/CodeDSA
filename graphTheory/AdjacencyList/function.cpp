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
      EDGE e;
      e.from = i;
      e.to = current->adjacentVertex;
      e.weight = current->weight;
      dec.list[dec.count++] = e;
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
