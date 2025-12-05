#include <iostream>
#include <queue>
#include <unordered_map>
#include <bitset>
#include <vector>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void buildCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root) return;
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }
    buildCodes(root->left, code + "0", huffmanCode);
    buildCodes(root->right, code + "1", huffmanCode);
}

void huffmanEncode(string text) {
    unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;
        pq.push(sum);
    }
    Node* root = pq.top();

    unordered_map<char, string> huffmanCode;
    buildCodes(root, "", huffmanCode);

    cout << "\nHuffman Codes:\n";
    for (auto &pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << "\n";
    }

    cout << "\nOriginal ASCII Binary (8-bit per char):\n";
    string originalBinary = "";
    for (char ch : text) {
        bitset<8> b(ch);
        cout << b << " ";
        originalBinary += b.to_string();
    }
    cout << "\n";

    string encodedBinary = "";
    for (char ch : text) {
        encodedBinary += huffmanCode[ch];
    }

    cout << "\nCompressed Binary:\n" << encodedBinary << "\n";
    cout << "\n--- Size Comparison ---\n";
    cout << "Original size: " << originalBinary.size() << " bits\n";
    cout << "Compressed size: " << encodedBinary.size() << " bits\n";
    double ratio = (double)encodedBinary.size() / originalBinary.size() * 100;
    cout << "Compression ratio: " << ratio << "%\n";
}

int main() {
    string text;
    cout << "Enter text to compress: ";
    getline(cin, text);

    huffmanEncode(text);
    return 0;
}
