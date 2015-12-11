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
    //this was on our final test. not exactly sure what its for :)
    int f() {
		return f(root);
	 }
    void recursiveInsert(Object x){
        BSTNode * newNode = new BSTNode;
        newNode->value = x;
        insertRec(newNode, root);
    }
    BSTNode * find(Object x){
        BSTNode * answer = findRec(x, root);
	cout << "found node with value: " << answer->value;
    }
    //this was to call my first version of delete
    void delNode(Object x){
        deleteNodeRec(x, root);
    }
    //calls my second version of delete
    void delNodeTwo(Object x){
		  deleteNodeRecTwo(x, root);
   }
    int findMin(){
        int min = findMinRec(root)->value;
    }
    int findMax(){
        int max = findMaxRec(root)->value;
    }
    list<Object> getList (){
        current = root;
        if(ourList.empty() == 0) ourList.clear();
        makeList(current);
        ourList.sort();
        return ourList;
    }

   int findHeight(){
   if(root != NULL){
		int theHeight = heightRec(root);
		return theHeight;
	} else return 0; 
    }

    private:
    //private data members
    list<Object> ourList;
    BSTNode * root;
    BSTNode * current;
    int leftHeight = 1;
	 int rightHeight = 1;
    
    //from our final.. not sure about it.
    //I read about "?" and, i understand what it does,
    //but I don't understand why this would return 2 when I run it from my main program
    //seems that it should return rightS if true and leftS if false.
    //but, it doesn't return rightS->value or leftS->value..
    //so how does it add 1 to anything?
    //OHHHHH!!! leftS and rightS are ints!!
    //so maybe they are equal to 1 if they are present?
    //and maybe this method checks to see if the current node has 1 or two children?
    int f(BSTNode * cur) {
		if (cur == NULL)
			return 0;
		else {
			int leftS = f(cur->left);
			int rightS = f(cur->right);
			return 1 + (leftS>rightS ? rightS : leftS);
		}
	}

	/***************************************************
	this is my new version of delete, its still a little
	messy, but it uses a parent, instead of checking one
	node ahead. I've checked that it works on
			* nodes with no children
			* nodes with one child to the right
			* nodes with one child to the left
			* nodes with two children
			* and the root node
	***************************************************/
	
   void deleteNodeRecTwo(Object x, BSTNode * current){
		if(x == root->value){
			cout << "deleting a root" << endl;
			BSTNode & tmp = *root;
			BSTNode * left = root->left;
			BSTNode * right = root->right;
			BSTNode * maxLeft = findMaxRec(tmp.left);
			maxLeft->parent->right = NULL;
			tmp = *maxLeft;
			//just checking that the new current is actually what i wanted
			tmp.left = left;
			tmp.right = right;
			//just checking
			tmp.parent = NULL;
			root->parent = NULL;
			return;
		}
		//if current->value is smaller than x, move to current->right)
		if(current->value < x){			
		 	deleteNodeRecTwo(x, current->right);
		 }
		 //if current->value is bigger than x, move to current->left)
		else if(current->value > x){
			deleteNodeRecTwo(x, current->left);
		}
		//if we've found the node, and if the node has no children
		if(current->right == NULL && current->left == NULL && current->value == x){
			cout << "deleting node with no children" << endl;
			//if this node is to the right of the parent
			if(current->parent->value < current->value){
				current->parent->right = nullptr;
			}
			//if this node is to the left of the parent
			else if(current->parent->value > current->value){
			 	current->parent->left = nullptr;
			}
			delete current;
			return;
		 }
		//if the node has two children
		if(current->value == x && current->left != NULL && current->right != NULL){
			cout << "deleting a node with two children" << endl;
			//save the right pointer
			BSTNode * right = current->right;
			//tmp will reference the address of what current points to
			BSTNode & tmp = *current;
			//then, we'll make that be the max valued node to the left (and we're working directly with current's place in memory)
			tmp = *findMaxRec(tmp.left);
			//and now we use that node pointer we created in the beginning
			tmp.right = right;
			//just checking that the new current is actually what i wanted
			//and, finally, the new current's left node will be the max valued node to the left of the new current node
			tmp.left = findMaxRec(tmp.left);
			return;
		}
		//if the node has one child to the left
		if(current->left != NULL && current->right == NULL && current->value == x){
			cout << "deleting a node with one child to the left" << endl;
			current->parent->left = current->left;
			current->left->parent = current->parent;
			current = current->left;
			
			return;
		}
		//if the node has one child to the right
		if(current->right != NULL && current->left == NULL && current->value == x){
			cout << "deleting a node with one child to the right" << endl;
			current->parent->right = current->right;
			return;
		 }
   }
	//as I insert, I also add the parent
    void insertRec(BSTNode * newNode, BSTNode * current){
        //if the list is empty
        if(empty()){
            root = newNode;
        }
        //if the new value is bigger than the current value and the right node is null, just add the newNode to the right
        else if(newNode->value > current->value && current->right == NULL){
            current->right = newNode;
            current->right->parent = current;
            return;
        }
        //if the new value is bigger than the current value and the right node is not null, call this method again
        else if(newNode->value > current->value && current->right != NULL){
            current->right->parent = current;
            insertRec(newNode, current->right);
        }
        //if the new value is smaller than the current value and the left node is null, just add the newNode to the left
        else if(newNode->value < current->value && current->left == NULL){
            current->left = newNode;
            current->left->parent = current;
        }
        //if the new value is smaller than the current value and the left node is not null, call this method again
        else if(newNode->value < current->value && current->left != NULL){
            current->left->parent = current;
            insertRec(newNode, current->left);
        }
        else if(newNode->value == current->value) return;
    }
    //returns a pointer to a Node, this is useful for delete
    BSTNode * findRec(Object x, BSTNode * current){
        if(x > current->value) findRec(x, current->right);
        else if(x < current->value) findRec(x, current->left);
        else if(current->value == x) return current;
        else return 0;
    }
    //returns a pointer to a Node, this is useful for delete
    BSTNode * findMinRec(BSTNode * current){
        if(current->left != NULL ) findMinRec(current->left);
        else return current;
    }
    //returns a pointer to a Node, this is useful for delete
    BSTNode * findMaxRec(BSTNode * current){
        if(current->right != NULL) findMaxRec(current->right);
        
        else return current;
    }
    /*********************************************************************
    this is my old version of delete. it works, but its messy and tooo big
    *********************************************************************/
    void deleteNodeRec(Object x, BSTNode * current ){
        //if this happens, we know that value is not in our tree, just tell me its not there and return
        if(current == NULL){
            cout << "element not in list" << endl;
            return;
        }
        //if we want to delete the root, we have to make a new root and return
        if(x == root->value){
            BSTNode * nodeToDelete;
            nodeToDelete = current;
            //i made this tmpNode to keep track of what the root is pointing to on the left
            BSTNode * tmpNode;
            tmpNode = root;
            root = current->right;
            root->left = tmpNode->left;
            delete nodeToDelete;
            return;
        }
        //if the left node is not null, and x is greater than the left node, move there to evaluate again
        if(current->left != NULL && x < current->left->value){
            deleteNodeRec(x, current->left);
        }
        //if the left node is not null, and the left node's value is equal to x, let's destroy it!
        else if( current->left != NULL && current->left->value == x) {
            BSTNode * nodeToDelete;
            nodeToDelete = current->left;
            BSTNode * tmpNode;
            tmpNode = current->left->left;
            delete nodeToDelete;
            current->left = tmpNode;
        }
        //if the right node is not null, and x is greater than the right node, move there to evaluate again
        else if(current->right != NULL && x > current->right->value){
            deleteNodeRec(x, current->right);
        }
        //if the right node is not null, and the right node's value is equal to x, let's destroy it!
        else if( current->right != NULL && current->right->value == x) {
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
            BSTNode * nodeToDelete;
            nodeToDelete = current->left;
            BSTNode * tmpNode;
            tmpNode = current->left->left;
            current->left = current->left->right;
            current->left->left = tmpNode;
            delete nodeToDelete;
        }
    }
    //this gets called from getList()
    //it will traverse the tree from the root and go to the left or right of each node as long as they're not null
    void makeList(BSTNode * current){
    	
        ourList.push_back(current->value);
        if(current->left != NULL) makeList(current->left);
        if(current->right != NULL) makeList(current->right);
    }
    //
    int heightRec(BSTNode * current){
		
		if(current->left != NULL){
			leftHeight++;
			heightRec(current->left);
			
		} 
		
		if(current->right != NULL){
			 rightHeight++;
			 heightRec(current->right);
			 
		}
		if(leftHeight > rightHeight) return leftHeight;
		else return rightHeight;
    }
};
