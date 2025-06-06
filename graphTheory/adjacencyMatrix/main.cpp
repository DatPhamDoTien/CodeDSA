#include "library.h"

int main() {
  int choice, vertex;
  adjacencyMatrix mt, mt1;
  arrayEdge edges;
  VERTEX v;
  arrayVertex arrVer;
  do {
    system("cls");
    cout << "\n=================";
    cout << "\n0.Ket thuc";
    cout << "\n1.Doc file do thi vo huong";
    cout << "\n2.Doc file do thi co huong";
    cout << "\n3.Ghi file";
    cout << "\n4.Tinh so bac vao cua dinh";
    cout << "\n5.Lay tap canh cua do thi co huong";
    cout << "\nMoi ban chon: ";
    cout << "\n6: Giai do thi vo huong";  // Chạy case 1 => 5 => 6
    cout << "\n7: Gia ma do thi co huong";
    cout << "\n8: Tim dinh ke co trong so nho nhat";
    cout << "\n9: Doi huong do thi";
    cout << "\n10: Duyet do thi theo chieu rong:";
    cout << "\n11: Duyet do thi theo chieu sau:";
    cout << "\n12: Kiem tra do thi lien thong";
    cout << "\n13: BFS tra ve danh sach dinh va danh sach canh";
    cout << "\n14: BFS kiem tra do thi lien thong manh hay yeu";
    cout << "\n15: Sap xep topo";

    cout << "\nNhap lua chon cua ban: ";
    cin >> choice;

    switch (choice) {
      case 1:
        readFile("dothi1.txt", mt);
        printAdjacencyMatrix(mt);
        cout << "so dinh la " << mt.num;
        break;
      case 2:
        readFile("dothi2.txt", mt);
        printAdjacencyMatrix(mt);
        cout << "so dinh la " << mt.num;
        break;
      case 3:
        cout << "Ghi file";
        writeFile("dothi3.txt", mt);
        printAdjacencyMatrix(mt);
        break;
      case 4:
        cout << "\nNhap dinh can tinh bac vao: ";
        cin >> vertex;
        cout << "So bac vao cua dinh " << vertex << " la: " << calDegreeInDirected(mt, vertex);
        break;
      case 5:
        edges = direcredGraphEdge(mt);
        if (edges.count == 0) {
          cout << "\nDo thi khong co canh nao";
        } else {
          cout << "\nTap canh cua do thi: ";
          for (int i = 0; i < edges.count; i++) {
            cout << "\n(" << edges.list[i].origin << " - " << edges.list[i].destination << ", " << edges.list[i].weight << ")";
          }
        }
        cout << "\n";
        //
        break;
      case 6:
        edges = direcredGraphEdge(mt);

        mt1 = matrixDecoding(edges, mt.num);
        printAdjacencyMatrix(mt1);
        //
        break;

      case 7:
        edges = direcredGraphEdge(mt);
        mt = matrixDecodingDeriectional(edges, mt.num);
        printAdjacencyMatrix(mt);
        //
        break;

      case 8:
        VERTEX verU;
        cout << "\nnhap dinh can tim: ";
        cin >> verU;
        findLightestVertex(mt, verU);
        //
        break;
      case 9:
        cout << "Doi huong do thi";
        redirectMatrix(mt);
        printAdjacencyMatrix(mt);
        //
        break;

      case 10: {
        cout << "\nNhap dinh bat dau: ";
        cin >> v;
        arrVer = breadthFirstSearch(mt, v);
        for (int i = 0; i < arrVer.count; i++) {
          cout << arrVer.list[i] << "\t";
        }
        break;
      }
      case 11: {
        cout << "\nNhap dinh bat dau: ";
        cin >> v;
        arrVer = depthFirstSearch(mt, v);
        for (int i = 0; i < arrVer.count; i++) {
          cout << arrVer.list[i] << "\t";
        }
        break;
      }
      case 12: {
        bool result = checkGraphConnected(mt);
        if (result) {
          cout << "\nDo thi lien thong!";
        } else {
          cout << "\nDo thi khong lien thong";
        }
        break;
      }
      case 13: {
        arrayEdge edges;
        arrayVertex vertexes;
        cout << "\nNhap dinh bat dau: ";
        cin >> v;
        BFS_Traversal(mt, v, vertexes, edges);
        cout << "\nDanh sach dinh la: \n";
        printArrayVertex(vertexes);
        cout << "\nDanh sach canh la: \n";
        printArrayEdge(edges);
        break;
      }
      case 14: {
        bool result = checkStrongGraphConnected(mt);
        if (result) {
          cout << "\nDo thi lien thong manh";
        } else {
          cout << "\nDo thi lien thong yeu";
        }
        break;
      }
      case 15: {
        readFile("dothi4.txt", mt);  // dothi4.txt la do thi khong co chu trinh
        arrVer = topoSort(mt);
        if (arrVer.count < mt.num) {
          cout << "\nDo thi co chu trinh, khong the sap xep topo!";
        } else {
          cout << "\nThu tu di khi sap xep topo la: ";
          printArrayVertex(arrVer);
        }
        break;
      }
    }
    cout << endl;
    system("pause");
  } while (choice != 0);
  return 0;
}

// 2) Cho số đỉnh và tập cạnh của đồ thị có hướng. Viết hàm trả về ma trận kề
// của đồ thị.
