#include <iostream>
#include <string>
#include "Item.h"
using namespace std;

string Item::getName(){
    return itemName;
}

int Item::getPrice(){
    return price;
}

bool Item:: operator<(const Item &item2) {
    return this->price < item2.price;
}

bool Item:: operator>(const Item &item2) {
    return this->price > item2.price;
}

void Item:: print() {
    cout << "Item Name: " << itemName << ", Category: " << category << ", Price: " << price << endl;
}

bool Item:: operator==(const Item &item2) {
    return this->itemName == item2.itemName && this->category == item2.category && this->price == item2.price;
}