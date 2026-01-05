#include "tree_node.hpp"
using namespace std;

/*
 * ======================================================================================
 * TREE TRAVERSALS
 * ======================================================================================
 * 
 * 1. Preorder  (Root -> Left -> Right)
 * 2. Inorder   (Left -> Root -> Right)
 * 3. Postorder (Left -> Right -> Root)
 * 4. Level Order (Breadth First Search)
 * 
 * Time Complexity: O(N) for all traversals (visiting each node once).
 * Space Complexity: 
 *    - O(H) for recursive/iterative DFS (H = height of tree).
 *    - O(W) for BFS (W = max width of tree), can be O(N/2) in last level.
 * 
 * ======================================================================================
 */

// 1. Recursive Preorder
void preorderRecursive(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

// 2. Recursive Inorder
void inorderRecursive(Node* root) {
    if (!root) return;
    inorderRecursive(root->left);
    cout << root->data << " ";
    inorderRecursive(root->right);
}

// 3. Recursive Postorder
void postorderRecursive(Node* root) {
    if (!root) return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    cout << root->data << " ";
}

// 4. Iterative Preorder
// Uses Stack. Push root, then Right child, then Left child.
void preorderIterative(Node* root) {
    if (!root) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        cout << curr->data << " ";
        // Push right first so left is processed first
        if (curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);
    }
}

// 5. Iterative Inorder
// Uses Stack. Go left as much as possible, pushing to stack. Then pop, print, go right.
void inorderIterative(Node* root) {
    stack<Node*> s;
    Node* curr = root;
    while (curr || !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

// 6. Level Order Traversal (BFS)
// Uses Queue. Push root. While queue not empty, pop, print, push left, push right.
void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    Node* root = createSampleTree();
    
    cout << "Tree Structure:\n    1\n   / \\\n  2   3\n / \\\n4   5\n\n";

    cout << "Recursive Preorder:  "; preorderRecursive(root); cout << endl;
    cout << "Recursive Inorder:   "; inorderRecursive(root); cout << endl;
    cout << "Recursive Postorder: "; postorderRecursive(root); cout << endl;
    cout << "---------------------\n";
    cout << "Iterative Preorder:  "; preorderIterative(root); cout << endl;
    cout << "Iterative Inorder:   "; inorderIterative(root); cout << endl;
    cout << "Level Order (BFS):   "; levelOrder(root); cout << endl;

    return 0;
}
