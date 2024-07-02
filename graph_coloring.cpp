#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

// Lớp biểu diễn một đồ thị vô hướng bằng cách sử dụng danh sách kề
class Graph {
    int V; // Số lượng đỉnh
    list<int>* adj; // Con trỏ tới mảng danh sách kề

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // Thêm cạnh vào đồ thị
    void greedyColoring(); // Thuật toán tô màu tham lam
};

// Constructor của Graph
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

// Thêm cạnh vào đồ thị
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v); // Vì đồ thị là vô hướng
}

// Hàm thực hiện thuật toán tô màu tham lam
void Graph::greedyColoring() {
    vector<int> result(V, -1); // Đặt tất cả các đỉnh chưa được tô màu
    result[0] = 0; // Tô màu đầu tiên cho đỉnh đầu tiên

    vector<bool> available(V, false); // Mảng để theo dõi các màu đã sử dụng

    // Gán màu cho các đỉnh còn lại
    for (int u = 1; u < V; u++) {
        // Đánh dấu các màu đã sử dụng bởi các đỉnh kề của u
        for (auto i : adj[u]) {
            if (result[i] != -1) {
                available[result[i]] = true;
            }
        }

        // Tìm màu nhỏ nhất chưa được sử dụng
        int cr;
        for (cr = 0; cr < V; cr++) {
            if (!available[cr]) {
                break;
            }
        }

        result[u] = cr; // Gán màu này cho đỉnh u

        // Đặt lại các giá trị trong mảng available cho lần lặp tiếp theo
        for (auto i : adj[u]) {
            if (result[i] != -1) {
                available[result[i]] = false;
            }
        }
    }

    // In ra kết quả tô màu
    for (int u = 0; u < V; u++) {
        cout << "Đỉnh " << u << " ---> Màu " << result[u] << endl;
    }
}

// Chương trình chính để kiểm tra thuật toán
int main() {
    Graph g(5); // Tạo đồ thị với 5 đỉnh
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Ket qua to mau su dung thuat toan to mau tham lam:\n";
    g.greedyColoring();

    return 0;
}
