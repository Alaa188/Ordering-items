#include "HeapName.h"

using namespace std;

void HeapName::addItem(const Item &newItem) {
    items.push_back(newItem);
    itemsNormal.push_back(newItem);
    heapSort();
}

void HeapName::removeItem(string name) {
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

void HeapName::heapSort() {
    int n = items.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyName(n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(items[0], items[i]);
        heapifyName(i, 0);
    }
}

void HeapName::heapifyName(int n, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int Max = i;
    if (l < n && items[l].getName() > items[Max].getName()) {
        Max = l;
    }
    if (r < n && items[r].getName() > items[Max].getName()) {
        Max = r;
    }
    if (Max != i) {
        swap(items[i], items[Max]);
        heapifyName(n, Max);
    }
}

void HeapName::displayAsc() {
    for (auto& item : items) {
        item.print();
    }
}

void HeapName::displayDes() {
    for (auto it = items.rbegin(); it != items.rend(); ++it) {
        it->print();
    }
}

void HeapName::displayNormally() {
    for (auto& item : itemsNormal) {
        item.print();
    }
}
