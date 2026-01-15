#include <iostream>
#include <vector>

using namespace std;

typedef struct node{
    char value;
    struct node* left;
    struct node* right;
} Node;

typedef struct BT{
    Node* head;
    int size;
} BT;

Node* createNode(char value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void pre_order(Node* head) {
    if (head != NULL) {
        cout << head->value;
        pre_order(head->left);
        pre_order(head->right);
    }
}

void in_order(Node* head) {
    if (head != NULL) {
        in_order(head->left);
        cout << head->value;
        in_order(head->right);
    }
}

void post_order(Node* head) {
    if (head != NULL) {
        post_order(head->left);
        post_order(head->right);
        cout << head->value;
    }
}

Node* search(Node* head, char value) {
    if (head == NULL) return NULL;
    if (head->value == value) return head;
    Node* leftResult = search(head->left, value);
    if (leftResult != NULL) return leftResult;
    return search(head->right, value);
}

int main() {
    int n;
    cin >> n;

    BT* tree = (BT*)malloc(sizeof(BT));
    if (!tree) return 0;
    tree->head = NULL;
    tree->size = 0;

    Node* nodes[26] = {NULL};

    for (int i = 0; i < n; i++) {
        char root, left, right;
        cin >> root >> left >> right;

        Node* rootNode = nodes[root - 'A'];
        if (rootNode == NULL) {
            rootNode = createNode(root);
            nodes[root - 'A'] = rootNode;
            if (tree->head == NULL)
                tree->head = rootNode;
        }

        if (left != '.') {
            if (nodes[left - 'A'] == NULL) {
                nodes[left - 'A'] = createNode(left);
            }
            rootNode->left = nodes[left - 'A'];
        }
        if (right != '.') {
            if (nodes[right - 'A'] == NULL) {
                nodes[right - 'A'] = createNode(right);
            }
            rootNode->right = nodes[right - 'A'];
        }
    }

    pre_order(tree->head);
    cout << "\n";
    in_order(tree->head);
    cout << "\n";
    post_order(tree->head);

    for (int i = 0; i < 26; i++) {
        if (nodes[i]) free(nodes[i]);
    }

    free(tree);

    return 0;
}