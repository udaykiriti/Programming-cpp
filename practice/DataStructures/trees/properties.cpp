#include "tree_node.hpp"
using namespace std;

/*
 * ======================================================================================
 * TREE PROPERTIES: Height, Diameter, Balanced Check
 * ======================================================================================
 * 
 * 1. Height (Max Depth): Number of nodes on longest path from root to leaf.
 *    - Complexity: O(N)
 * 2. Diameter: Longest path between any two nodes. Path may/may not pass through root.
 *    - Naive O(N^2): Height at every node.
 *    - Optimized O(N): Calculate height and update diameter in same recursion.
 * 3. Check Balanced: Height of left and right subtrees differ by at most 1 for all nodes.
 *    - Optimized O(N): Return -1 if unbalanced, else return height.
 * 
 * ======================================================================================
 */

// 1. Height
int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// 2. Diameter (Optimized O(N))
// Returns height, but updates 'ans' with max diameter found so far.
int diameterRec(Node* root, int& ans) {
    if (!root) return 0;
    
    int lh = diameterRec(root->left, ans);
    int rh = diameterRec(root->right, ans);
    
    // Diameter passing through this node = left height + right height + 1
    ans = max(ans, lh + rh + 1);
    
    return 1 + max(lh, rh);
}

int diameter(Node* root) {
    int ans = 0;
    diameterRec(root, ans);
    return ans;
}

// 3. Check Balanced (Optimized O(N))
// Returns height if balanced, -1 if unbalanced.
int checkBalanced(Node* root) {
    if (!root) return 0;
    
    int lh = checkBalanced(root->left);
    if (lh == -1) return -1;
    
    int rh = checkBalanced(root->right);
    if (rh == -1) return -1;
    
    if (abs(lh - rh) > 1) return -1;
    
    return 1 + max(lh, rh);
}

bool isBalanced(Node* root) {
    return checkBalanced(root) != -1;
}

int main() {
    Node* root = createSampleTree();
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    cout << "Height: " << height(root) << endl;     // Expect 3
    cout << "Diameter: " << diameter(root) << endl; // Expect 4 (4-2-1-3 or 5-2-1-3)
    
    if (isBalanced(root)) cout << "Tree is Balanced" << endl;
    else cout << "Tree is NOT Balanced" << endl;

    return 0;
}
