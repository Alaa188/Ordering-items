#include "Tree.h"

// class for avl tree compare by price
class AVLPrice : public Tree {
public:
    AVLPrice() = default;

    int height(node *N) {
        if (N == nullptr)
            return 0;
        return N->height;
    }

    int max(int a, int b) {

        if(a > b) return a;
        else return b;

    }

    int getBalance(node *N) {
        if (N == nullptr)
            return 0;
        else
            return height(N->left) - height(N->right);
    }


    node* rightRotate(node *y) {
        node *x = y->left;
        node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    node* leftRotate(node *n1) {
        node *n2 = n1->right;
        node *T2 = n2->left;

        n2->left = n1;
        n1->right = T2;

        n1->height = max(height(n1->left), height(n1->right)) + 1;
        n2->height = max(height(n2->left), height(n2->right)) + 1;

        return n2;
    }


    void add(Item &value) override {

        v.push_back(value);

        root = insert(root, value);
    }

     node* insert(node* node, Item &value) {
        if (node == nullptr)
            return(new Tree::node(value));

        if (value < node->data)
            node->left  = insert(node->left, value);
        else
            node->right = insert(node->right, value);


        node->height = 1 + max(height(node->left),
                               height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && value < node->left->data)
            return rightRotate(node);

        if (balance < -1 && value > node->right->data)
            return leftRotate(node);

        if (balance > 1 && value > node->left->data) {
            node->left =  leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
    void ascendingsort(node* node) override{
        if (node != nullptr) {
            ascendingsort(node->left);

            node->data.print();

            ascendingsort(node->right);
        }
    };
    void descendingsort(node* node) override{
        if (node != nullptr) {
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
    void deleteItem(Item &value) override {
        auto pos = find(v.begin(),v.end(),value);
        if(pos!=v.end()){
            v.erase(pos);
        }
        root = deleteNode(root, value);
    }

    node* deleteNode(node* root, Item &key) {


        if (root == nullptr)
            return root;

        if ( key.getName() < root->data.getName() )
            root->left = deleteNode(root->left, key);

        else if( key.getName() > root->data.getName() )
            root->right = deleteNode(root->right, key);

        else {

            if( (root->left == nullptr) || (root->right == nullptr) ) {
                node *temp = root->left ? root->left : root->right;


                if(temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else {
                node* temp = minValueNode(root->right);

                root->data = temp->data;

                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (root == nullptr)
            return root;

        root->height = max(height(root->left),height(root->right)) + 1;

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left =  leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    node* minValueNode(node* node) {
        Tree::node * current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }};

class AVLName : public Tree {
public:
    AVLName() = default;

    int height(Tree::node *N) {
        if (N == nullptr)
            return 0;
        return N->height;
    }

    int max(int a, int b) {

        if(a > b) return a;
        else return b;

    }

    int getBalance(node *n) {
        if (n == nullptr)
            return 0;
        else
            return height(n->left) - height(n->right);
    }

    node* rightRotate(Tree::node *n2) {
        node *n1 = n2->left;
        node *T2 = n1->right;

        n1->right = n2;
        n2->left = T2;

        n2->height = max(height(n2->left), height(n2->right)) + 1;
        n1->height = max(height(n1->left), height(n1->right)) + 1;

        return n1;
    }

    node* leftRotate(node *n1) {
        node *n2 = n1->right;
        node *T2 = n2->left;

        n2->left = n1;
        n1->right = T2;

        n1->height = max(height(n1->left), height(n1->right)) + 1;
        n2->height = max(height(n2->left), height(n2->right)) + 1;

        return n2;
    }


    void add(Item &value) override {

        v.push_back(value);

        root = insert(root, value);
    }

    node* insert(node* node, Item &value) {

        if (node == nullptr)
            return(new Tree::node(value));

        if (value.getName() <= node->data.getName())
            node->left  = insert(node->left, value);
        else if (value.getName() > node->data.getName())
            node->right = insert(node->right, value);



        node->height = max(height(node->left),height(node->right)) + 1;


        int balance = getBalance(node);

        if (balance > 1 && value.getName() < node->left->data.getName())
            return rightRotate(node);


        if (balance < -1 && value.getName() > node->right->data.getName())
            return leftRotate(node);

        if (balance > 1 && value.getName() > node->left->data.getName()) {
            node->left =  leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && value.getName() < node->right->data.getName()) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }


        return node;
    }

    void ascendingsort(node* node) override{
        if (node != nullptr) {
            ascendingsort(node->left);

            node->data.print();

            ascendingsort(node->right);
        }
    };
    void descendingsort(node* node) override{
        if (node != nullptr) {
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
    void printascending() override{
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
    void deleteItem(Item &value) override {
        auto pos = find(v.begin(),v.end(),value);
        if(pos!=v.end()){
            v.erase(pos);
        }
        root = deleteNode(root, value);
    }

    node* deleteNode(node* root, Item &key) {

        if (root == nullptr)
            return root;


        if ( key.getName() < root->data.getName() )
            root->left = deleteNode(root->left, key);


        else if( key.getName() > root->data.getName() )
            root->right = deleteNode(root->right, key);


        else {

            if( (root->left == nullptr) || (root->right == nullptr) ) {
                node *temp = root->left ? root->left : root->right;

                if(temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else {

                node* tmp = minValueNode(root->right);

                root->data = tmp->data;

                root->right = deleteNode(root->right, tmp->data);
            }
        }


        if (root == nullptr)
            return root;


        root->height = 1 + max(height(root->left), height(root->right));


        int balance = getBalance(root);




        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);


        if (balance > 1 && getBalance(root->left) < 0) {
            root->left =  leftRotate(root->left);
            return rightRotate(root);
        }


        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);


        if (balance < -1 && getBalance(root->right) > 0) {

            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }
    node* minValueNode(node* node) {

        Tree::node * crnt = node;


        while (crnt->left != nullptr)

            crnt = crnt->left;

        return crnt;
    }
};
// made by Kareem Mohamed Hasseeb