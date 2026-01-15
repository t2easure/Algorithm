#include <iostream>
#include <map>
#include <set>

using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BinaryTree {
public:
    map<int, Node*> nodes;

    ~BinaryTree() {
        for (auto& pair : nodes) {
            delete pair.second;
        }
    }

    Node* ensureNode(int value) {
        if (nodes.count(value) == 0) {
            nodes[value] = new Node(value);
        }
        return nodes[value];
    }

    void insert(int root, int left, int right) {
        Node* rootNode = ensureNode(root);
        if (left != -1) {
            Node* leftNode = ensureNode(left);
            rootNode->left = leftNode;
            leftNode->parent = rootNode;
        }
        if (right != -1) {
            Node* rightNode = ensureNode(right);
            rootNode->right = rightNode;
            rightNode->parent = rootNode;
        }
    }

    Node* findLastNode(Node* node) {
        Node* last = nullptr;
        inorder(node, last);
        return last;
    }

    void inorder(Node* node, Node*& last) {
        if (node == nullptr) return;
        inorder(node->left, last);
        last = node;
        inorder(node->right, last);
    }

    int traversal(Node* root) {
        if (root == nullptr) return 0;
        Node* lastNode = findLastNode(root);

        set<Node*> visited;
        Node* current = root;
        int moves = 0;

        while (current != nullptr) {
            visited.insert(current);

            if (current->left && visited.find(current->left) == visited.end()) {
                current = current->left;
            } else if (current->right && visited.find(current->right) == visited.end()) {
                current = current->right;
            } else if (current == lastNode) {
                break;
            } else {
                current = current->parent;
            }
            moves++;
        }

        return moves;
    }
};

int main() {
    int n;
    cin >> n;

    BinaryTree tree;
    for (int i = 0; i < n; i++) {
        int root, left, right;
        cin >> root >> left >> right;
        tree.insert(root, left, right);
    }

    int result = tree.traversal(tree.nodes[1]);
    cout << result << "\n";

    return 0;
}
