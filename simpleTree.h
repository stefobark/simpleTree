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
                
                int findMin(){
                	findMinRec(root);
                }
                
                int findMax(){
                	findMaxRec(root);
                }
               
                list<Object> getList (){
                	makeList(root);
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
					cout << "\tadding " << newNode->value << " to the right of current node with value " << current->value << endl;
					current->right = newNode;
					return;
				}
				else if(newNode->value > current->value && current->right != NULL){
					cout << "new value is bigger than current value: " << newNode->value << " > " << current->value << endl;
					cout << "\tmoving to the right so we can see how our new value compares to that node" << endl;
				 	insertRec(newNode, current->right);
				}
				else if(newNode->value < current->value && current->left == NULL){
				cout << "new value is smaller than current value: " << newNode->value << " < " << current->value << endl;
				cout << "\tadding " << newNode->value << " to the left of current node with value " << current->value << endl;
					current->left = newNode;
					return;
				}
				else if(newNode->value < current->value && current->left != NULL){
					cout << "new value is smaller than current value: " << newNode->value << " < " << current->value << endl;
					cout << "\tmoving to the right so we can see how our new value compares to that node" << endl;
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
		
		int findMinRec(BSTNode * current){
        	 if(current->left != NULL) findMinRec(current->left);
          else return current->value;
      }
      
      int findMaxRec(BSTNode * current){
        	if(current->right != NULL) findMaxRec(current->right);
         else return current->value;
      }
      
      void makeList(BSTNode * current){
      	ourList.push_back(current->value);
      	if(current->left != NULL) makeList(current->left);
      	if(current->right != NULL) makeList(current->right);
      }
};

