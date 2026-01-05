#include "tree_node.hpp"
using namespace std;

/*
 * ======================================================================================
 * TREE PATH SUM PROBLEMS
 * ======================================================================================
 * 
 * 1. Has Path Sum: Check if root-to-leaf path sums to target.
 * 2. Maximum Path Sum (Hard): Max sum of ANY path between ANY two nodes.
 * 
 * Complexity: O(N)
 * ======================================================================================
 */

// 1. Root to Leaf Path Sum
bool hasPathSum(Node* root, int targetSum) {
    if (!root) return false;
    
    targetSum -= root->data;
    
    // Check if leaf and sum is 0
    if (!root->left && !root->right) 
        return targetSum == 0;
        
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

// 2. Maximum Path Sum (Any to Any)
// Returns max path sum starting from root downwards (for parent usage),
// but updates global 'maxi' with the actual max path sum found.
int maxPathDown(Node* root, int& maxi) {
    if (!root) return 0;
    
    // Ignore negative sums (take 0 instead)
    int leftS = max(0, maxPathDown(root->left, maxi));
    int rightS = max(0, maxPathDown(root->right, maxi));
    
    // Path passing through this root
    maxi = max(maxi, leftS + rightS + root->data);
    
    // Return max path extending downwards
    return max(leftS, rightS) + root->data;
}

int maxPathSum(Node* root) {
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);
    
    cout << "Has Path Sum 21? " << (hasPathSum(root, 21) ? "Yes" : "No") << endl;
    cout << "Max Path Sum: " << maxPathSum(root) << endl; // Expect 42 (20 + 2 + 10 + 10)

    return 0;
}
