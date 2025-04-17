#include <iostream>
#include <string>
#include <queue>
#include <string>

using namespace std;

struct HuffmanNode { // define Huffman tree node
    char symbol;
    int frequency;
    HuffmanNode *left; // left child
    HuffmanNode *right; // right child

    HuffmanNode(char s, int f) : symbol(s), frequency(f), left(nullptr), right(nullptr) {}
    HuffmanNode(int f, HuffmanNode* l, HuffmanNode* r) : symbol('\0'), frequency(f), left(l), right(r) {}
};

struct CompareFrequency { // min-heap compare by frequency
    bool operator()(HuffmanNode* a, HuffmanNode* b) const {
        return a->frequency > b->frequency;
    }
};

HuffmanNode* build(const vector<int>& frequency) { // returns root of Huffman tree after building it
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareFrequency> pq;

    for (int i = 0; i < 6; i++) {
        pq.push(new HuffmanNode(char('A' + i), frequency[i]));
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();
        HuffmanNode* parent = new HuffmanNode(left->frequency + right->frequency, left, right);
        pq.push(parent);
    }
    return pq.top(); // returns root
}

void gCodes(HuffmanNode* node, const string& p, vector<string>& codes) { // recursively traverse tree and build codes
    if (!node) {
        return;
    }
    if (!node->left && !node->right) {
        codes[node->symbol - 'A'] = p;
    }
    gCodes(node->left, p + "0", codes);
    gCodes(node->right, p + "1", codes);
}

void deleteTree(HuffmanNode* node) {
    if (!node) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    vector<int> frequency(6);
    for (int i = 0; i < 6; i++) {
        cin >> frequency[i];
    }

    HuffmanNode* root = build(frequency);

    vector<string> codes(6);
    gCodes(root, "", codes);

    for (int i = 0; i < 6; i++) {
        cout << char('A' + i) << ":" << codes[i] << endl;
    }

    deleteTree(root); // free memory

    return 0;
}