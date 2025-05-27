#include "library.h"

int main() {
  int choice, flag, vertex, qty;
  AdjacencyList list;
  do {
    cout << "\n===================================";
    cout << "\n0.Ket thuc";
    cout << "\n1.Doc file do thi co trong so";
    cout << "\n2.Doc file do thi khong trong so";
    cout << "\n3.Ghi file";
    cout << "\n4.Tinh so bac vao cua dinh";
    cout << "\n5.Lay tap canh cua do thi";
    cout << endl;
    cout << "Nhap luu chon cua ban: ";
    cin >> choice;
    cin.ignore();
    switch (choice) {
    case 1:
      readFile("dothi1.txt", list, 0);
      printAdjacencyList(list);
      break;
    case 2:
      readFile("dothi2.txt", list, 1);
      printAdjacencyList(list);
      break;

    case 3:
      cout << "\nChon che do ghi: \n0: ghi file khong trong so.\n1: Ghi file "
        "co trong so\n";
      cout << "\nChoice: ";
      cin >> flag;
      cout << "Dang ghi....." << endl;
      countDowload();
      cout << "Da ghi xong!";
      writeFile("dothi3.txt", list, flag);
      break;
    case 4:
      cout << "\nNhap so dinh can tinh: ";
      cin >> vertex;
      qty = calcutaleInDegrees(list, vertex);
      cout << "Bac vao cua dinh " << vertex << " la: " << qty << endl;
    default:
      break;
    }
  } while (choice != 0);
}