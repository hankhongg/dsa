#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table;
    int size;
    const int EMPTY = -1;
    const int DELETED = -2;

public:
    HashTable(int m) : size(m) {
        table.resize(m, EMPTY);
    }

    int hash(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hash(key);
        int originalIndex = index;
        int i = 1;

        while (table[index] != EMPTY && table[index] != DELETED && table[index] != key) {
            index = (originalIndex + i) % size;
            i++;
        }

        if (table[index] != key) {
            table[index] = key;
        }
    }

    bool search(int key) {
        int index = hash(key);
        int originalIndex = index;
        int i = 1;

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                return true;
            }
            index = (originalIndex + i) % size;
            i++;
        }
        return false;
    }

    void remove(int key) {
        int index = hash(key);
        int originalIndex = index;
        int i = 1;

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                table[index] = DELETED;
                return;
            }
            index = (originalIndex + i) % size;
            i++;
        }
    }

    void printTable() {
        for (int i = 0; i < size; i++) {
            if (table[i] == EMPTY) {
                cout << i << ": EMPTY" << endl;
            } else if (table[i] == DELETED) {
                cout << i << ": DELETED" << endl;
            } else {
                cout << i << ": " << table[i] << endl;
            }
        }
    }
};

int main() {
    HashTable ht(37);

    // Thêm các khóa vào bảng băm
    int keysToAdd[] = {1, 28, 38, 152, 31, 112, 77, 4, 271, 149};
    for (int key : keysToAdd) {
        ht.insert(key);
    }

    // In bảng băm sau khi thêm khóa
    cout << "Hash table after insertions:" << endl;
    ht.printTable();
    cout << endl;

    // Tìm các khóa
    int keysToSearch[] = {1, 38, 112, 75};
    for (int key : keysToSearch) {
        cout << "Search " << key << ": " << (ht.search(key) ? "Found" : "Not Found") << endl;
    }
    cout << endl;

    // Xóa các khóa
    int keysToDelete[] = {1, 75, 112};
    for (int key : keysToDelete) {
        ht.remove(key);
    }

    // In bảng băm sau khi xóa khóa
    cout << "Hash table after deletions:" << endl;
    ht.printTable();
    cout << endl;

    // Tìm lại các khóa sau khi xóa
    int keysToSearchAgain[] = {38, 112, 149};
    for (int key : keysToSearchAgain) {
        cout << "Search " << key << ": " << (ht.search(key) ? "Found" : "Not Found") << endl;
    }

    return 0;
}
