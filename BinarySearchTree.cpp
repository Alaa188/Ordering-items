#include "Tree.h"
using namespace std;
class BSTPrice :public Tree{
public:
    BSTPrice(){}

    void add(Item &value) override{

        //Store in vector normal input
        v.push_back(value);

        node *newNode= new node(value, nullptr, nullptr);

        if(root==nullptr){
            root=newNode;
            return;
        }
        node *temp=root;
        //search untill the nextptr of temp = null then put the value and discard temp
        while(true){
            if(value>temp->data){
                if(temp->right== nullptr){
                    temp->right=newNode;
                    break;
                }
                temp=temp->right;
            }
            else if(value<temp->data){
                if(temp->left== nullptr){
                    temp->left=newNode;
                    break;
                }
                temp=temp->left;
            }
            else{
                if(temp->right== nullptr){
                    temp->right=newNode;
                    break;
                }
                temp=temp->right;
            }
        }

    };

    void ascendingsort(node* node) override{
        if (node != NULL) {

            ascendingsort(node->left);

            node->data.print();

            ascendingsort(node->right);
        }
    };
    void descendingsort(node* node) override{
        if (node != NULL) {

            descendingsort(node->right);

            node->data.print();

            descendingsort(node->left);
        }
    };

    void printdescending() override{
        cout<<"Sorted By Price descending: \n";
        descendingsort(root);
        cout<<endl;
    }
    void printascending() override{
        cout<<"Sorted By Price ascending: \n";
        ascendingsort(root);
        cout<<endl;
    }
    void printNormal() override{
        cout<<"Sort items Normally: \n";
        for(auto &i :v){
            i.print();
        }
        cout<<'\n';
    }
    void deleteItem(Item &value) override{

        auto pos = find(v.begin(),v.end(),value);
        if(pos!=v.end()){
            v.erase(pos);
        }

        node*current=root;
        node*parent=nullptr;
        bool isLeftChild=false;

        while(current!= nullptr && !(current->data==value)){
            parent=current;
            if(value>current->data){
                isLeftChild=false;
                current=current->right;
            }else{
                isLeftChild=true;
                current=current->left;
            }
        }

        if(current== nullptr){
            cout<<"Item isnt found in the tree"<<endl;
            return;
        }else{
            if(current->left== nullptr&&current->right== nullptr){
                if(current==root){
                    root= nullptr;
                }else if(isLeftChild){
                    parent->left= nullptr;
                }else{
                    parent->right= nullptr;
                }
            }

            else if(current->left= nullptr){
                node* temp = current->right;
                if(parent== nullptr){
                    root=temp;
                }else if(isLeftChild){
                    parent->left=temp;
                }else{
                    parent->right = temp;
                }
                delete current;
            }

            else if(current->right= nullptr){
                node* temp = current->left;
                if(parent== nullptr){
                    root=temp;
                }else if(isLeftChild){
                    parent->left=temp;
                }else{
                    parent->right = temp;
                }
                delete current;
            }

            else if (current->left != nullptr && current->right != nullptr) {
                node* succ = current->right;
                node* succParent = current;

                while(succ->left!= nullptr){
                    succParent=succ;
                    succ=succ->left;
                }
                current->data=succ->data;

                if (succParent->left == succ) {
                    succParent->left = succ->right;
                } else {
                    succParent->right = succ->right;
                }
                delete succ;
            }
        }

    }
};
class BSTName:public Tree{
public:
    BSTName(){}
    void add(Item &value) override{
        node *newNode= new node(value, nullptr, nullptr);

        v.push_back(value);

        if(root==nullptr){
            root=newNode;
            return;
        }
        node *temp=root;
        //search untill the nextptr of temp = null then put the value and discard temp
        while(true){
            if(value.getName()>temp->data.getName()){
                if(temp->right== nullptr){
                    temp->right=newNode;
                    break;
                }
                temp=temp->right;
            }
            else if(value.getName()<temp->data.getName()){
                if(temp->left== nullptr){
                    temp->left=newNode;
                    break;
                }
                temp=temp->left;
            }
            else{
                return;
            }
        }
    };

    void ascendingsort(node* node) override{
        if (node != NULL) {

            ascendingsort(node->left);

            node->data.print();

            ascendingsort(node->right);
        }
    };
    void descendingsort(node* node) override{
        if (node != NULL) {
            descendingsort(node->right);

            node->data.print();

            descendingsort(node->left);
        }
    };

    void printdescending() override{
        cout<<"Sorted By Name descending: \n";
        descendingsort(root);
        cout<<endl;
    }
    void  printascending() override{
        cout<<"Sorted By Name ascending: \n";
        ascendingsort(root);
        cout<<endl;
    }
    void printNormal() override{
        cout<<"Sort items Normally: \n";
        for(auto &i :v){
            i.print();
        }
        cout<<'\n';
    }

    void deleteItem(Item &value){
        auto pos = find(v.begin(),v.end(),value);
        if(pos!=v.end()){
            v.erase(pos);
        }

        node*current=root;
        node*parent=nullptr;
        bool isLeftChild=false;
        while(current!= nullptr && !(current->data==value)){
            parent=current;
            if(value>current->data){
                isLeftChild=false;
                current=current->right;
            }else{
                isLeftChild=true;
                current=current->left;
            }
        }
        if(current== nullptr){
            cout<<"Item isnt found in the tree"<<endl;
            return;
        }else{
            //case1 ; node with no children
            if(current->left== nullptr&&current->right== nullptr){
                if(current==root){
                    root= nullptr;
                }else if(isLeftChild){
                    parent->left= nullptr;
                }else{
                    parent->right= nullptr;
                }
            }
                //case2; node has one child on the right
            else if(current->left= nullptr){
                node* temp = current->right;
                if(parent== nullptr){//node is the root
                    root=temp;
                }else if(isLeftChild){
                    parent->left=temp;
                }else{
                    parent->right = temp;
                }
                delete current;
            }
                //case3; node has one child on the left
            else if(current->right= nullptr){
                node* temp = current->left;
                if(parent== nullptr){//node is the root
                    root=temp;
                }else if(isLeftChild){
                    parent->left=temp;
                }else{
                    parent->right = temp;
                }
                delete current;
            }
                //case4; node has two children
            else if (current->left != nullptr && current->right != nullptr) {
                node* succ = current->right;
                node* succParent = current;

                //find the seccessor of the node you want to delete(the smallest number in the right sub tree)
                while(succ->left!= nullptr){
                    succParent=succ;
                    succ=succ->left;
                }
                current->data=succ->data;//copy the succ data in the current

                //delete the original successor
                if (succParent->left == succ) {
                    succParent->left = succ->right; // Connect the successor's parent to successor's right child
                } else {
                    succParent->right = succ->right; // Connect the successor's parent to successor's right child
                }
                delete succ; // Delete the successor
            }
        }

    }
};
