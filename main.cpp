#include <iostream>

#include "binaryTree.h"

using namespace std;

int main() {
    int b[]={10, 25, 20, 6, 21, 8, 5,4,7,30,45};
    binaryTree root;
    for (int i : b)
        root.addHeapy(i);
    root.print();
    cout<<"==============="<<endl;
    cout<<root.leafCount();
    return 0;
}
