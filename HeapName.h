#ifndef HEAPNAME_H
#define HEAPNAME_H

#include <iostream>
#include <deque>
#include <algorithm>
#include "HeapDatastructure.h"

class HeapName : public HeapDatastructure {
private:
    std::deque<Item> items;
    std::deque<Item> itemsNormal;

    void heapifyName(int n, int i);

public:
    void addItem(const Item &newItem) override;
    void removeItem(std::string name) override;
    void displayAsc() override;
    void displayDes() override;
    void heapSort() override;
    void displayNormally() override;
};

#endif // HEAPNAME_H
