#include <iostream>
#include <queue>

using namespace std;

typedef struct treeNode {
	int data;
	treeNode* left;
	treeNode* right;
}TREENODE; 

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
		else addBST(root->right,x);
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
		if (t->right != NULL)q.push(t->right);
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
\
void deleteNode(treeNode* root, int x) {
	treeNode* t = searchNode(root, x);
	treeNode* father = root;
	queue<treeNode*> q;
	q.push(root);
	while (!q.empty()) {
		treeNode* a = q.front();
		q.pop();
		if (a->left) {
			if (a->left->data == x) {
				father = a;
				break;
			}
			q.push(a->left);
		}
		if (a->right) {
			if (a->right->data == x) {
				father = a;
				break;
			}
			q.push(a->right);
		}
	}
	if (!t->left && !t->right) {
		delete t;
		father->left = NULL;
		father->right = NULL;
	}
	else if (t->left && !t->right) {
		treeNode* l = t->left;
		if (l->data > father->data) father->right = l;
		else if (l->data < father->data) father->left = l;
		delete t;
	}
	else if (t->right && !t->left) {
		treeNode* r = t->right;
		if (r->data > father->data) father->right = r;
		else if (r->data < father->data) father->left = r;
		delete t;
	}
	else {
		
	}

}

int main() {
	treeNode* root = createNode(13);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		addBST(root, x);
	}
	int sum = totalEven(root);
	cout << sum << endl;
	printLeaf(root); cout << endl;
	int x;
	cin >> x;
	deleteNode(root, x);

}
