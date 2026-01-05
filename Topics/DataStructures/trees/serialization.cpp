#include "tree_node.hpp"
using namespace std;

/*
 * ======================================================================================
 * SERIALIZE AND DESERIALIZE
 * ======================================================================================
 * 
 * Convert tree to string and back.
 * - Use Preorder Traversal.
 * - Use 'X' or '#' for null.
 * 
 * Complexity: O(N)
 * ======================================================================================
 */

// Encodes a tree to a single string.
string serialize(Node* root) {
    if (!root) return "X,";
    string s = to_string(root->data) + ",";
    s += serialize(root->left);
    s += serialize(root->right);
    return s;
}

// Helper for deserialize
Node* deserializeHelper(queue<string>& q) {
    string val = q.front();
    q.pop();
    
    if (val == "X") return nullptr;
    
    Node* root = new Node(stoi(val));
    root->left = deserializeHelper(q);
    root->right = deserializeHelper(q);
    return root;
}

// Decodes your encoded data to tree.
Node* deserialize(string data) {
    queue<string> q;
    string temp;
    stringstream ss(data);
    while (getline(ss, temp, ',')) {
        q.push(temp);
    }
    return deserializeHelper(q);
}

void inorderDebug(Node* root) {
    if(!root) return;
    inorderDebug(root->left);
    cout << root->data << " ";
    inorderDebug(root->right);
}

int main() {
    Node* root = createSampleTree();
    cout << "Original Inorder: "; inorderDebug(root); cout << endl;
    
    string serialized = serialize(root);
    cout << "Serialized: " << serialized << endl;
    
    Node* newRoot = deserialize(serialized);
    cout << "Deserialized Inorder: "; inorderDebug(newRoot); cout << endl;
    
    return 0;
}
