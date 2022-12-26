#include <iostream>
using namespace std;

struct Node{
    int data;
    int height = 1;
    Node* left;
    Node* right;
    Node(int newData, Node* newLeft = nullptr, Node* newRight = nullptr, int newHeight = 1)
    :data(newData), left(newLeft), right(newRight), height(newHeight){}
};

void printBTRec(const std::string& prefix, const Node* node, bool isLeft);
void printBT(const Node* node);

Node* insertAVL(Node* node, int value);
Node* removeAVL(Node* node, int value);

Node* arrToTree(const int* sorted_data, int size);
int treeToArr(Node* node, int* result);
void releaseAVL(Node* node);