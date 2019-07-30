//
//  main.cpp
//  BinaryTree
//
//  Created by KAM HAYMAN on 7/25/19.
//  Copyright © 2019 KAM HAYMAN. All rights reserved.
//

#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int treeKeys[16] = {38,46,47,29,35,43,41,1,8,6,3,34,15,37,7,17};
    int input=0;
    BST kamTree;
    
    for(int i = 0; i<=15; i++){
        kamTree.AddLeaf(treeKeys[i]);
    }
    kamTree.printInOrder();
    for (int i=0; i<=15; i++) {
        kamTree.printChildren(treeKeys[i]);
    }
    cout<<"The smallest key in the tree is: "<<kamTree.findSmallest()<<endl;
    
    cout<<"Enter a value to delete. Enter -1 to exit.";
    
    while (input!=-1) {
        cout<<"Enter a node to delete: \n";
        cin>>input;
        if (input != -1) {
            cout<<endl;
            kamTree.removeNode(input);
            kamTree.printInOrder();
            cout<<endl;
        }
    }
    
    return 0;
}
