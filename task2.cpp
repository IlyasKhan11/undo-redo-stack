#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

bool checkChildrenSumProperty(Node* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return true;
    }

    int leftData = (root->left) ? root->left->data : 0;
    int rightData = (root->right) ? root->right->data : 0;

    if (root->data == leftData + rightData &&
        checkChildrenSumProperty(root->left) &&
        checkChildrenSumProperty(root->right)) {
        return true;
    }

    return false;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);

    if (checkChildrenSumProperty(root)) {
        cout << "The tree satisfies the Children Sum Property.\n";
    } else {
        cout << "The tree does not satisfy the Children Sum Property.\n";
    }

    return 0;
}
