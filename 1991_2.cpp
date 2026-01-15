#include <iostream>
#include <vector>

using namespace std;

class Node { 
public:
    char value;
    Node* left;
    Node* right;
    Node(char val) : value(val), left(nullptr), right(nullptr) {} 
};

class BinaryTree {
public:
    Node* head;
    int size;

    BinaryTree() : head(nullptr), size(0) {}
    ~BinaryTree() { clear(head); }

    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    void insert(char root, char left, char right) {
        Node* rootNode = search(head, root);
        if (!rootNode) {
            rootNode = new Node(root);
            if (!head) head = rootNode;
            size += 1;
        }

        if (left != '.') {
            Node* leftNode = search(head, left);
            if (!leftNode) {
                leftNode = new Node(left);
                size += 1;
            }
            rootNode->left = leftNode;
        }

        if (right != '.') {
            Node* rightNode = search(head, right);
            if (!rightNode) {
                rightNode = new Node(right);
                size += 1;
            }
            rootNode->right = rightNode;
        }
    }

    Node* search(Node* node, char value) {
        if (!node) return nullptr;
        if (node->value == value) return node;
        Node* foundNode = search(node->left, value);
        if (foundNode) return foundNode;
        return search(node->right, value);
    }

    void preOrder(Node* node) {
        if (node != nullptr) {
            cout << node->value;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->value;
            inOrder(node->right);
        }
    }

    void postOrder(Node* node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->value;
        }
    }
};

int main() {
    int n;
    cin >> n;

    BinaryTree tree;

    for (int i = 0; i < n; i++) {  
        char root, left, right;
        cin >> root >> left >> right;
        tree.insert(root, left, right);
    }

    tree.preOrder(tree.head);
    cout << "\n";
    tree.inOrder(tree.head);
    cout << "\n";
    tree.postOrder(tree.head);

    return 0;
}