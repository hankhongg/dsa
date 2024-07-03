#include <iostream>
#include <queue>

using namespace std;

typedef struct treeNode {
    int data;
    treeNode* left;
    treeNode* right;
} TREENODE; 

treeNode* createNode(int x) {
    treeNode* root = new treeNode;
    root->data = x;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void addBST(treeNode* root, int x) {
    if (root == NULL) return;
    if (root->left != NULL && root->right != NULL) {
        if (root->data > x) addBST(root->left, x);
        else addBST(root->right, x);
    }
    else if (root->left != NULL) {
        if (root->data > x) addBST(root->left, x);
        else root->right = createNode(x);
    }
    else if (root->right != NULL) {
        if (root->data < x) addBST(root->right, x);
        else root->left = createNode(x);
    }
    else {
        if (root->data < x) root->right = createNode(x);
        else root->left = createNode(x);
    }
}

int totalEven(treeNode* root) {
    queue<treeNode*> q;
    int sum = 0;
    q.push(root);
    while (!q.empty()) {
        treeNode* t = q.front();
        if (t->data % 2 == 0) sum += t->data;
        q.pop();
        if (t->left != NULL) q.push(t->left);
        if (t->right != NULL) q.push(t->right);
    }
    return sum;
}

void printLeaf(treeNode* root) {
    if (root == NULL) return;
    printLeaf(root->left);
    printLeaf(root->right);    
    if (!root->left && !root->right) cout << root->data << " ";
}

treeNode* searchNode(treeNode* root, int x) {
    if (root == NULL) return root;
    if (root->data < x) return searchNode(root->right, x);
    else if (root->data > x) return searchNode(root->left, x);
    else return root;
}

treeNode* findMin(treeNode* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

treeNode* deleteNode(treeNode* root, int x) {
    if (root == NULL) return root;
    if (x < root->data) {
        root->left = deleteNode(root->left, x);
    } else if (x > root->data) {
        root->right = deleteNode(root->right, x);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            treeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            treeNode* temp = root->left;
            delete root;
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        treeNode* temp = findMin(root->right);
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    treeNode* root = createNode(13);
    int n;
    cout << "Enter number of elements to add: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        addBST(root, x);
    }
    int sum = totalEven(root);
    cout << "Sum of even elements: " << sum << endl;
    cout << "Leaf nodes: ";
    printLeaf(root); 
    cout << endl;
    int x;
    cout << "Enter element to delete: ";
    cin >> x;
    root = deleteNode(root, x);
    cout << "Leaf nodes after deletion: ";
    printLeaf(root); 
    cout << endl;
    return 0;
}
