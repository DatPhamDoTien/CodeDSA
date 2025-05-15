#include "library.h"

int main() {
    int choice, vertex;
    adjacencyMatrix mt;
    arrayEdge edges;
    do {
        cout << "\n=================";
        cout << "\n0.Ket thuc";
        cout << "\n1.Doc file do thi vo huong";
        cout << "\n2.Doc file do thi co huong";
        cout << "\n3.Ghi file";
        cout << "\n4.Tinh so bac vao cua dinh";
        cout << "\n5.Lay tap canh cua do thi co huong";
        cout << "\nMoi ban chon: ";
        cout << "\n6: Giai ma danh sach canh"; //Chạy case 1 => 5 => 6
        cout << endl;
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
            cout << "So bac vao cua dinh " << vertex
                << " la: " << calDegreeInDirected(mt, vertex);
            break;
        case 5:
            edges = direcredGraphEdge(mt);
            if (edges.count == 0) {
                cout << "\nDo thi khong co canh nao";
            }
            else {
                cout << "\nTap canh cua do thi: ";
                for (int i = 0; i < edges.count; i++) {
                    cout << "\n(" << edges.list[i].origin << " - "
                        << edges.list[i].destination << ", " << edges.list[i].weight
                        << ")";
                }
            }
            cout << "\n";
            //
            break;
        case 6:
            edges = direcredGraphEdge(mt);
            adjacencyMatrix mt1;
            mt1 = matrixDecoding(edges, mt.num);
            printAdjacencyMatrix(mt1);
            //
            break;
        }

    } while (choice != 0);

    return 0;
}

