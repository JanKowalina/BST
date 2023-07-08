#include <iostream>

// Node structure for the binary search tree
struct Node {
    unsigned int data;
    Node* parent;
    Node* left;
    Node* right;
};

// Add a node with the given key to the tree
Node* AddNode(unsigned int key, Node* root) {
    Node* newNode = new Node;
    newNode->data = key;
    newNode->right = nullptr;
    newNode->left = nullptr;

    if (root == nullptr) {
        newNode->parent = nullptr;
        return newNode;
    } else {
        Node* tmp = root;
        Node* parent = root;
        while (tmp != nullptr) {
            parent = tmp;
            if (key < tmp->data)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
        newNode->parent = parent;
        if (key < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        return root;
    }
}

// Find the minimum node in the tree starting from the given cell
Node* Minimum(Node* cell) {
    while (cell->left != nullptr)
        cell = cell->left;
    return cell;
}

// Find the successor node of the given cell in the tree
Node* Successor(Node* cell) {
    if (cell->right != nullptr)
        return Minimum(cell->right);
    Node* tmp = cell->parent;
    while (tmp != nullptr && cell != tmp->right) {
        cell = tmp;
        tmp = tmp->parent;
    }
    return tmp;
}

// Remove the node with the given key from the tree
Node* RemoveNode(unsigned int key, Node* root) {
    Node* tmp = root;
    while (tmp != nullptr && tmp->data != key) {
        if (key < tmp->data)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }

    if (tmp != nullptr) {
        Node* ret = root;
        Node* todel = tmp;

        if (tmp->left != nullptr && tmp->right != nullptr)
            todel = Successor(tmp);

        Node* son = (todel->left != nullptr) ? todel->left : todel->right;

        if (son != nullptr)
            son->parent = todel->parent;

        if (todel->parent == nullptr)
            ret = son;
        else if (todel == todel->parent->left)
            todel->parent->left = son;
        else
            todel->parent->right = son;

        if (todel != tmp)
            tmp->data = todel->data;

        if (todel->parent != nullptr) {
            if (todel == todel->parent->left)
                todel->parent->left = nullptr;
            else
                todel->parent->right = nullptr;
        }

        delete todel;
        return ret;
    }
    return root;
}

// Search for a node with the given key in the tree
bool SearchNode(unsigned int key, Node* root) {
    Node* tmp = root;
    while (tmp != nullptr && tmp->data != key) {
        if (key < tmp->data)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    return tmp != nullptr;
}

// Find the minimum key in the tree
unsigned int MinNode(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

// Find the maximum key in the tree
unsigned int MaxNode(Node* root) {
    while (root->right != nullptr) {
        root = root->right;
    }
    return root->data;
}

// Deallocate the memory occupied by the tree
void DeallocateTree(Node* root) {
    if (root != nullptr) {
        DeallocateTree(root->left);
        DeallocateTree(root->right);
        delete root;
    }
}

int main() {
    char c;
    unsigned int i;
    Node* root = nullptr;
    std::cin >> c;
    while (c != 'q') {
        switch (c) {
            case '+':
                std::cin >> i;
                root = AddNode(i, root);
                break;
            case '-':
                std::cin >> i;
                root = RemoveNode(i, root);
                break;
            case '?':
                std::cin >> i;
                std::cout << SearchNode(i, root) << std::endl;
                break;
            case 'm':
                std::cout << MinNode(root) << std::endl;
                break;
            case 'M':
                std::cout << MaxNode(root) << std::endl;
                break;
        }
        std::cin >> c;
    }
    DeallocateTree(root);
    return 0;
}
