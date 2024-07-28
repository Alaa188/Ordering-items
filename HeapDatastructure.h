#ifndef HEAPDATASTRUCTURE_H
#define HEAPDATASTRUCTURE_H

#include "Item.h"

class HeapDatastructure {
public:
    virtual void addItem(const Item &newItem) = 0;
    virtual void removeItem(std::string name) = 0;
    virtual void displayAsc() = 0;
    virtual void displayDes() = 0;
    virtual void heapSort() = 0;
    virtual void displayNormally() = 0;
};

#endif // HEAPDATASTRUCTURE_H
