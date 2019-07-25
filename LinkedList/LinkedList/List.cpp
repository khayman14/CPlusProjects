//
//  List.cpp
//  LinkedList
//
//  Created by KAM HAYMAN on 7/22/19.
//  Copyright © 2019 KAM HAYMAN. All rights reserved.
//
#include <iostream>
#include "List.h"
#include <cstdlib>
using namespace std;

List::List(){
    head = NULL;
    current = NULL;
    temp = NULL;
}

void List::addNode(int addData){
    nodePTR n = new Node;
    n->next = NULL;
    n->data = addData;
    
    if (head != NULL){
        current = head;
        while (current->next != NULL) {
           current = current->next;
        }
        current->next = n;
    }else{
        head = n;
    }
}

void List::deleteNode(int deleteData){
    nodePTR delPTR = NULL;
    temp = head;
    current = head;
    while(current != NULL && current->data != deleteData){
        temp = current;
        current = current->next;
    }
    if (current == NULL){
        cout<<deleteData<<" was not found in the list \n";
        delete delPTR;
    }else{
        delPTR = current;
        current = current->next;
        temp -> next = current;
        delete delPTR;
        cout<<deleteData<<" was deleted \n";
    }
}

void List::printList(){
    current = head;
    if(current == NULL){
        cout<<"List is Empty \n";
    }else{
        while(current != NULL){
            cout<<current->next<<endl;
            current = current->next;
        }
    }
    
}
