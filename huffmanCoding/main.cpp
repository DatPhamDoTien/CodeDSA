#include "library.h"

int main() {
    // Danh sách ký tự và tần suất xuất hiện của ký tự trong văn bản.
    // ví dụ: 
    /* Pham Do Tien Dat:
    *   P xuất hiện 1 lần, tần xuất là 1.
    *   h           1                  1.
    *   a           2                  2.
    * ........ Những kí tự khác tương tự
    */
    vector<pair<char, int>> freq = {
        {'A', 5}, {'B', 9}, {'C', 12}, {'D', 13}, {'E', 16}, {'F', 45}, {'T',11},{'I', 9},{'N', 54}
    };

    //Xây dựng huffman tree.
    huffmanNode* root = buildHuffmanTree(freq);
    
    //Tạo bảng mã huffman
    unordered_map<char, string> huffmanTable;
    generalHuffmanCodes(root, "", huffmanTable);

    //Hiển thị mã huffman của từng kí tưj
    cout << "Bang ma huffman:\n";
    for (auto it : huffmanTable) {
        cout << it.first << ": " << it.second << endl;
    }
    //Văn bản cần mã hoá
    string text = "TIENDAT";
    //Mã hoá văn bản
    string encodedText = encodeText(text, huffmanTable);
    cout << "\nVan ban da ma hoa: " << encodedText << endl;

    // giải mã văn bản.
    string decodedText = decodeText(root, encodedText);
    cout << "Van ban goc: " << decodedText << endl;
    saveEncodeFile(encodedText, huffmanTable);

    loadEncodeFile();
    //Note:
    /*cout << "Theo bảng mã ASCII mở rộng, mỗi kí tự được biểu diễn bằng 8 bit như vậy với chuỗi TIENDAT\n";
    cout << "có 7 kí tự và tổng số bit cần để biểu diễn chuỗi này theo mã ASSCI là 7*8 = 56 kí tự và cách";
    cout << "mã hoá trong ví dụ trên đã biểu diễn chuỗi TIENDAT chỉ còn lại 25 bit, tiết kiệm 31 bit. Có vẻ \n";
    cout << "không đáng bao nhiêu đúng không. Nhưng nếu với văn bản cả triệu từ thì con số tiết kiệm sẽ lớn \n ";
    cout << "hơn rất nhiều và mã hoá được sinh ra để làm điều đó";*/

	return 0;
}
