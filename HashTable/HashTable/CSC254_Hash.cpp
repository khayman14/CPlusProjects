//
//  CSC254_Hash.cpp
//  HashTable
//
//  Created by KAM HAYMAN on 7/17/19.
//  Copyright © 2019 KAM HAYMAN. All rights reserved.
//

#include<iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class HashNode
{
public:
    int key;
    int value;
    HashNode* next;
    HashNode(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};

/*
 * HashMap Class Declaration
 */
class HashMap
{
    int TABLE_SIZE = 5;
private:
    HashNode** htable;
public:
    HashMap()
    {
        htable = new HashNode*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
            htable[i] = NULL;
    }
    ~HashMap()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            HashNode* entry = htable[i];
            while (entry != NULL)
            {
                HashNode* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] htable;
    }
    /*
     * Hash Function
     */
    int HashFunc(int key)
    {
        return key % TABLE_SIZE;
    }
    
    /*
     * Insert Element at a key
     */
    void Insert(int key, int value)
    {
        int hash_val = HashFunc(key);
        HashNode* prev = NULL;
        HashNode* entry = htable[hash_val];
        while (entry != NULL)
        {
            prev = entry;
            entry = entry->next;
        }
        if (entry == NULL)
        {
            entry = new HashNode(key, value);
            if (prev == NULL)
            {
                htable[hash_val] = entry;
            }
            else
            {
                prev->next = entry;
            }
        }
        else
        {
            entry->value = value;
        }
    }
    /*
     * Remove Element at a key
     */
    void Remove(int key)
    {
        int hash_val = HashFunc(key);
        HashNode* entry = htable[hash_val];
        HashNode* prev = NULL;
        if (entry == NULL || entry->key != key)
        {
            cout << "No Element found at key " << key << endl;
            return;
        }
        while (entry->next != NULL)
        {
            prev = entry;
            entry = entry->next;
        }
        if (prev != NULL)
        {
            prev->next = entry->next;
        }
        delete entry;
        cout << "Element Deleted" << endl;
    }
    /*
     * Search Element at a key
     */
    int Search(int key)
    {
        bool flag = false;
        int hash_val = HashFunc(key);
        HashNode* entry = htable[hash_val];
        while (entry != NULL)
        {
            if (entry->key == key)
            {
                cout << entry->value << " ";
                flag = true;
            }
            entry = entry->next;
        }
        if (!flag){
            return -1;
        }
        return 0;
    }
    };
