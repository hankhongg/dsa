#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define V 6 // Định nghĩa số lượng đỉnh trong đồ thị

// Thêm cạnh vào đồ thị vô hướng
void addEdge(vector<int> adjList[], int u, int v) {
    adjList[u].push_back(v); // Thêm đỉnh v vào danh sách kề của đỉnh u
    adjList[u].push_back(v); // Thêm đỉnh u vào danh sách kề của đỉnh v (vô hướng)
}

// Thêm cạnh vào đồ thị có hướng
void addDirectedEdge(vector<int> adjList[], int u, int v) {
    adjList[u].push_back(v); // Thêm đỉnh v vào danh sách kề của đỉnh u (có hướng)
}

// BFS trên đồ thị có hướng hoặc vô hướng
void bfs(const vector<int> adjList[], int start) {
    vector<bool> visited(V, false); // Mảng đánh dấu các đỉnh đã được duyệt, ban đầu tất cả các đỉnh chưa được duyệt
    queue<int> q; // Tạo hàng đợi để lưu trữ các đỉnh sẽ được duyệt

    q.push(start); // Đẩy đỉnh bắt đầu vào hàng đợi
    visited[start] = true; // Đánh dấu đỉnh bắt đầu là đã được duyệt

    while (!q.empty()) { // Lặp lại cho đến khi hàng đợi rỗng
        int current = q.front(); // Lấy đỉnh ở đầu hàng đợi
        q.pop(); // Xóa đỉnh đó khỏi hàng đợi
        cout << current << " "; // In ra đỉnh hiện tại

        for (int neighbor : adjList[current]) { // Duyệt qua tất cả các đỉnh kề của đỉnh hiện tại
            if (!visited[neighbor]) { // Nếu đỉnh kề chưa được duyệt
                q.push(neighbor); // Đẩy đỉnh kề vào hàng đợi
                visited[neighbor] = true; // Đánh dấu đỉnh kề là đã được duyệt
            }
        }
    }
}


// Tìm đường đi bằng BFS giữa hai đỉnh
bool bfsPath(const vector<int> adjList[], int start, int end, vector<int>& path) {
    vector<bool> visited(V, false); // Mảng đánh dấu các đỉnh đã được duyệt
    vector<int> parent(V, -1); // Mảng lưu cha của mỗi đỉnh, dùng để truy vết đường đi
    queue<int> q; // Tạo hàng đợi để lưu trữ các đỉnh sẽ được duyệt

    q.push(start); // Đẩy đỉnh bắt đầu vào hàng đợi
    visited[start] = true; // Đánh dấu đỉnh bắt đầu là đã được duyệt

    while (!q.empty()) { // Lặp lại cho đến khi hàng đợi rỗng
        int current = q.front(); // Lấy đỉnh ở đầu hàng đợi
        q.pop(); // Xóa đỉnh đó khỏi hàng đợi

        if (current == end) { // Nếu đỉnh hiện tại là đỉnh đích
            int crawl = end;
            path.push_back(crawl); // Thêm đỉnh đích vào đường đi
            while (parent[crawl] != -1) { // Truy vết đường đi từ đỉnh đích về đỉnh bắt đầu
                path.push_back(parent[crawl]); // Thêm đỉnh cha vào đường đi
                crawl = parent[crawl]; // Di chuyển tới đỉnh cha
            }
            reverse(path.begin(), path.end()); // Đảo ngược đường đi để có thứ tự từ đỉnh bắt đầu tới đỉnh đích
            return true; // Đường đi được tìm thấy
        }

        for (int neighbor : adjList[current]) { // Duyệt qua tất cả các đỉnh kề của đỉnh hiện tại
            if (!visited[neighbor]) { // Nếu đỉnh kề chưa được duyệt
                q.push(neighbor); // Đẩy đỉnh kề vào hàng đợi
                visited[neighbor] = true; // Đánh dấu đỉnh kề là đã được duyệt
                parent[neighbor] = current; // Gán cha của đỉnh kề là đỉnh hiện tại
            }
        }
    }
    return false; // Không tìm thấy đường đi
}

int main() {
    vector<int> undirectedAdjList[V]; // Tạo đồ thị vô hướng
    vector<int> directedAdjList[V]; // Tạo đồ thị có hướng

    // Thêm các cạnh vào đồ thị vô hướng
    addEdge(undirectedAdjList, 0, 1);
    addEdge(undirectedAdjList, 0, 2);
    addEdge(undirectedAdjList, 1, 3);
    addEdge(undirectedAdjList, 1, 4);
    addEdge(undirectedAdjList, 2, 5);
    addEdge(undirectedAdjList, 4, 5);

    // Thêm các cạnh vào đồ thị có hướng
    addDirectedEdge(directedAdjList, 0, 1);
    addDirectedEdge(directedAdjList, 0, 2);
    addDirectedEdge(directedAdjList, 1, 3);
    addDirectedEdge(directedAdjList, 1, 4);
    addDirectedEdge(directedAdjList, 2, 5);
    addDirectedEdge(directedAdjList, 4, 5);

    vector<int> path; // Vector lưu đường đi


    // Tìm đường đi bằng BFS trên đồ thị vô hướng
    cout << "BFS Path in undirected graph: ";
    if (bfsPath(undirectedAdjList, 0, 5, path)) {
        for (int vertex : path) {
            cout << vertex << " "; // In ra các đỉnh trong đường đi
        }
        cout << endl;
    }
    else {
        cout << "Path not found" << endl; // Thông báo nếu không tìm thấy đường đi
    }

    path.clear(); // Xóa đường đi để chuẩn bị tìm đường đi mới

    // Tìm đường đi bằng BFS trên đồ thị có hướng
    cout << "BFS Path in directed graph: ";
    if (bfsPath(directedAdjList, 0, 5, path)) {
        for (int vertex : path) {
            cout << vertex << " "; // In ra các đỉnh trong đường đi
        }
        cout << endl;
    }
    else {
        cout << "Path not found" << endl; // Thông báo nếu không tìm thấy đường đi
    }

    return 0; // Kết thúc chương trình
}

