#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    Node* t = arrToTree(arr, 6);
    printBT(t);

    /*
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


    a = removeAVL(a, 2);
    printBT(a);
    cout<<endl<<endl;


    a = insertAVL(a, 99);
    printBT(a);
    cout<<endl<<endl;

    a = insertAVL(a, 101);
    printBT(a);
    cout<<endl<<endl;

    a = insertAVL(a, 120);
    printBT(a);
    cout<<endl<<endl;

    a = insertAVL(a, 150);
    printBT(a);
    cout<<endl<<endl;

    releaseAVL(a);
    */
    //cout<<endl<<(a->right->left == nullptr)<<endl;
    //cout<<endl<<(a->left->right->data)<<endl;

}
