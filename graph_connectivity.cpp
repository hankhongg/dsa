#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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

// Hàm DFS để xác định thứ tự hoàn thành
void dfs(int v, vector<int> adjList[], vector<bool>& visited, stack<int>& Stack) {
    // ...
    visited[v] = true;
    for (int neighbor : adjList[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited, Stack);
        }
    }
    Stack.push(v);
}

// Hàm DFS trên đồ thị chuyển vị
void reverseDfs(int v, vector<vector<int>>& transpose, vector<bool>& visited) {
    visited[v] = true;
    for (int neighbor : transpose[v]) { // chạy vòng lặp trên đồ thị chuyển vị
        if (!visited[neighbor]) {
            reverseDfs(neighbor, transpose, visited);
        }
    }
}


// Hàm kiểm tra tính liên thông mạnh của đồ thị
bool isStronglyConnected(vector<int> adjList[], int n) {
    stack<int> Stack;
    vector<bool> visited(n, false);

    // Bước 1: Thực hiện DFS và lưu thứ tự hoàn thành vào ngăn xếp
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, adjList, visited, Stack);
        }
    }

    // Bước 2: Tạo đồ thị chuyển vị 
    vector<vector<int>> transpose(n);
    for (int v = 0; v < n; ++v) {
        for (int neighbor : adjList[v]) {
            transpose[neighbor].push_back(v);
        }
    }

    // Bước 3: Thực hiện DFS trên đồ thị chuyển vị theo thứ tự trong ngăn xếp
    fill(visited.begin(), visited.end(), false); // Reset mảng visited
    int count = 0;  // Đếm số lượng thành phần liên thông mạnh
    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();

        if (!visited[v]) {
            // Bước 4: Thực hiện DFS, mỗi lần đỉnh chưa thăm count++
            reverseDfs(v, transpose, visited);
            count++;
            if (count > 1) {
                return false;  // Nếu có nhiều hơn 1 thành phần liên thông mạnh, đồ thị không liên thông mạnh
            }
        }
    }
    return true;  // Chỉ có 1 thành phần liên thông mạnh, đồ thị liên thông mạnh
}


void dfs(vector<int> adjList[], int s, /*vector<int>& parent*/ vector<bool>& visited /*int t*/) {
    // Cho đỉnh hiện tại là đã duyệt
    visited[s] = true;
    // Duyệt qua các "hàng xóm" hay đỉnh liền kề theo đệ quy
    for (int neighbor : adjList[s]) {
        if (!visited[neighbor]) {
            dfs(adjList, neighbor, visited);
        }
    }
}

void bfs(vector<int> adjList[], int s, vector<bool>& visited /*vector<int>& parent*/) {
    queue<int> q;  // Tạo hàng đợi để duyệt BFS
    visited[s] = true;  // ...
    q.push(s);  // ...

    while (!q.empty()) {
        int v = q.front();  // Lấy đỉnh ở đầu hàng đợi
        q.pop();

        // Duyệt các đỉnh kề chưa duyệt của đỉnh hiện tại
        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;  // Đánh dấu đỉnh kề là đã duyệt
                q.push(neighbor);  // Thêm đỉnh kề vào hàng đợi để duyệt tiếp
            }
        }
    }
}

bool check_if_connected(vector<int> adjList[], int n) {
    vector<bool> visited(n, false); // n là gì?
    dfs(adjList, 0, visited);  // Bắt đầu duyệt từ đỉnh 0
    // hoặc bfs 
    // Kiểm tra nếu tất cả các đỉnh đã được thăm
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}



int main() {
    const int V = 4; // Số đỉnh
    vector<int> adjList[V];  // Danh sách kề cho đồ thị có hướng
    vector<int> adjListUn[V];  // Danh sách kề cho đồ thị vô hướng

    // Các cạnh của đồ thị có hướng
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 0);
    addEdge(adjList, 3, 2);

    // Kiểm tra tính liên thông cho đồ thị có hướng
    if (isStronglyConnected(adjList, V)) {
        cout << "Do thi co huong lien thong manh!" << endl;
    }
    else {
        cout << "Do thi co huong khong lien thong manh!" << endl;
    }

    // Các cạnh của đồ thị vô hướng
    addUndirectedEdge(adjListUn, 0, 1);
    addUndirectedEdge(adjListUn, 0, 3);
    addUndirectedEdge(adjListUn, 2, 2);

    // Kiểm tra tính liên thông cho đồ thị vô hướng
    if (check_if_connected(adjListUn, V)) {
        cout << "Do thi vo huong lien thong!" << endl;
    }
    else {
        cout << "Do thi vo huong khong lien thong!" << endl;
    }

    return 0;
}



