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
                        BSTNode * parent;
                };

        public:

                BST() : root{NULL}
                {}

               bool empty(){
                        if(root == NULL) return 1;
                        else return 0;
                }

            	void insert(Object x){
            				//create this node, with x as it's value. now we have to figure out where to put it
                        BSTNode * newNode = new BSTNode;
                        newNode->value = x;
                        
                        //if the tree is empty, set root to newNode
                        if(empty()){
                                root = newNode;
                                ourList.push_back(root->value);
                        } else {
                                current = root;

                                while(true){
                                        if(newNode->value < current->value){
                                        			cout << newNode->value << " < " << current->value << endl;
                                                //check if the left node is already filled
                                                //if it is not filled already, then, we'll set current->left to newNode
                                                if(current->left == NULL){
                                                	newNode->parent = current;
                                                	current->left = newNode;
                                                	cout << "\tadding the newNode to the left (and pushing to the list)" << endl;
                                                	ourList.push_back(current->left->value);
                                                	break;
                                                } else {
                                                	//if newNode value is less, move current to the left
                                                	current = current->left;
                                                	cout << "\tmoving to the left because the next node is occupied" << endl;
                                                }
                                                	
                                                	
                                        } else if(newNode->value > current->value){
                                        			cout << newNode->value << " > " << current->value << endl;
                                                
                                                //and check if it is filled.
                                                //if it is not filled already, then, we'll set current to newNode
                                                if(current->right == NULL){
                                                	newNode->parent = current;
                                                	current->right = newNode;
                                                	cout << "\tadding the newNode to the right (and pushing to the list)" << endl;
                                                	ourList.push_back(current->right->value);
                                                	break;
                                                } else {
                                                	//if the new value is bigger, move current to the right
                                                	current = current->right;
                                                	cout << "\tmoving to the right because the next node is occupied" << endl;
                                                }	
                                                	
                                        } else if(newNode->value == current->value){
                                        		 	break;
                                        } else break;
                                }
                        }
                }

                bool find(Object x){
                    current = root;
                    while(current != NULL){
                          	 if(x > current->value) current = current->right;
                            else if(x < current->value) current = current->left;
                            else if(current->value == x) return true;
                            else return false;
                    }
                }
                
                int findMin(){
                	  current = root;
                    while(current != NULL){
                          	 if(current->left != NULL) current = current->left;
                            else return current->value;
                    }
                }
                
                 int findMax(){
                	  current = root;
                    while(current != NULL){
                          	 if(current->right != NULL) current = current->right;
                            else return current->value;
                    }
                }
               
               //this is the function that gets called from the main program.
               list<Object> getList(){
               	ourList.sort();
               	return ourList;
               }
               


        private:
        list<Object> ourList;
        BSTNode * root;
        BSTNode * current;
};
