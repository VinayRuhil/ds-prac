7. Write a program to implement insert and search operation in AVL trees 

 

 

#include <iostream> 
#include <algorithm> 
using namespace std; 
class AVLNode { 
public: 
    int key; 
    int height; 
    AVLNode* left; 
    AVLNode* right; 
 

AVLNode(int k) : key(k), height(1), left(nullptr), right(nullptr) {} 
}; 
 

class AVLTree { 
private: 
    AVLNode* root; 
 

int height(AVLNode* node) { 
        if (node == nullptr) 
            return 0; 
        return node->height; 
    } 
 

int balanceFactor(AVLNode* node) { 
        if (node == nullptr) 
            return 0; 
        return height(node->left) - height(node->right); 
    } 
 

void updateHeight(AVLNode* node) { 
        if (node != nullptr) 
            node->height = 1 + std::max(height(node->left), height(node->right)); 
    } 
 

AVLNode* rotateRight(AVLNode* y) { 
        AVLNode* x = y->left; 
        AVLNode* T2 = x->right; 
 

x->right = y; 
        y->left = T2; 
 

updateHeight(y); 
        updateHeight(x); 
 

return x; 
    } 
 

AVLNode* rotateLeft(AVLNode* x) { 
        AVLNode* y = x->right; 
        AVLNode* T2 = y->left; 
 

y->left = x; 
        x->right = T2; 
 

updateHeight(x); 
        updateHeight(y); 
 

return y; 
    } 
 

AVLNode* insert(AVLNode* root, int key) { 
        if (root == nullptr) 
            return new AVLNode(key); 
 

if (key < root->key) 
            root->left = insert(root->left, key); 
        else if (key > root->key) 
            root->right = insert(root->right, key); 
        else 
            return root; // Duplicate keys not allowed 
 

updateHeight(root); 
 

int balance = balanceFactor(root); 
 

// Perform rotations if needed 
        // Left Left Case 
        if (balance > 1 && key < root->left->key) 
            return rotateRight(root); 
 

// Right Right Case 
        if (balance < -1 && key > root->right->key) 
            return rotateLeft(root); 
 

// Left Right Case 
        if (balance > 1 && key > root->left->key) { 
            root->left = rotateLeft(root->left); 
            return rotateRight(root); 
        } 
 

// Right Left Case 
        if (balance < -1 && key < root->right->key) { 
            root->right = rotateRight(root->right); 
            return rotateLeft(root); 
        } 
 

return root; 
    } 
 

AVLNode* search(AVLNode* root, int key) { 
        if (root == nullptr || root->key == key) 
            return root; 
 

if (key < root->key) 
            return search(root->left, key); 
 

return search(root->right, key); 
    } 
 

public: 
    AVLTree() : root(nullptr) {} 
 

void insertKey(int key) { 
        root = insert(root, key); 
    } 
 

bool searchKey(int key) { 
        AVLNode* result = search(root, key); 
        return (result != nullptr); 
    } 
 

void printInOrder(AVLNode* root) { 
        if (root != nullptr) { 
            printInOrder(root->left); 
            cout << root->key << " "; 
            printInOrder(root->right); 
        } 
    } 
 

void printTree() { 
        cout << "In-order traversal of AVL tree: "; 
        printInOrder(root); 
        cout << endl; 
    } 
}; 
 

int main() { 
    AVLTree avl; 
 

int choice, key; 
 

do { 
        cout << "\nAVL Tree Operations:"<<endl; 
        cout << "1. Insert Key"<<endl; 
        cout << "2. Search Key"<<endl; 
        cout << "3. Print AVL Tree"<<endl; 
        cout << "4. Exit"<<endl; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 

switch (choice) { 
            case 1: 
                cout << "Enter key to insert: "; 
                cin >> key; 
                avl.insertKey(key); 
                break; 
            case 2: 
                cout << "Enter key to search: "; 
                cin >> key; 
                if (avl.searchKey(key)) 
                    cout << "Key " << key << " found in AVL tree." << endl; 
                else 
                    cout << "Key " << key << " not found in AVL tree." << endl; 
                break; 
            case 3: 
                avl.printTree(); 
                break; 
            case 4: 
                cout << "Exiting program"; 
                break; 
            default: 
                cout << "Invalid choice"; 
        } 
    } while (choice != 4); 
 

return 0; 
} 

 
