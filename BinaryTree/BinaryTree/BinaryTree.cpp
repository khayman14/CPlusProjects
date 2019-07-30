//
//  BinaryTree.cpp
//  BinaryTree
//
//  Created by KAM HAYMAN on 7/25/19.
//  Copyright © 2019 KAM HAYMAN. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "BinaryTree.h"
using namespace std;

BST::BST(){
    root = NULL;
};
BST::Node* BST::CreateLeaf(int key){
    Node* n = new Node;
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    
    return n;
};

void BST::AddLeaf(int key){
    AddLeafPrivate(key, root);
}
void BST::AddLeafPrivate(int key, Node* Ptr){
    if(root == NULL){
        root = CreateLeaf(key);
    }
    else if(key< Ptr->key){
        if(Ptr->left != NULL){
            AddLeafPrivate(key, Ptr->left);
        }else{
            Ptr->left = CreateLeaf(key);
        }
    }
    else if(key> Ptr->key){
        if(Ptr->right != NULL){
            AddLeafPrivate(key, Ptr->right);
        }else{
            Ptr->right = CreateLeaf(key);
        }
    }else{
        cout<<"The key value "<<key<<" is already in the tree.";
    }
}

void BST::printInOrder(){
    printInOrderPrivate(root);
}

void BST::printInOrderPrivate(Node* Ptr){
    if(root != NULL){
        if(Ptr->left!=NULL){
            printInOrderPrivate(Ptr->left);
        }
        cout<<Ptr->key<<" ";
        if (Ptr->right!=NULL) {
            printInOrderPrivate(Ptr->right);
        }
    }else{
        cout<<"The tree is empty";
    }
}

BST::Node* BST::returnNode(int key){
    return returnNodePrivate(key,root);
}

BST::Node* BST::returnNodePrivate(int key, Node* Ptr){
    if(Ptr != NULL){
        if(Ptr->key == key){
            return Ptr;
        }else{
            if (key < Ptr->key) {
                return returnNodePrivate(key, Ptr->left);
            }else{
                return returnNodePrivate(key, Ptr->right);
            }
        }
    }else{
        return NULL;
    }
    
}
int BST::returnRootKey(){
    if (root!=NULL) {
        return root->key;
    }else{
        return 5;
    }
}

void BST::printChildren(int key){
    Node* Ptr = returnNode(key);
    
    if(Ptr != NULL){
        cout<<"\nParent Node= "<< Ptr->key<<endl;
        
        Ptr->left == NULL ?
        cout<<"Left Child = NULL"<<endl:
        cout<<"Left Child = "<<Ptr->left->key<<endl;
        
        Ptr->right == NULL ?
        cout<<"Right Child = NULL"<<endl:
        cout<<"Right Child = "<<Ptr->right->key<<endl;
    }else{
        cout<<key<<" is not in the tree\n";
    }
}

int BST::findSmallest(){
   return findSmallestPrivate(root);
}

int BST::findSmallestPrivate(Node* Ptr){
    if (root==NULL) {
        cout<<"The tree is empty\n";
        return -1000;
    }else{
        if (Ptr->left!=NULL) {
            return findSmallestPrivate(Ptr->left);
        }else{
            return Ptr->key;
        }
    }
}

void BST::removeNode(int key){
    removeNodePrivate(key, root);
}

void BST:: removeNodePrivate(int key, Node* parent){
    if(root != NULL){
        if(root->key == key){
            removeRootMatch();
        }else{
            if (key<parent->key && parent->left != NULL) {
                parent->left->key == key ?
                removeMatch(parent, parent->left, true):
                removeNodePrivate(key, parent->left);
            }else if (key<parent->key && parent->right != NULL){
                parent->right->key == key ?
                removeMatch(parent, parent->right, false):
                removeNodePrivate(key, parent->right);
            }else{
                cout<<"Key not found in tree\n";
            }
        }
    }else{
        cout<<"The tree is empty"<<endl;
    }
}

void BST::removeRootMatch(){
    if (root != NULL) {
        Node* delPtr = root;
        int rootKey = root->key;
        int smallestInRightSubtree;
        
        if (root->left == NULL && root->right == NULL) {
            root = NULL;
            delete delPtr;
        }else if (root->left == NULL && root->right != NULL){
            root = root->right;
            delPtr->right = NULL;
            delete delPtr;
            cout<<"The root with key "<<rootKey<<" has been deleted\n"<<"The new root contains"<<root->key ;
        }else if (root->left != NULL && root->right == NULL){
            root = root->left;
            delPtr->left = NULL;
            delete delPtr;
            cout<<"The root with key "<<rootKey<<" has been deleted\n"<<"The new root contains"<<root->key ;
        }else{
            smallestInRightSubtree = findSmallestPrivate(root->right);
            removeNodePrivate(smallestInRightSubtree, root);
            rootKey = smallestInRightSubtree;
            cout<<"The root key containing key "<<rootKey<<" has been overwritten with key "<<root->key<<endl;
        }
    }else{
        cout<<"The tree is empty\n";
    }
}

void BST::removeMatch(Node* parent, Node* match, bool left){
    if (root!=NULL) {
        Node* delPtr;
        int matchKey = match->key;
        int smallestInRightSubtree;
        
        if (match->left == NULL && match->right==NULL) {
            delPtr = match;
            left = true ?
            parent->left = NULL:
            parent->right = NULL;
            delete delPtr;
            cout<<"The node containing key"<<matchKey<<" was removed\n";
            
        }else if (match->left == NULL && match->right != NULL){
            left == true?
            parent->left = match->right:
            parent->right = match->right;
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            cout<<"The node containing key"<<matchKey<<" was removed\n";
            
        }else if (match->left != NULL && match->right == NULL){
            left == true?
            parent->left = match->left:
            parent->right = match->left;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            cout<<"The node containing key"<<matchKey<<" was removed\n";
        }else{
            smallestInRightSubtree = findSmallestPrivate(match->right);
            removeNodePrivate(smallestInRightSubtree, match);
            match->key = smallestInRightSubtree;
            
        }
    }else{
        cout<<"Cannot remove match: The tree is empty\n";
    }
}
