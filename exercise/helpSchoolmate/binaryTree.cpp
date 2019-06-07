#include <iostream>
using namespace std;

struct Node {
    int value;
    struct Node *left, *right;
};

Node* addNewNode(Node* root, int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->left = newNode->right = nullptr;

    if (root == nullptr) {
        root = newNode;
    } else {
        Node *current = root, *next = root;
        bool isRight = false;
        do {
            current = next;
            if (value > current->value) {
                next = current->right;
                isRight = true;
            } else {
                next = current->left;
                isRight = false;
            }
        } while (next);

        if (isRight)
            current->right = newNode;
        else
            current->left = newNode;
    }
    return root;
}

void inorderTraversal(Node* current) {
    if (current) {
        inorderTraversal(current->left);
        cout << current->value << " ";
        inorderTraversal(current->right);
    } else
        return;
}
void postTraversal(Node* current) {
    if (current) {
        postTraversal(current->right);
        cout << current->value << " ";
        postTraversal(current->left);
    } else
        return;
}

int main() {
    Node* root = nullptr;
    int tmp;
    while (cout << "Please input a number: " && cin >> tmp && tmp > 0) {
        root = addNewNode(root, tmp);
    }
    cout << "Sorted!" << endl;
    inorderTraversal(root);
    cout << endl;
    postTraversal(root);
    cout << endl;
    return 0;
}