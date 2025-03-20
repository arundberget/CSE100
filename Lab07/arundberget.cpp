#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int key; // key value
    Node* left; // left child
    Node* right; // right child
    Node* parent; // parent node

    Node(int key) : key(key), left(nullptr), right(nullptr), parent(nullptr) {} // constructor
};

class BST {
    public:
    Node* root; // root node

    BST() : root(nullptr) {} // constructor for empty BST

    void insert(int key) { // function to insert new key
        Node* z = new Node(key);
        Node* y = nullptr;
        Node* x = root;

        while (x != nullptr) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        z->parent = y;
        if (y == nullptr) {
            root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }

    Node* treeSearch(Node* x, int k) { // function to search for node with key
        if (x == nullptr || k == x->key) {
            return x;
        }
        if (k < x->key) {
            return treeSearch(x->left, k);
        } else {
            return treeSearch(x->right, k);
        }
    }
    
    void transplant(Node* u, Node* v) { // function to replace rooted subtree with another rooted subtree
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v != nullptr) {
            v->parent = u->parent;
        }
    }
    
    Node* minimum(Node* x) { // function to find node with minimum key
        while (x->left != nullptr) {
            x = x->left;
        }
        return x;
    }
    
    void deleteKey(int key) { // function to delete node with key
        Node* z = treeSearch(root, key);
        if (z == nullptr) {
            return;
        }
        
        Node* y;
        if (z->left == nullptr) {
            transplant(z, z->right);
        } else if (z->right == nullptr) {
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            if (y->parent != z) {
                Node* temp = y->right;
                transplant(y, temp);
                y->right = z->right;
                if(y->right != nullptr) {
                    y->right->parent = y;
                }
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
        delete z;
    }

    void preOrder(Node* node, vector<int>& result) { // function to perform preorder traversal
        if (node != nullptr) {
            result.push_back(node->key);
            preOrder(node->left, result);
            preOrder(node->right, result);
        }
    }

    void inOrder(Node* node, vector<int>& result) { // function to perform inorder traversal
        if (node != nullptr) {
            inOrder(node->left, result);
            result.push_back(node->key);
            inOrder(node->right, result);
        }
    }

    void postOrder(Node* node, vector<int>& result) { // function to perform postoder traversal
        if (node != nullptr) {
            postOrder(node->left, result);
            postOrder(node->right, result);
            result.push_back(node->key);
        }
    }

    void print(const vector<int>& vec) { // function to print elements with correct format
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << endl;
        }
    }
};

int main() {
    BST bst; // BST object
    char line[10]; // enough space
    int key; // stores key

    while (cin.getline(line, sizeof(line))) { // checks for each command by looking at the first character of each line
        if (line[0] == 'e') {
            break;
        } else if (line[0] == 'i') {
            key = 0;
            int i = 1;
            while (line[i] != '\0') {
                key = key * 10 + (line[i] - '0');
                i++;
            }
            bst.insert(key);
        } else if (line[0] == 'd') {
            key = 0;
            int i = 1;
            while (line[i] != '\0') {
                key = key * 10 + (line[i] - '0');
                i++;
            }
            bst.deleteKey(key);
        } else if (line[0] == 'o') {
            vector<int> result;
            if (line[1] == 'i' && line[2] == 'n') {
                bst.inOrder(bst.root, result);
            } else if (line[1] == 'p' && line[2] == 'r') {
                bst.preOrder(bst.root, result);
            } else if (line[1] == 'p' && line[2] == 'o') {
                bst.postOrder(bst.root, result);
            }
            bst.print(result);
        }
    }
    return 0;
}




