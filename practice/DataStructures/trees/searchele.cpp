#include <bits/stdc++.h>
#include "node.h"
using namespace std;

bool findPath(Node* root, int key, vector<int>& path) {
    if (!root) return false;

    path.push_back(root->data);

    if (root->data == key)
        return true;

    if (findPath(root->left, key, path) ||
        findPath(root->right, key, path))
        return true;

    path.pop_back();
    return false;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    int key = 5;
    vector<int> path;

    if (findPath(root, key, path)) {
        cout << "Path: ";
        for (int x : path)
            cout << x << " ";
    } else {
        cout << "Element not found";
    }
    cout << '\n';
}
