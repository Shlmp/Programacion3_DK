```c++
#ifndef AVL_TREE_H
#define AVL_TREE_H

//nullptr --> declares a pointer with a null value (think int = 0)

//Libraries
#include<iostream>
#include<iomanip> //da acceso a mas funciones (extrae un valor monetario de un flujo con el formato especificado y devuelve el valor en un parametro)
#include<algorithm>
#include<memory> //obtiene direcion real de un objeto

template <typename T> //Creates template in order to work with any value
class Node {
public:
    T data; //Creates T called data
    int height; //int to store height
    std::shared_ptr<Node<T>> left; //shared pointer for pointing left
    std::shared_ptr<Node<T>> right; //Shared pointer for pointing right

    Node(T data) : data(data), height(1), left(nullptr), right(nullptr) {} //Node definition
};

template <typename T> //Creates template for AVLTree (Balanced)
class AVLTree {
public:
    std::shared_ptr<Node<T>> root; //Pointer for root with values of Node<T>

    AVLTree(): root(nullptr) {} //AVLTree inherits from root

    void add(T data) {
        root = insert(root, data); //Adds to root the current data
    }

    void remove(T data)  {
        root = deleteNode(root, data); //Removes data from root
    }

    void print() {
        if (root != nullptr) {
            print(root, 0); //If root is not empty, prints
        } else {
            std::cout << "The tree is empty." << std::endl; //If root is empty, say it's empty
        }
    }

private:
    void print(std::shared_ptr<Node<T>> node, int indent) {
        if(node) {
            if(node->right) { //Checks if current node has a right node
                print(node->right, indent + 8); //Prints the right child of the current node with an indent of 8, in order to 
            }
            if (indent) { //If indent has value, then sets said value as width
                std::cout << std::setw(indent) << ' '; //setw = setwidth
            }
            if (node->right) {
                std::cout << " / (Right of " << node->data << ")\n" << std::setw(indent) << ' ';
            }
            std::cout << node->data << "\n" ;
            if (node->left) {
                std::cout << std::setw(indent) << ' ' << " \\ (Left of " << node->data << ")\n";
                print(node->left, indent + 8);
            }
        }
    }

    std::shared_ptr<Node<T>> newNode(T data) {
        return std::make_shared<Node<T>>(data);
    }

    std::shared_ptr<Node<T>> rightRotate(std::shared_ptr<Node<T>> y) {
        std::shared_ptr<Node<T>> x = y->left;
        std::shared_ptr<Node<T>> T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right))+1;
        x->height = max(height(x->left), height(x->right))+1;

        return x;
    }

    std::shared_ptr<Node<T>> leftRotate(std::shared_ptr<Node<T>> x) {
        std::shared_ptr<Node<T>> y = x->right;
        std::shared_ptr<Node<T>> T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left),height(x->right))+1;
        y->height = max(height(y->left),height(y->right))+1;

        return y;
    }

    int getBalance(std::shared_ptr<Node<T>> N) {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }

    std::shared_ptr<Node<T>> insert(std::shared_ptr<Node<T>> node, T data) {
        if (node == nullptr)
            return (newNode(data));

        if (data < node->data)
            node->left = insert(node->left, data);
        else if (data > node->data)
            node->right = insert(node->right, data);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && data < node->left->data)
            return rightRotate(node);

        if (balance < -1 && data > node->right->data)
            return leftRotate(node);

        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    std::shared_ptr<Node<T>> minValueNode(std::shared_ptr<Node<T>> node) {
        std::shared_ptr<Node<T>> current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    std::shared_ptr<Node<T>> deleteNode(std::shared_ptr<Node<T>> root, T data) {
        if (!root)
            return root;

        if (data < root->data) {
            root->left = deleteNode(root->left, data);
        }
        else if(data > root->data) {
            root->right = deleteNode(root->right, data);
        }
        else {
            if(!root->left || !root->right) {
                root = (root->left) ? root->left : root->right;
            }
            else {
                std::shared_ptr<Node<T>> temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
                temp.reset();
            }
        }

        if(!root)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    int height(std::shared_ptr<Node<T>> N) {
        if (N == nullptr) //Checks if N exists, if N  then 
            return 0;
        return N->height;
    }

    int max(int a, int b) {
        return (a > b)? a : b;
    }
};

#endif /* AVL_TREE_H */
```