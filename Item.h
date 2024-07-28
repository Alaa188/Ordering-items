//
// Created by PC on 5/18/2024.
//

#ifndef DATASTRUCTURE_ASSIGNMENT2_ITEM_H
#define DATASTRUCTURE_ASSIGNMENT2_ITEM_H
#include <iostream>
using namespace std;

class Item {
private:
    string itemName;
    string category;
    int price;
public:

    Item(string itemName, string category, int price) {
        this->itemName=itemName;
        this->category=category;
        this->price=price;
    };

    string getName();
    int getPrice();
    bool operator<(const Item &item2);
    bool operator>(const Item &item2);
    void print();
    bool operator==(const Item &item2);

};


#endif //DATASTRUCTURE_ASSIGNMENT2_ITEM_H
