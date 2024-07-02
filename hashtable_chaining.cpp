#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
private:
    int size; // Kích thước của bảng băm
    vector<list<int>> table; // Mảng vector các danh sách liên kết

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size); // Khởi tạo mảng vector với kích thước được chỉ định
    }

    // Hàm băm sử dụng phép chia đơn giản
    int hash(int key) {
        return key % size;
    }

    // Thêm một khóa vào bảng băm
    void insert(int key) {
        int index = hash(key); // Tính chỉ số băm

        // Thêm khóa vào danh sách liên kết tại chỉ số băm
        table[index].push_back(key);
    }

    // Tìm một khóa trong bảng băm
    bool search(int key) {
        int index = hash(key); // Tính chỉ số băm

        // Duyệt qua danh sách liên kết tại chỉ số băm để tìm khóa
        for (auto& element : table[index]) {
            if (element == key) {
                return true; // Khóa được tìm thấy
            }
        }
        return false; // Khóa không tồn tại
    }

    // Xóa một khóa khỏi bảng băm
    void remove(int key) {
        int index = hash(key); // Tính chỉ số băm

        // Duyệt qua danh sách liên kết tại chỉ số băm để xóa khóa
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                table[index].erase(it); // Xóa khóa khỏi danh sách liên kết
                return;
            }
        }
    }

    // In nội dung của bảng băm
    void printTable() {
        for (int i = 0; i < size; ++i) {
            cout << i << ": ";
            for (auto& element : table[i]) {
                cout << element << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable ht(7); // Khởi tạo bảng băm có kích thước 7

    // Thêm các khóa vào bảng băm
    ht.insert(1);
    ht.insert(28);
    ht.insert(38);
    ht.insert(152);
    ht.insert(31);
    ht.insert(112);
    ht.insert(77);
    ht.insert(4);
    ht.insert(271);
    ht.insert(149);

    // In nội dung của bảng băm sau khi thêm khóa
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

    // In nội dung của bảng băm sau khi xóa khóa
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
