#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int key) {
        if (node == nullptr) return new Node(key);
        if (key < node->key) node->left = insert(node->left, key);
        else node->right = insert(node->right, key);

        return node;
    }

    void _traversal(Node* node) {
        if (node != nullptr) {
            _traversal(node->left);
            _traversal(node->right);
            cout << node->key << "\n";
        }
    }

    void _destroy(Node* node) {
        if (node != nullptr) {
            _destroy(node->left);
            _destroy(node->right);
            delete node;
        }
    }
public:
    BST() : root(nullptr) {}

    ~BST() { _destroy(root); }

    void _insert(int key) { root = insert(root, key); }

    void traversal() { _traversal(root); }
};

int main() {
    BST bst;
    int key;
    while (cin >> key) bst._insert(key);

    bst.traversal();

    return 0;
}