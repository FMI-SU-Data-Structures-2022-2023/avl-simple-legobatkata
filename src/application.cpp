#include <iostream>
#include "solution.h"
using namespace std;

int main() {

    Node* a = nullptr;

    a = insertAVL(a, 1);
    printBT(a);
    cout<<endl<<endl;
    a = insertAVL(a, 2);
    printBT(a);
    cout<<endl<<endl;
    a = insertAVL(a, 3);
    printBT(a);
    cout<<endl<<endl;
    a = insertAVL(a, 4);
    printBT(a);
    cout<<endl<<endl;
    a = insertAVL(a, 5);
    printBT(a);
    cout<<endl<<endl;
    a = insertAVL(a, 6);
    printBT(a);
    cout<<endl<<endl;

    //cout<<endl<<(a->right->left == nullptr)<<endl;
    //cout<<endl<<(a->left->right->data)<<endl;

}
