#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int len1 = 16;

    for(int i=0; i<len1; i++) cout<<arr[i]<<" ";
    cout<<endl<<endl;

    Node* t = arrToTree(arr, len1);
    printBT(t);

    int* res = new int[50];
    int len2 = treeToArr(t, res);

    for(int i=0; i<len2; i++) cout<<arr[i]<<" ";
    cout<<endl<<endl;

    releaseAVL(t);

}
