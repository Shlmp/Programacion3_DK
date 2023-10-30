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
    //shared_ptr -> puntero especial donde dos punteros pueden apuntar al mismo espacio de memoria
    std::shared_ptr<Node<T>> left; //shared pointer for pointing left, 
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
//indent -> moves 8 spaces every time
/*
ex1
	ex2
		ex3
			ex4
*/
    void print(std::shared_ptr<Node<T>> node, int indent) {
        if(node) {
            if(node->right) { //Checks if current node has a right node and moves to it
                print(node->right, indent + 8); //Prints the right child of the current node with an indent of 8, in order to 
            }
            if (indent) { //If indent has value, then sets said value as width
                std::cout << std::setw(indent) << ' '; //setw = setwidth
            }
            if (node->right) { //Checks if current node has a right node and moves to it 
                std::cout << " / (Right of " << node->data << ")\n" << std::setw(indent) << ' '; //Prints the right side of the current data
            }
            std::cout << node->data << "\n" ; //Prints the data
            if (node->left) { //Checks if current node has a left node and moves to it
                std::cout << std::setw(indent) << ' ' << " \\ (Left of " << node->data << ")\n"; //Prints the left side of the current data 
                print(node->left, indent + 8);
            }
        }
    }

//Creates new node
    std::shared_ptr<Node<T>> newNode(T data) {
        return std::make_shared<Node<T>>(data);
    }

/*ROTATIONS FOR REBALANCING*/
//Rotates clockwise the desired node
    std::shared_ptr<Node<T>> rightRotate(std::shared_ptr<Node<T>> y) {
        std::shared_ptr<Node<T>> x = y->left; //Assigns x the value of y->left (left child of y)
        std::shared_ptr<Node<T>> T2 = x->right; //Assigns T2 the value of x->right (right child of x)

        x->right = y; //Assigns y to the right child of x
        y->left = T2; //Assigns T2 to the left child of y

        y->height = max(height(y->left), height(y->right))+1; //Recalculates the height of y
        x->height = max(height(x->left), height(x->right))+1; //Recalculates the height of x

        return x;
    }

//Rotates anti-clockwise the desired node
    std::shared_ptr<Node<T>> leftRotate(std::shared_ptr<Node<T>> x) {
        std::shared_ptr<Node<T>> y = x->right; //Assigns y the value of x->right
        std::shared_ptr<Node<T>> T2 = y->left; //Assigns T2 the value of y->left

        y->left = x; //Assigns x to the left child of y
        x->right = T2; //Assigns T2 to the right child of x

        x->height = max(height(x->left),height(x->right))+1; //Recalculates the height of x
        y->height = max(height(y->left),height(y->right))+1; //Recalculates the height of y

        return y;
    }

    int getBalance(std::shared_ptr<Node<T>> N) { 
        if (N == nullptr) //If node is null returns 0 as balance
            return 0;
        return height(N->left) - height(N->right); //If node is not null, substracts the height of left side - height of right side
    }

    std::shared_ptr<Node<T>> insert(std::shared_ptr<Node<T>> node, T data) {
        if (node == nullptr) //If node is null, creates new node with assigned data
            return (newNode(data));

        if (data < node->data) //Checks if data is less than the data on node
            node->left = insert(node->left, data); //If yes, left child of node is assigned a new node with said data
        else if (data > node->data) //If previous condition is not met, checks if data is more than data on node
            node->right = insert(node->right, data); //If yes, right child of node is assigned a new node with said data
        else
            return node; //Returns node if no previous condition is met

        node->height = 1 + max(height(node->left), height(node->right)); //Recalculates height after insertion

        int balance = getBalance(node); //Creates int variable to check balance using the substraction previously defined

        if (balance > 1 && data < node->left->data) //If balance is more than 1 AND data is less than data on left child of node
            return rightRotate(node); //Rotates clockwise in said node

        if (balance < -1 && data > node->right->data) //If balance is less than -1 AND data is more than data on right child of node
            return leftRotate(node); //Rotates anti-clockwise in said node

        if (balance > 1 && data > node->left->data) { //If balance is more than 1 AND data is more than data on left child of node
            node->left = leftRotate(node->left); //Rotates anti-clockwise on left child of node and assigns new value of rotation to node
            return rightRotate(node); //Rotates clockwise in said node (with left rotation)
        }

        if (balance < -1 && data < node->right->data) { //If balance is more than -1 AND data is less than data on right child of node
            node->right = rightRotate(node->right); //Rotates clockwise on right child of node and assigns new value of rotation to node
	            return leftRotate(node); //Rotates anti-clockwise in said node (with right rotation)
        }

        return node; //Returns node with rotation
    }

    std::shared_ptr<Node<T>> minValueNode(std::shared_ptr<Node<T>> node) {
        std::shared_ptr<Node<T>> current = node; //Declares a new node called current with value of current node

        while (current->left != nullptr) //While current node's left child is not null
            current = current->left; //Declares current node as its left child

        return current; //Returns current node
    }

    std::shared_ptr<Node<T>> deleteNode(std::shared_ptr<Node<T>> root, T data) {
        if (!root) //Checks if root is empty
            return root; //If yes, returns root (nullptr) since nothing is there

        if (data < root->data) { //If data is less than data on root
            root->left = deleteNode(root->left, data); //On the left child of node, deletes left node
        }
        else if(data > root->data) { //If data is more than data on root
            root->right = deleteNode(root->right, data); //On the right child of node, deletes right node
        }
        else {
            if(!root->left || !root->right) { //Checks if left or right child of root is empty
                root = (root->left) ? root->left : root->right; //If left child of root exists, assigns to root left child of root. If not, assigns right child of root
            }
            else {
                std::shared_ptr<Node<T>> temp = minValueNode(root->right); //Assigns to temp Node the minValue of the right side of the root
                root->data = temp->data; //Assigns to data on root the data on temp
                root->right = deleteNode(root->right, temp->data); //Deletes on right side of node de data of temp 
                temp.reset(); //Resets temp
            }
        }

        if(!root) //Checks if root exists
            return root; //Returns root (nullptr)

        root->height = 1 + max(height(root->left), height(root->right)); //Recalculates height after deletion

        int balance = getBalance(root); //Creates int for balance from root

        if (balance > 1 && getBalance(root->left) >= 0) //If balance is more than 1 AND balance of left child of root is more or equal to 0
            return rightRotate(root); //Rotates clockwise in root

        if (balance < -1 && getBalance(root->right) <= 0) //If balance is less than -1 AND balance of right child of root is less or equal to 0
            return leftRotate(root); //Rotates anti-clockwise in root

        if (balance > 1 && getBalance(root->left) < 0) { //If balance is more than 1 AND balance of left child of root is less than 0
            root->left = leftRotate(root->left); //Rotates anti-clockwise in left child of root
            return rightRotate(root); //Rotates clockwise in root
        }

        if (balance < -1 && getBalance(root->right) > 0) { //If balance is less than -1 AND balance of right child of root is more than 0
            root->right = rightRotate(root->right); //Rotates clockwise in right child of root
            return leftRotate(root); //Rotates anti-clockwise in root
        }

        return root; //Return root after rotation
    }

    int height(std::shared_ptr<Node<T>> N) {
        if (N == nullptr) //Checks if N is null, if yes then returns 0
            return 0;
        return N->height; //If not, returns height of N
    }

    int max(int a, int b) {
        return (a > b)? a : b; //Checks if a is more than b. If yes, returns a. If not, returns b
    }
};

#endif /* AVL_TREE_H */