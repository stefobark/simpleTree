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
                                                	cout << "\tadding the newNode to the tree" << endl;
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
                                                	cout << "\tadding the newNode to the tree" << endl;
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
                
                Object findMin(){
                	  current = root;
                    while(current != NULL){
                          	 if(current->left != NULL) current = current->left;
                            else return current->value;
                    }
                }
                
                 Object findMax(){
                	  current = root;
                    while(current != NULL){
                          	 if(current->right != NULL) current = current->right;
                            else return current->value;
                    }
                }
               
               //this is the function that gets called from the main program.
               list<Object> getList(){
               	inOrder(root);
               	return ourList;
               }
               
               //this isn't right.. i can only work the left side of the tree. I haven't dug into the book yet.
               //trying to feel my way through it..
               void inOrder(BSTNode * current){
               	//we want to get to the lowest values first, so if current->left is not null, follow it (recursively)
                	 if(current->left != NULL) inOrder(current->left);
                	 //else if current->left is null, then we know we've reached the lowest, so push this value to the list
                	 else if(current->left == NULL){ 
                	 	ourList.push_back(current->value);
                	 	//now, we will work back up the list, using the parent pointer i added to the BSTNode struct
                	 	while(current->parent != NULL){
                	 		current = current->parent;
                	 		ourList.push_back(current->value);
                	 		//if there is an element to the right, push it to the list.
                	 		if(current->right != NULL){
                	 			 ourList.push_back(current->right->value); 
                	 		}
                	 	}
                	 }
              	}


        private:
        list<Object> ourList;
        BSTNode * root;
        BSTNode * current;
};
