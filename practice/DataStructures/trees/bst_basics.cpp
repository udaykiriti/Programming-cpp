#include "tree_node.hpp"
using namespace std;

/*
 * ======================================================================================
 * BINARY SEARCH TREE (BST) BASICS
 * ======================================================================================
 * 
 * 1. Insert: O(H)
 * 2. Search: O(H) (O(N) in worst case skew tree, O(log N) in balanced)
 * 3. Validate BST: Check if every node is within valid range (min, max).
 * 
 * ======================================================================================
 */

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

Node* search(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

// Validation using Min/Max range
bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isValidBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
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
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder (Sorted): "; inorder(root); cout << endl;

    if (search(root, 60)) cout << "Found 60" << endl;
    else cout << "Not Found 60" << endl;

    if (isValidBST(root)) cout << "Valid BST" << endl;
    else cout << "Invalid BST" << endl;

    return 0;
}
