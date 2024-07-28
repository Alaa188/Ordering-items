#include "HeapPrice.h"

using namespace std;

void HeapPrice::addItem(const Item &newItem) {
    items.push_back(newItem);
    itemsNormal.push_back(newItem);
    heapSort();
}

void HeapPrice::removeItem(string name) {
    if (items.empty()) {
        cout << "List is already empty, can't remove\n";
        return;
    }

    auto itNormal = remove_if(itemsNormal.begin(), itemsNormal.end(), [&name](Item& item) {
        return item.getName() == name;
    });

    if (itNormal != itemsNormal.end()) {
        itemsNormal.erase(itNormal, itemsNormal.end());
    }

    auto it = remove_if(items.begin(), items.end(), [&name](Item& item) {
        return item.getName() == name;
    });

    if (it != items.end()) {
        items.erase(it, items.end());
        heapSort(); // Re-heapify after removing an item
    }
}

void HeapPrice::heapSort() {
    int n = items.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyPrice(n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(items[0], items[i]);
        heapifyPrice(i, 0);
    }
}

void HeapPrice::heapifyPrice(int n, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int Max = i;
    if (l < n && items[l].getPrice() > items[Max].getPrice()) {
        Max = l;
    }
    if (r < n && items[r].getPrice() > items[Max].getPrice()) {
        Max = r;
    }
    if (Max != i) {
        swap(items[i], items[Max]);
        heapifyPrice(n, Max);
    }
}

void HeapPrice::displayAsc() {
    for (auto& item : items) {
        item.print();
    }
}

void HeapPrice::displayDes() {
    for (auto it = items.rbegin(); it != items.rend(); ++it) {
        it->print();
    }
}

void HeapPrice::displayNormally() {
    for (auto& item : itemsNormal) {
        item.print();
    }
}
