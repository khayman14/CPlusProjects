//
//  List.h
//  LinkedList
//
//  Created by KAM HAYMAN on 7/22/19.
//  Copyright © 2019 KAM HAYMAN. All rights reserved.
//

#ifndef List_h
#define List_h

class List{
  
private:
    typedef struct Node{
        int data;
        Node *next;
    }* nodePTR;
    
    nodePTR head;
    nodePTR current;
    nodePTR temp;
    
public: //functions
    
    List();
    void addNode(int addData);
    void deleteNode(int deleteData);
    void printList();
};

#endif /* List_h */
