#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

class HashTable {
private:
    int size;
    vector<list<int>> table;
    list<int>::iterator it;

public:
    // Constructor
    HashTable(int m) : size(m) {
        table.resize(m);
    }

    // Hash function: h(k) = k mod m
    int hash(int key) {
        return key % size;
    }

    // Insert operation - add key to the beginning of the linked list
    void insert(int key) {
        int i = hash(key);
        table[i].push_front(key);
    }

    // Search operation
    bool search(int key) {
        int i = hash(key);
        int listI = 0;
        
        for (int k : table[i]) {
            if (k == key) {
                cout << key << ":FOUND_AT" << i << "," << listI << ";" << endl;
                return true;
            }
            listI++;
        }
        
        cout << key << ":NOT_FOUND;" << endl;
        return false;
    }

    // Delete operation
    bool remove(int key) {
        int i = hash(key);
        
        for (it = table[i].begin(); it != table[i].end(); ++it) {
            if (*it == key) {
                table[i].erase(it);
                std::cout << key << ":DELETED;" << std::endl;
                return true;
            }
        }
        
        cout << key << ":DELETE_FAILED;" << endl;
        return false;
    }

    // Output the entire hash table
    void print() {
        for (int i = 0; i < size; i++) {
            cout << i << ":";
            for (int key : table[i]) {
                cout << key << "->";
            }
            cout << ";" << endl;
        }
    }
};

int main() {
    int m;
    cin >> m;
    
    HashTable hashTable(m);
    
    char c;
    int key;
    
    while (cin >> c) {
        if (c == 'i') {
            cin >> key;
            hashTable.insert(key);
        }
        else if (c == 's') {
            cin >> key;
            hashTable.search(key);
        }
        else if (c == 'd') {
            cin >> key;
            hashTable.remove(key);
        }
        else if (c == 'o') {
            hashTable.print();
        }
        else if (c == 'e') {
            break;
        }
    }
    
    return 0;
}