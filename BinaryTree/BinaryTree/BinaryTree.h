//
//  BinaryTree.h
//  BinaryTree
//
//  Created by KAM HAYMAN on 7/25/19.
//  Copyright © 2019 KAM HAYMAN. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h
class BST{
private:
    struct Node{
        int key;
        Node* left;
        Node* right;
        
    };
    Node* root;
    void AddLeafPrivate(int key, Node* Ptr);
    void printInOrderPrivate(Node* Ptr);
    Node* returnNodePrivate(int key, Node* Ptr);
    int findSmallestPrivate(Node* Ptr);
    void removeNodePrivate(int key,Node* parent);
    void removeRootMatch();
    void removeMatch(Node* parent, Node* match, bool left);
public:
    BST();
    Node* CreateLeaf(int key);
    void AddLeaf(int key);
    void printInOrder();
    Node* returnNode(int key);
    int returnRootKey();
    void printChildren(int key);
    int findSmallest();
    void removeNode(int key);
    
};

#endif /* BinaryTree_h */

