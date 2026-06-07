#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int diameterHelper(Node* root, int& ans) {
    if (!root) return 0;
    int leftHeight = diameterHelper(root->left, ans);
    int rightHeight = diameterHelper(root->right, ans);
    ans = max(ans, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}

int diameter(Node* root) {
    int ans = 0;
    diameterHelper(root, ans);
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    cout << "Diameter: " << diameter(root) << "\n";
    return 0;
}
