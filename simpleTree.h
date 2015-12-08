#include<iostream>
#include<list>
using namespace std;
template <class Object>
class BST {
    private:
    struct BSTNode {
        Object value;
        BSTNode * left;
        BSTNode * right;
    };
    public:
    BST() : root{NULL}
    {}
    bool empty(){
        if(root == NULL) return 1;
        else return 0;
    }
    void recursiveInsert(Object x){
        BSTNode * newNode = new BSTNode;
        newNode->value = x;
        insertRec(newNode, root);
    }
    bool find(Object x){
        bool answer = findRec(x, root);
    }
    void delNode(Object x){
        deleteNodeRec(x, root);
    }
    int findMin(){
        findMinRec(root);
    }
    int findMax(){
        findMaxRec(root);
    }
    list<Object> getList (){
        current = root;
        if(ourList.empty() == 0) ourList.clear();
        makeList(current);
        ourList.sort();
        return ourList;
    }
    private:
    list<Object> ourList;
    BSTNode * root;
    BSTNode * current;
    void insertRec(BSTNode * newNode, BSTNode * current){
        if(empty()){
            root = newNode;
        }
        else if(newNode->value > current->value && current->right == NULL){
            cout << "new value is bigger than current value: " << newNode->value << " > " << current->value << endl;
            cout << "tadding " << newNode->value << " to the right of current node with value " << current->value << endl;
            current->right = newNode;
            return;
        }
        else if(newNode->value > current->value && current->right != NULL){
            cout << "new value is bigger than current value: " << newNode->value << " > " << current->value << endl;
            cout << "tmoving to the right so we can see how our new value compares to that node" << endl;
            insertRec(newNode, current->right);
        }
        else if(newNode->value < current->value && current->left == NULL){
            cout << "new value is smaller than current value: " << newNode->value << " < " << current->value << endl;
            cout << "tadding " << newNode->value << " to the left of current node with value " << current->value << endl;
            current->left = newNode;
            return;
        }
        else if(newNode->value < current->value && current->left != NULL){
            cout << "new value is smaller than current value: " << newNode->value << " < " << current->value << endl;
            cout << "tmoving to the right so we can see how our new value compares to that node" << endl;
            insertRec(newNode, current->left);
        }
        else return;
    }
    bool findRec(Object x, BSTNode * current){
        if(x > current->value) findRec(x, current->right);
        else if(x < current->value) findRec(x, current->left);
        else if(current->value == x) return true;
        else return false;
    }
    BSTNode * findMinRec(BSTNode * current){
        if(current->left != NULL) findMinRec(current->left);
        else return current;
    }
    BSTNode * findMaxRec(BSTNode * current){
        if(current->right != NULL) findMaxRec(current->right);
        else return current;
    }
    void deleteNodeRec(Object x, BSTNode * current ){
        //if this happens, we know that value is not in our tree, just tell me its not there and return
        if(current == NULL){
            cout << "element not in list" << endl;
            return;
        }
        //if we want to delete the root, we have to make a new root and return
        if(x == root->value){
            cout << "tcurrent: " << current->value << endl;
            cout << "tdeleting root" << endl;
            BSTNode * nodeToDelete;
            nodeToDelete = current;
            BSTNode * tmpNode;
            tmpNode = root;
            root = current->right;
            root->left = tmpNode->left;
            delete nodeToDelete;
            return;
        }
        //if the left node is not null, and x is greater than the left node, move there to evaluate again
        if(current->left != NULL && x < current->left->value){
            cout << "tleft node = " << current->left->value << endl;
            deleteNodeRec(x, current->left);
        }
        //if the left node is not null, and the left node's value is equal to x, let's destroy it!
        else if( current->left != NULL && current->left->value == x) {
            cout << "tdeleting node with value = " << current->left->value << endl;
            BSTNode * nodeToDelete;
            nodeToDelete = current->left;
            BSTNode * tmpNode;
            tmpNode = current->left->left;
            delete nodeToDelete;
            current->left = tmpNode;
        }
        //if the right node is not null, and x is greater than the right node, move there to evaluate again
        else if(current->right != NULL && x > current->right->value){
            cout << "tright node = " << current->right->value << endl;
            deleteNodeRec(x, current->right);
        }
        //if the right node is not null, and the right node's value is equal to x, let's destroy it!
        else if( current->right != NULL && current->right->value == x) {
            cout << "tdeleting node with value = " << current->value << endl;
            BSTNode * nodeToDelete;
            nodeToDelete = current;
            BSTNode * tmpNode;
            tmpNode = current->right->right;
            delete nodeToDelete;
            current->right->right = tmpNode;
        }
        //else, if x is hidden behind a node that is greater than x, we have to do this work around-- this confused me for a while
        //but now, it looks at the right node's value and checks to see if the min value underneathe is less than x, and then it
        //proceeds to check from current->right
        else if(current->right != NULL && x > findMinRec(current->right)->value){
            cout << "tusing findMinRec... right node = " << current->right->value << endl;
            deleteNodeRec(x, current->right);
        }
        //if the right node has two children and it has a value equal to x
        else if( current->right->value == x && current->right->left != NULL && current->right->right != NULL ) {
            cout << "current: " << current->value << endl;
            BSTNode * nodeToDelete;
            nodeToDelete = current->right;
            BSTNode * tmpNode;
            tmpNode = current->right->left;
            current->right = current->right->right;
            current->right->left = tmpNode;
            delete nodeToDelete;
        }
        //if the left node has two children and it has a value equal to x
        else if( current->left->value == x && current->left->left != NULL && current->left->right != NULL ) {
            cout << "current: " << current->value << endl;
            BSTNode * nodeToDelete;
            nodeToDelete = current->left;
            BSTNode * tmpNode;
            tmpNode = current->left->left;
            current->left = current->left->right;
            current->left->left = tmpNode;
            delete nodeToDelete;
        }
    }
    void makeList(BSTNode * current){
        ourList.push_back(current->value);
        if(current->left != NULL) makeList(current->left);
        if(current->right != NULL) makeList(current->right);
    }
};
