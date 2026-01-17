#include "tree_node.hpp"
using namespace std;

/*
 * ======================================================================================
 * SYMMETRIC & MIRROR TREES
 * ======================================================================================
 * 
 * 1. Symmetric Tree: Checks if tree is a mirror of itself.
 * 2. Invert/Mirror Tree: Physically swaps all left/right children.
 * 
 * Complexity: O(N)
 * ======================================================================================
 */

// 1. Symmetric Check
bool isMirror(Node* node1, Node* node2) {
    if (!node1 && !node2) return true;
    if (!node1 || !node2) return false;
    
    return (node1->data == node2->data) &&
           isMirror(node1->left, node2->right) &&
           isMirror(node1->right, node2->left);
}

bool isSymmetric(Node* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

// 2. Invert Binary Tree
Node* invertTree(Node* root) {
    if (!root) return nullptr;
    
    Node* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    
    return root;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);
    
    cout << "Is Symmetric: " << (isSymmetric(root) ? "Yes" : "No") << endl;
    
    root = invertTree(root);
    cout << "Inverted Tree logic executed." << endl;

    return 0;
}
