#include "BinarySearchTree.cpp"
#include "AVL.cpp"
#include "HeapDatastructure.h"
#include "HeapName.h"
#include "HeapPrice.h"
#include <iostream>
#include <fstream>
#include <istream>

using namespace std;
Tree *treeName=nullptr;
Tree *treePrice=nullptr;
HeapDatastructure *myHeapName = nullptr;
HeapDatastructure *myHeapPrice = nullptr;

bool isHeap = false;

deque<Item> readItems(istream& in) {
    int numItems,price;
    string itemName, category;
    deque<Item> items;
    in >> numItems;
    in.ignore();

    for (int i = 0; i < numItems; ++i) {
        getline(in, itemName);
        for(auto &k :itemName){
            k=tolower(k);
        }
        getline(in, category);
        in >> price;
        in.ignore();
        Item item(itemName, category, price);
        items.push_back(item);
    }

    return items;
}

void ChooseTree(){
    cout<<"Welcome to our program\n";
    cout<<"Choose The Suitable DataStructure :\n";
    cout<<"1.BinarySearchTree\n"
          "2.Heaps\n"
          "3.AVL Trees\n";
    int choice;
    cin>>choice;
    switch (choice) {
        case 1:
            treeName = new BSTName();
            treePrice = new BSTPrice();
            break;
        case 2:
            myHeapName = new HeapName();
            myHeapPrice = new HeapPrice();
            isHeap = true;
            break;
        case 3:
            treeName = new AVLName();
            treePrice = new AVLPrice();
            break;
    }
}

void ChooseOperation(deque<Item>&i){
    int index=0;
    //
    string name;
    bool itemFound=false;
    menu:
    cout<<"1.Add Item\n"
          "2.Remove Item from data\n"
          "3.Display the Item data normally\n"
          "4.Display all the items sorted by their name ascending\n"
          "5.Display all the items sorted by their name descending\n"
          "6.Display all the items sorted by their prices ascending\n"
          "7.Display all the items sorted by their prices descending\n"
          "8.Exit\n";
    int choice;
    cin>>choice;
    cin.ignore();
    switch (choice){
        case 1:
            if (index >= i.size()) {
                cout << "no more items\n";
                goto menu;
            }
            if (isHeap) {
                myHeapName->addItem(i[index]);
                myHeapPrice->addItem(i[index]);
            } else {
                treeName->add(i[index]);
                treePrice->add(i[index]);
            }
            index++;
            goto menu;
        case 2:
            cout << "Enter the name of the item you want to delete: ";
            getline(cin, name);
            //HEAP
            if (isHeap) {
                myHeapName->removeItem(name);
                myHeapPrice->removeItem(name);
                cout << "Item deleted successfully.\n";
            }
            //AVL , BST
            else {
                for (auto it = i.begin(); it != i.end(); ++it) {
                    if (it->getName() == name) {
                        treeName->deleteItem(*it);
                        treePrice->deleteItem(*it);
                        i.erase(it);
                        cout << "Item deleted successfully.\n";
                        itemFound = true;
                        break;
                    }
                }
                if (!itemFound) {
                    cout << "Item not found.\n";
                }
            }
            goto menu;
        case 3:
            if (isHeap) {
                myHeapName->displayNormally();
            } else {
                treeName->printNormal();
            }
            goto menu;
        case 4:
            if (isHeap) {
                myHeapName->displayAsc();
            } else {
                treeName->printascending();
            }

            goto menu;

        case 5:
            if(isHeap){
                myHeapName->displayDes();
            }
            else {
                treeName->printdescending();
            }
            goto menu;

        case 6:
            if(isHeap){
                myHeapPrice->displayAsc();
            }
            else {
                treePrice->printascending();
            }
            goto menu;

        case 7:
            if(isHeap){
                myHeapPrice->displayDes();
            }
            else {
                treePrice->printdescending();
            }
            goto menu;

        case 8:
            break;
    }
}


int main(){
    ifstream inFile("Input.txt");
    if (!inFile) {
        cerr << "Unable to open file items.txt";
        return 1;
    }
    deque<Item> items = readItems(inFile);
    inFile.close();
    ChooseTree();
    ChooseOperation(items);

}

