#include "library.h"


// Xuất đỉnh ra màn hình
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
int readFile(const char* fileName, adjacencyMatrix& mt) {
 FILE * f = fopen(fileName, "rt");
 if(f == nullptr) return 0;
 fscanf(f, "%d", &mt.num);
 for(int i =0; i< mt.num; i++){
    for(int j = 0; j <mt.num; j++){
        fscanf(f, "%d", &mt.matrix[i][j]);
    }
 }
 fclose(f);
 return 1;
}
// Ghi file ma trận kề lên file văn bản
int writeFile(const char* fileName, adjacencyMatrix& mt) {
    FILE* f = fopen(fileName, "wt");
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
        for (int j = 0; j < mt.num; j++) {
            cout << mt.matrix[i][j] << "\t";
        }
        cout << "\n";
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

void initMatrix(adjacencyMatrix& mt, int numOfVertex){
    for(int i =0; i< numOfVertex; i++){
        for(int j =0; j<numOfVertex; j++){
            mt.matrix[i][j] = 0;
        }
    }
}
//1) Cho số đỉnh và tập cạnh của đồ thị vô hướng. Viết hàm trả về ma trận kề của đồ thị. 
adjacencyMatrix matrixDecoding(arrayEdge& edges, int numOfVertex){
    adjacencyMatrix mt;
    for (int i = 0; i < numOfVertex; i++) {
        for (int j = 0; j < numOfVertex; j++) {
            mt.matrix[i][j] = 0;
        }
    }
    for(int i =0; i<edges.count; i++){
        int u = edges.list[i].origin;
        int v = edges.list[i].destination;
        int w = edges.list[i].weight;
        mt.matrix[u][v] = w;
        mt.matrix[v][u] = w;
    }
    return mt;
}