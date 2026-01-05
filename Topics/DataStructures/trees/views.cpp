#include "tree_node.hpp"
using namespace std;

/*
 * ======================================================================================
 * TREE VIEWS
 * ======================================================================================
 * 
 * 1. Left View: First node at each level.
 * 2. Right View: Last node at each level.
 * 3. Top View: First node at each horizontal distance.
 * 4. Bottom View: Last node at each horizontal distance.
 * 
 * Complexity: O(N) Time, O(N) Space.
 * ======================================================================================
 */

// 1. Left View (Using Recursion/DFS)
// Keep track of max level visited. If current level > max level, print node.
void leftViewUtil(Node* root, int level, int* max_level) {
    if (!root) return;
    if (*max_level < level) {
        cout << root->data << " ";
        *max_level = level;
    }
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}

void printLeftView(Node* root) {
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}

// 2. Right View (Using Recursion/DFS)
// Same as Left View, but visit Right child before Left child.
void rightViewUtil(Node* root, int level, int* max_level) {
    if (!root) return;
    if (*max_level < level) {
        cout << root->data << " ";
        *max_level = level;
    }
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}

void printRightView(Node* root) {
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

// 3. Top View (Using BFS + Map)
// Map stores pair <horizontal_distance, Node->data>.
// For Top View, we only store the first node found at each HD.
void printTopView(Node* root) {
    if (!root) return;
    map<int, int> m; // HD -> Data
    queue<pair<Node*, int>> q; // Node, HD
    
    q.push({root, 0});
    while (!q.empty()) {
        auto p = q.front();
        Node* curr = p.first;
        int hd = p.second;
        q.pop();

        if (m.find(hd) == m.end()) {
            m[hd] = curr->data;
        }

        if (curr->left) q.push({curr->left, hd - 1});
        if (curr->right) q.push({curr->right, hd + 1});
    }

    for (auto i : m) cout << i.second << " ";
}

// 4. Bottom View (Using BFS + Map)
// For Bottom View, we update the map at every node with the same HD.
// The last node processed at a given HD will remain in the map.
void printBottomView(Node* root) {
    if (!root) return;
    map<int, int> m;
    queue<pair<Node*, int>> q;
    
    q.push({root, 0});
    while (!q.empty()) {
        auto p = q.front();
        Node* curr = p.first;
        int hd = p.second;
        q.pop();

        m[hd] = curr->data; // Always replace

        if (curr->left) q.push({curr->left, hd - 1});
        if (curr->right) q.push({curr->right, hd + 1});
    }

    for (auto i : m) cout << i.second << " ";
}

int main() {
    Node* root = createSampleTree();
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    cout << "Left View:   "; printLeftView(root); cout << endl;
    cout << "Right View:  "; printRightView(root); cout << endl;
    cout << "Top View:    "; printTopView(root); cout << endl;
    cout << "Bottom View: "; printBottomView(root); cout << endl;

    return 0;
}
