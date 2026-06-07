#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* lca(Node* root, int n1, int n2) {
    if (!root) return nullptr;
    if (root->data == n1 || root->data == n2) return root;
    Node* leftLCA = lca(root->left, n1, n2);
    Node* rightLCA = lca(root->right, n1, n2);
    if (leftLCA && rightLCA) return root;
    return leftLCA ? leftLCA : rightLCA;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node* ans = lca(root, 4, 5);
    cout << "LCA of 4 and 5: " << (ans ? ans->data : -1) << "\n";
    ans = lca(root, 4, 6);
    cout << "LCA of 4 and 6: " << (ans ? ans->data : -1) << "\n";
    return 0;
}
