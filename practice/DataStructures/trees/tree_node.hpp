#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <climits>
#include <sstream>
#include <string>

/*
 * Shared Binary Tree Node Structure
 * Used across all tree interview question modules.
 */
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function to create a simple sample tree
//       1
//      / \
//     2   3
//    / \
//   4   5
inline Node* createSampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return root;
}

#endif // TREE_NODE_HPP
