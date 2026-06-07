#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

bool search(Node* root, int val) {
    if (!root) return false;
    if (root->data == val) return true;
    return val < root->data ? search(root->left, val) : search(root->right, val);
}

Node* minValueNode(Node* root) {
    Node* curr = root;
    while (curr && curr->left) curr = curr->left;
    return curr;
}

Node* deleteNode(Node* root, int val) {
    if (!root) return nullptr;
    if (val < root->data) root->left = deleteNode(root->left, val);
    else if (val > root->data) root->right = deleteNode(root->right, val);
    else {
        if (!root->left) { Node* temp = root->right; delete root; return temp; }
        if (!root->right) { Node* temp = root->left; delete root; return temp; }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30); insert(root, 20);
    insert(root, 40); insert(root, 70);
    insert(root, 60); insert(root, 80);
    cout << "Inorder: "; inorder(root); cout << "\n";
    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not Found") << "\n";
    root = deleteNode(root, 20);
    cout << "After deleting 20: "; inorder(root); cout << "\n";
    return 0;
}
