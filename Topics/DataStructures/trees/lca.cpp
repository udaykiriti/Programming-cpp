#include "tree_node.hpp"
using namespace std;

/*
 * ======================================================================================
 * LOWEST COMMON ANCESTOR (LCA)
 * ======================================================================================
 * 
 * Problem: Find the lowest node that is an ancestor of both n1 and n2.
 * Assumption: Both n1 and n2 assume to be present.
 * 
 * Algorithm:
 * 1. Base Case: If root is null, return null.
 * 2. If root is n1 or n2, return root (found one).
 * 3. Search left and right subtrees.
 * 4. If both return non-null, root is the LCA.
 * 5. If one returns non-null, pass it up.
 * 
 * Complexity: O(N) Time, O(H) Space.
 * ======================================================================================
 */

Node* findLCA(Node* root, int n1, int n2) {
    if (!root) return nullptr;

    // If either n1 or n2 matches root, this root is the LCA (or ancestor of LCA)
    if (root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLCA = findLCA(root->left, n1, n2);
    Node* rightLCA = findLCA(root->right, n1, n2);

    // If both return non-null, n1 is in one subtree and n2 in other. Root is LCA.
    if (leftLCA && rightLCA) {
        return root;
    }

    // Otherwise return the non-null child (or null if both null)
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int main() {
    Node* root = createSampleTree();
    
    int n1 = 4, n2 = 5;
    Node* lca = findLCA(root, n1, n2);
    if(lca) cout << "LCA of " << n1 << " and " << n2 << " is " << lca->data << endl;
    else cout << "LCA not found" << endl;

    n1 = 4; n2 = 3;
    lca = findLCA(root, n1, n2);
    if(lca) cout << "LCA of " << n1 << " and " << n2 << " is " << lca->data << endl;

    return 0;
}
