#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm> // Thêm thư viện này để sử dụng hàm reverse

using namespace std;

const int V = 10;  // Số lượng đỉnh tối đa

// Hàm thêm cạnh có hướng vào đồ thị
void addEdge(vector<int> adjList[], int u, int v) {
    adjList[u].push_back(v);  // thêm v vào adjList[u] (danh sách đỉnh kề của u)
}

// Hàm thêm cạnh vô hướng vào đồ thị (cả hai chiều)
void addUndirectedEdge(vector<int> adjList[], int u, int v) {
    addEdge(adjList, u, v);  // thêm v vào adjList[u] (danh sách đỉnh kề của u)
    addEdge(adjList, v, u);  // thêm u vào adjList[v] (danh sách đỉnh kề của v)
}

// Hàm thực hiện BFS (Breadth-First Search)
void bfs(vector<int> adjList[], int s, vector<bool>& visited, vector<int>& parent) {
    queue<int> q;  // Tạo hàng đợi để duyệt BFS

    // Đánh dấu đỉnh bắt đầu là đã duyệt và thêm vào hàng đợi
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        // Lấy đỉnh ở đầu hàng đợi
        int current = q.front();
        q.pop();

        // Duyệt các đỉnh kề chưa duyệt của đỉnh hiện tại
        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                // Đánh dấu đỉnh kề là đã duyệt và lưu trữ đỉnh cha
                visited[neighbor] = true;
                parent[neighbor] = current;

                // Thêm đỉnh kề vào hàng đợi để duyệt tiếp
                q.push(neighbor);
            }
        }
    }
}

// Hàm tìm đường đi BFS từ 's' đến 't'
void bfsPath(vector<int> adjList[], int s, int t) {
    vector<bool> visited(V, false);  // Mảng đánh dấu các đỉnh đã duyệt
    vector<int> parent(V, -1);  // Mảng lưu trữ đỉnh cha của mỗi đỉnh

    // Thực hiện BFS để tìm kiếm và lưu trữ thông tin duyệt
    bfs(adjList, s, visited, parent);

    if (!visited[t]) {
        cout << "Khong co duong di nao!\n";  // Không tìm thấy đường đi
    }
    else {
        vector<int> path;  // Mảng lưu trữ đường đi

        for (int v = t; v != -1; v = parent[v]) {
            path.push_back(v);  // Thêm đỉnh hiện tại vào đường đi
        }
        reverse(path.begin(), path.end());  // Đảo ngược đường đi cho thứ tự chính xác

        for (int x : path) {
            cout << x << " ";  // In ra đường đi
        }
        cout << endl;
    }
}

// Hàm đệ quy DFS để duyệt đồ thị
void dfs(vector<int> adjList[], int s, vector<int>& parent , vector<bool>& visited, int t) {
    // Đánh dấu đỉnh hiện tại là đã duyệt
    visited[s] = true;

    // Trường hợp cơ sở: ...
    if (s == t) {
        return;  // Không cần duyệt thêm
    }

    // Duyệt các đỉnh kề chưa duyệt của đỉnh hiện tại
    for (int neighbor : adjList[s]) {
        if (!visited[neighbor]) {
            // Thiết lập đỉnh hiện tại là đỉnh cha của đỉnh kề
            parent[neighbor] = s;
            // Gọi đệ quy DFS trên đỉnh kề để duyệt sâu hơn
            dfs(adjList, neighbor, parent, visited, t);
        }
    }
}

// Hàm thực hiện DFS để tìm đường đi từ 's' đến 't'
void dfsPath(vector<int> adjList[], int s, int t) {
    vector<bool> visited(V, false);  // Mảng đánh dấu các đỉnh đã duyệt
    vector<int> parent(V, -1);  // Mảng lưu trữ đỉnh cha của mỗi đỉnh

    dfs(adjList, s, parent, visited, t);  // Gọi hàm đệ quy DFS

    if (!visited[t]) {
        cout << "Khong co duong di nao!\n";  // Không tìm thấy đường đi
    }
    else {
        vector<int> path;  // Mảng lưu trữ đường đi

        for (int v = t; v != -1; v = parent[v]) {
            path.push_back(v);  // ...
        }
        reverse(path.begin(), path.end());  // ...

        for (int x : path) {
            cout << x << " ";  // In ra đường đi
        }
        cout << endl;
    }
}

int main() {
    vector<int> adjList[V];  // Mảng danh sách kề
    vector<int> adjListUn[V];  // Mảng danh sách kề cho đồ thị vô hướng

    // ...
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 3, 4);

    // BFS đồ thị có hướng
    int s = 0, t = 4;
    cout << "Duong di BFS co huong tu " << s << " den " << t << ": ";
    bfsPath(adjList, s, t);

    bool check;
    do {
        check = true;
        cout << "Moi nhap dinh bat dau: "; cin >> s;
        cout << "Moi nhap dinh ket thuc: "; cin >> t;
        if ((s < 0 || s > 4) || (t < 0 || t > 4)) { // tai sao lai la 0 va 4? 
            cout << "Dinh bat dau va ket thuc khong hop le!" << endl;
            check = false;
        }
    } while (!check);

    // DFS đồ thị có hướng
    cout << "Duong di DFS co huong tu " << s << " den " << t << ": ";
    dfsPath(adjList, s, t);

    // ...
    addUndirectedEdge(adjListUn, 2, 3);
    addUndirectedEdge(adjListUn, 0, 1);
    addUndirectedEdge(adjListUn, 0, 4);
    addUndirectedEdge(adjListUn, 1, 2);
    addUndirectedEdge(adjListUn, 2, 4);
    addUndirectedEdge(adjListUn, 3, 4);

    //  BFS đồ thị vô hướng
    cout << "Duong di BFS vo huong tu " << s << " den " << t << ": ";
    bfsPath(adjListUn, s, t);

    // DFS đồ thị vô hướng
    cout << "Duong di DFS vo huong tu " << s << " den " << t << ": ";
    dfsPath(adjListUn, s, t);

    return 0;
}

