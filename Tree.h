#ifndef TREEASSIGNMENT_TREE_H
#define TREEASSIGNMENT_TREE_H
#include "Item.h"
#include <iostream>
#include <deque>
#include <algorithm>
class Tree{
protected:
    struct node {
        Item data;
        node* left;
        node* right;
        int height;

        node(Item data, node* left = nullptr, node* right = nullptr, int height = 1)
                : data(data), left(left), right(right), height(height) {}
    };

    node *root= nullptr;
public:
    //vector to store data normally then print them normally q3
    deque <Item>v;
    virtual void add(Item &value)=0;
    virtual void ascendingsort(node* node)=0;
    virtual void descendingsort(node* node)=0;
    virtual void printdescending()=0;
    virtual void printascending()=0;
    virtual void printNormal()=0;
    virtual void deleteItem(Item &value)=0;
};
#endif //TREEASSIGNMENT_TREE_H