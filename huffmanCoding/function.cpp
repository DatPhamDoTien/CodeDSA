#include "library.h"
#include <queue>

// Tạo cây huffman dựa trên những cặp node có kí tự và tần xuất xuất hiện khác
// nhau, lưu chúng trong priority_queue theo thứ tự ưu tiên min_heap. (lưu ý
// priority_queue mặc định có thứ tự ưu tiên là max-heap nên cần struct compare
// hoạt động theo cách function call operator để so sánh và đưa những node có
// frequency thấp lên top của queue.

huffmanNode *buildHuffmanTree(vector<pair<char, int>> &frequency) {
  priority_queue<huffmanNode *, vector<huffmanNode *>, compare> pq;
  for (auto it : frequency) {
    pq.push(new huffmanNode(it.first, it.second));
  }
  while (pq.size() > 1) {
    huffmanNode *leftNode = pq.top();
    pq.pop();
    huffmanNode *rightNode = pq.top();
    pq.pop();
    huffmanNode *parent =
        new huffmanNode('\0', leftNode->frequency + rightNode->frequency);
    parent->left = leftNode;
    parent->right = rightNode;
    pq.push(parent);
  }
  return pq.top();
}

// Xây dựng mã huffman từ cây huffman theo nguyên tắc đi về trái thì biểu diễn
// code bằng bit 0 đi về phải thì biểu diễn bằng bit 1.
void generalHuffmanCodes(huffmanNode *root, string code,
                         unordered_map<char, string> &huffmanTable) {
  if (!root)
    return;

  if (root->character != '\0')
    huffmanTable[root->character] = code;
  generalHuffmanCodes(root->left, code + "0", huffmanTable);
  generalHuffmanCodes(root->right, code + "1", huffmanTable);
}

void generalHuffmancodess(huffmanNode *root, string code,
                          unordered_map<char, string> &huffmanTable) {
  if (!root)
    return;
  if (root->character != '\0') {
    huffmanTable[root->character] = code;
  }
  generalHuffmancodess(root->left, code + "0", huffmanTable);
  generalHuffmancodess(root->right, code + "1", huffmanTable);
}

// Mã hoá văn bản dựa trên mã huffman đã tạo bằng cách duyệt toàn bộ ký tự có
// trong văn bản (ký tự là key), và nối mã đã được mã hoá riêng cho kí tự (mã đã
// được mã hoá là value)
string encodeText(const string &text,
                  unordered_map<char, string> &huffmanTable) {
  string encodedText = "";
  for (char ch : text) {
    encodedText += huffmanTable[ch];
  }
  return encodedText;
}

// Quá trình giải mã
// Dựa trên mã đã được mã hoá lưu trong encodedText duyệt huffmanTree để giải
// mã. Duyệt mã đã được mã hoá trong encodedText bằng cách so sánh bit (bit 0 đi
// về bên trái, bit 1 đi về bên phải) khi đến node lá nối ký tự vào chuỗi ta sẽ
// được chuỗi ký tự được giải mã (văn bản).
string decodeText(huffmanNode *root, const string encodedText) {
  string decodedText = "";
  huffmanNode *current = root;
  for (char bit : encodedText) {
    if (bit == '0')
      current = current->left;
    else
      current = current->right;

    if (!current->left && !current->right) { // node lá
      decodedText += current->character;
      current =
          root; // đưa node duyệt trở về gốc để tiếp tục quá trình giải mã.
    }
  }
  return decodedText;
}

void saveEncodeFile(const string encodedText,
                    unordered_map<char, string> &huffmanTable) {
  ofstream outFile("huffman_encoded.bin", ios::binary);
  if (!outFile) {
    cerr << "Khong the mo file de ghi!\n";
    return;
  }

  outFile << huffmanTable.size() << endl;
  for (auto it : huffmanTable) {
    outFile << it.first << " " << it.second << endl;
  }

  bitset<8> bitBuffer;
  int bitCount = 0;
  for (char bit : encodedText) {
    bitBuffer[7 - bitCount] = (bit == '1');
    bitCount++;
    if (bitCount == 8) {
      outFile.put(static_cast<char>(bitBuffer.to_ullong()));
      bitBuffer.reset();
      bitCount = 0;
    }
  }
  if (bitCount > 0) {
    outFile.put(static_cast<char>(bitBuffer.to_ullong()));
  }
  outFile.close();
  cout << "Da luu file nen huffman thanh cong!\n";
}

// Giải mã từ chuỗi bit sang văn bản.
string decodeTextFromBit(const string &encodedBits,
                         unordered_map<string, char> &reverseHuffmanTable) {
  string decodedText = "";
  string currentCode = "";
  for (char bit : encodedBits) {
    currentCode += bit;
    if (reverseHuffmanTable.find(currentCode) != reverseHuffmanTable.end()) {
      decodedText += reverseHuffmanTable[currentCode]; // Tìm thấy mã hợp lệ ->
                                                       // thêm vào kết quả
      currentCode = "";
    }
  }
  return decodedText;
}
// Đọc file huffman và giải mã.
void loadEncodeFile() {
  ifstream inFile("huffman_encoded.bin", ios::binary);
  if (!inFile) {
    cerr << "Khong the mo file de doc: ";
    return;
  }

  unordered_map<string, char> reverseHuffmanTable;
  int tableSize;
  inFile >> tableSize;
  inFile.ignore();
  for (int i = 0; i < tableSize; i++) {
    char character;
    string code;
    inFile >> character >> code;
    reverseHuffmanTable[code] = character;
  }
  string encodedBits = "";
  char byte;
  while (inFile.get(byte)) {
    bitset<8> bits(byte);
    encodedBits += bits.to_string();
  }
  inFile.close();

  string decodedText = decodeTextFromBit(encodedBits, reverseHuffmanTable);
  cout << "Van ban da giai ma: " << decodedText << endl;
}

// huffman codding
huffmanNode *buildHuffmanTreee(vector<pair<char, int>> &frequency) {
  priority_queue<huffmanNode *, vector<huffmanNode *>, compare> pq;
  for (auto it : frequency) {
    pq.push(new huffmanNode(it.first, it.second));
  }
  while (pq.size() > 1) {
    huffmanNode *leftNode = pq.top();
    pq.pop();
    huffmanNode *rightNode = pq.top();
    pq.pop();
    huffmanNode *parent;
    parent->character = '\0';
    parent->left = leftNode;
    parent->right = rightNode;
    pq.push(parent);
  }
  return pq.top();
}

void generalHuffmanCodese(huffmanNode *root, string code,
                          unordered_map<char, string> &huffmanTable) {
  if (!root) {
    return;
  }
  if (root->character != '\0') {
    huffmanTable[root->character] = code;
  }
  generalHuffmanCodese(root->left, code + "0", huffmanTable);
  generalHuffmanCodese(root->right, code + "1", huffmanTable);
}
