#include "solution.h"
#include <iostream>


///
///
/// arr to tree

Node* arrToTree(const int* sorted_data, int size){
    if(size <= 0) return nullptr;
    Node* node = new Node(sorted_data[size/2]);
    node->left = arrToTree(sorted_data, size/2);
    node->right = arrToTree(sorted_data + (size/2) + 1, (size/2) + (size%2 - 1));
    return node;
}

///
///
/// release

void releaseAVL(Node* node){
    if(node == nullptr) return;
    releaseAVL(node->left);
    releaseAVL(node->right);
    delete node;
}

///
///
/// tree to arr

int treeToArr(Node* node, int* result){
    if(node == nullptr) return 0;
    int resLen = 1 + treeToArr(node->left, result+1) + treeToArr(node->right, result+1);
    return resLen;
}

///
///
/// exercise to print trees

void printBTRec(const std::string& prefix, const Node* node, bool isRight){
    if( node != nullptr ){
        cout << prefix;
        cout << (isRight ? "├── " : "└── " );
        cout << node->data << std::endl;  // print the value of the node

        // if a node is a dead end go back
        if(node->left == nullptr && node->right == nullptr) return;

        // if a node has at least one child enter the next tree level - left and right branch
        printBTRec( prefix + (isRight ? "│   " : "    "), node->right, true);
        printBTRec( prefix + (isRight ? "│   " : "    "), node->left, false);
    } else {
        cout << prefix;
        cout << (isRight ? "├── " : "└── " );
        cout << "x" << std::endl;
        // print x on nullptr when a node has a single child
        // if I don't do this then it's not possible to tell whether a single child is left or right
    }
}
void printBT(const Node* node){
    printBTRec("", node, false);
}

///
///
/// exercise for avl tree insertion/deletion

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

Node* maxValueNode(Node* node){
    if(node->right == nullptr) return node;
    else return maxValueNode(node->right);
}

Node* rebalanceAVL(Node* node, int value){
    int balance = getBalance(node);

    if(balance < -1 && value < node->left->data) return rotateRight(node);

    if(balance > 1 && value > node->right->data) return rotateLeft(node);

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

Node* insertAVL(Node* node, int value){
    if(node == nullptr) return new Node(value);
    else if(value < node->data) node->left = insertAVL(node->left, value);
    else node->right = insertAVL(node->right, value);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    return rebalanceAVL(node, value);
}

Node* removeAVL(Node* node, int value){
    if(node == nullptr) return node;
    if(value < node->data) removeAVL(node->left, value);
    else if(value > node->data) removeAVL(node->right, value);
    else{
        if(node->left == nullptr || node->right == nullptr){
            Node* temp;
            if(node->left == nullptr) temp = node->right;
            else temp = node->left;

            if(temp == nullptr){ // case when both left and right are null
                temp = node;
                node = nullptr;
            } else node->data = temp->data; // case when only one is null and other is not
            delete temp;
        } else { // case when both are not null
            // here temp is the highest number on the left, but I could also use the lowest on the right
            Node* temp = maxValueNode(node->left);
            node->data = temp->data;
            node->left = removeAVL(node->left, temp->data);
        }
    }
    if(node == nullptr) return node;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    return rebalanceAVL(node, value);
}

