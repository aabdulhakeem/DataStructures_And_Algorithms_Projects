/*
 * Name: Ahmed Abdulhakeem Salah Eldeen
 * Date: 5/14/2024
 */



#include <iostream>
using namespace std;

#ifndef UNTITLED1_BINARYSEARCHTREE_H
#define UNTITLED1_BINARYSEARCHTREE_H

// Define a template struct for a Node in the binary search tree
template <typename T>
struct Node{
    T data;
    Node* left;
    Node* right;
};

// Define the BinarySearchTree class
template <typename T>
class BinarySearchTree {
private:
    Node<T>* root; // Pointer to the root node of the binary search tree

    // Private helper function to print nodes in in-order traversal
    void printInOrder(Node<T>* current){
        if (current != NULL){
            printInOrder(current->left); // Recursively print left subtree
            cout << current->data << "  "; // Print current node
            printInOrder(current->right); // Recursively print right subtree
        }
    }

    // Private helper function to print nodes in reverse in-order traversal
    void printRightInOrder(Node<T>* current){
        if (current != NULL){
            printRightInOrder(current->right); // Recursively print right subtree
            cout << current->data << "  "; // Print current node
            printRightInOrder(current->left); // Recursively print left subtree
        }
    }

    // Private helper function to find a node containing a given item
    Node<T>* found(T item){
        Node<T> *current = NULL;
        current = root;
        if (root == NULL){
            return NULL; // If tree is empty, return NULL
        }
        while (current != NULL){
            if (item == current->data){
                return current; // Return current node if found
            }
            else if (item < current->data){
                current = current->left; // Traverse left subtree
            }
            else {
                current = current->right; // Traverse right subtree
            }
        }
        return NULL; // Return NULL if item not found
    }

public:
    // Constructor to initialize the binary search tree
    BinarySearchTree(){
        root = NULL; // Initialize root to NULL
    }

    // Public function to insert a new item into the binary search tree
    void insert(T item) {
        Node<T> *newNode, *current, *prev;
        newNode = new (nothrow) Node<T>;
        if (newNode == nullptr){
            cerr << "error allocating memory"; // Error message if memory allocation fails
            return;
        }
        newNode->data = item;
        newNode->left = newNode->right = NULL;
        if (root == NULL){
            root = newNode; // If tree is empty, make new node the root
        } else{
            current = root;
            while (current != NULL){
                prev = current;
                if (item <= current->data){
                    current = current->left; // Traverse left subtree
                }
                else
                    current = current->right; // Traverse right subtree
            }
            if (item <= prev->data){
                prev->left = newNode; // Insert new node as left child
            }
            else
                prev->right = newNode; // Insert new node as right child
        }
    }

    // Public function to search for an item in the binary search tree
    bool search(T item){
        Node<T> *current = NULL;
        current = found(item);
        return (current != NULL); // Return true if item is found, false otherwise
    }

    // Public function to remove an item from the binary search tree
    void remove(T item) {
        Node<T> *current = NULL, *prev, *temp;
        current = root;
        if (root == NULL){
            cout << "empty tree"; // Error message if tree is empty
            return;
        }
        while (current != NULL){
            if (item == current->data){
                break; // Exit loop if item is found
            }
            else if (item < current->data){
                prev = current;
                current = current->left; // Traverse left subtree
            }
            else{
                prev = current;
                current = current->right; // Traverse right subtree
            }
        }

        if (current == NULL){
            cout << "item is not found\n"; // Error message if item is not found
            return;
        }
        else if (current->right == NULL && current->left == NULL){
            if (current == root){
                root = NULL; // If current node is root and has no children, set root to NULL
            }
            else {
                if (prev->right == current){
                    prev->right = NULL; // If current node is right child, set parent's right pointer to NULL
                }
                else prev->left = NULL; // If current node is left child, set parent's left pointer to NULL
            }
            delete current; // Delete current node
            current = NULL;
        }
        else if(current->right == NULL){
            if (current == root){
                root = current->left; // If current node is root and has left child only, set root to left child
            }
            else {
                if (prev->right == current){
                    prev->right = current->left; // If current node is right child, set parent's right pointer to current node's left child
                }
                else prev->left = current->left; // If current node is left child, set parent's left pointer to current node's left child
            }
            delete current; // Delete current node
            current = NULL;
        }
        else if(current->left == NULL){
            if (current == root){
                root = current->right; // If current node is root and has right child only, set root to right child
            }
            else {
                if (prev->right == current){
                    prev->right = current->right; // If current node is right child, set parent's right pointer to current node's right child
                }
                else prev->left = current->right; // If current node is left child, set parent's left pointer to current node's right child
            }
            delete current; // Delete current node
            current = NULL;
        }
        else {
            temp = current;
            prev = NULL;
            current = current->right;
            while (current->left != NULL){
                prev = current;
                current = current->left; // Traverse left subtree of current node's right child to find successor
            }
            temp->data = current->data; // Copy data of successor to current node
            if (prev == NULL)
                temp->right = current->right;
            else
                prev->left = current->right;

            delete current; // Delete successor node
            current = NULL;
        }
    }

    // Public function to perform in-order traversal of the binary search tree
    void inOrder(){
        printInOrder(root); // Call private helper function to print in-order traversal
    }

    // Public function to perform reverse in-order traversal of the binary search tree
    void rightInOrder(){
        printRightInOrder(root); // Call private helper function to print reverse in-order traversal
    }

    // Public function to print details of a specific item in the binary search tree
    void print(T item){
        Node<T> *f = found(item);
        if (f != NULL){
            cout << "item: " << f->data << endl;
            (f->left) ? cout << "item->left: " << f->left->data << endl : cout << "item->left is NULL";
            (f->right) ? cout << "item->right: " << f->right->data << endl : cout << "item->right is NULL";
        }
    }
};

#endif //UNTITLED1_BINARYSEARCHTREE_H
