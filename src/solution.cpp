#include "solution.h"
#include <iostream>


void printBTRec(const std::string& prefix, const Node* node, bool isRight){
    if( node != nullptr ){
        std::cout << prefix;
        std::cout << (isRight ? "├── " : "└── " );
        std::cout << node->data << std::endl;  // print the value of the node

        // enter the next tree level - left and right branch
        printBTRec( prefix + (isRight ? "│   " : "    "), node->right, node->left != nullptr);
        printBTRec( prefix + (isRight ? "│   " : "    "), node->left, false);
    }
}
void printBT(const Node* node){
    printBTRec("", node, false);
}

///
///
/// insert

int getHeight(Node* node){
    if(node == nullptr) return 0;
    return node->height;
}
int getBalance(Node* node){
    if(node == nullptr) return 0;
    return getHeight(node->right) - getHeight(node->left);
}

Node* rotateLeft(Node* node){
    Node* tempR = node->right;
    Node* temp2 = tempR->left;

    tempR->left = node;
    node->right = temp2;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    tempR->height = 1 + max(getHeight(tempR->left), getHeight(tempR->right));

    return tempR;
}
Node* rotateRight(Node* node){
    Node* tempL = node->left;
    Node* temp2 = tempL->right;

    tempL->right = node;
    node->left = temp2;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    tempL->height = 1 + max(getHeight(tempL->left), getHeight(tempL->right));

    return tempL;
}

Node* insertAVL(Node* node, int value){
    if(node == nullptr) return new Node(value);
    else if(value < node->data) node->left = insertAVL(node->left, value);
    else node->right = insertAVL(node->right, value);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    //node->height = calcHeight(node);

    int balance = getBalance(node);

    if(balance < -1 && value < node->left->data){
        return rotateRight(node);
    }
    if(balance > 1 && value > node->right->data){
        return rotateLeft(node);
    }
    if(balance < -1 && value > node->left->data){
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if(balance > 1 && value < node->right->data){
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}