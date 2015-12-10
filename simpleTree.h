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
    void recursiveInsert(Object x){
        BSTNode * newNode = new BSTNode;
        newNode->value = x;
        insertRec(newNode, root);
    }
    BSTNode * find(Object x){
        BSTNode * answer = findRec(x, root);
	cout << "found node with value: " << answer->value;
    }
    void delNode(Object x){
        deleteNodeRec(x, root);
    }
    void delNodeTwo(Object x){
		  deleteNodeRecTwo(x, root);
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

   int findHeight(){
	if(root == NULL) height = 0;
	else height = 1;
	int theHeight = heightRec(root);
	return theHeight;
    }

    private:
    //private data members
    list<Object> ourList;
    BSTNode * root;
    BSTNode * current;
    int height;

	/***************************************************
	this is my new version of delete, its still a little
	messy, but its smaller and still works!
	I'm printing a lot of stuff to help me see how it's
	working.
	***************************************************/
	
   void deleteNodeRecTwo(Object x, BSTNode * current){
		if(x == root->value){
			BSTNode & tmp = *root;
			BSTNode * left = root->left;
			BSTNode * right = root->right;
			BSTNode * maxLeft = findMaxRec(tmp.left);
			cout << "first maxLeft = " << maxLeft->value << endl;
			maxLeft->parent->right = NULL;
			tmp = *maxLeft;
			//just checking that the new current is actually what i wanted
			cout << "new current : " << current->value <<endl;
			cout << "maxLeft = " << maxLeft->value << endl;
			tmp.left = left;
			tmp.right = right;
			cout << "maxLeft = " << tmp.left->value << endl;
			//just checking
			cout << "current->left = " << tmp.left->value << endl;
			cout << "current->left = " << tmp.right->value << endl;
			tmp.parent = nullptr;
			root->parent = NULL;
			return;
		}
		
		//show me the parent and the current
		if(current->parent != NULL) cout << "parent = " << current->parent->value << endl;
		cout << "current = " << current->value << endl;
		
		//if current->value is smaller than x, move to current->right)
		
		if(current->value < x){
		 	deleteNodeRecTwo(x, current->right);
		 }
		 //if current->value is bigger than x, move to current->left)
		else if(current->value > x){
			deleteNodeRecTwo(x, current->left);
		}
		//if we've found the node, and if the node has no children
		else if(current->value == x && current->right == NULL && current->left == NULL){
			BSTNode * tmp = current;
			cout << "current value = " << tmp->value << endl;
			BSTNode * parent = current->parent;
			cout << "parent value = " << parent->value << endl;
			
			if(parent->value < tmp->value) parent->right = NULL;
			if(parent->value > tmp->value) parent->left = NULL; 
			current = NULL;
			delete tmp;
		 }
		//if the node has two children
		else if(current->value == x && current->left != NULL && current->right != NULL){
			//save the right pointer
			BSTNode * right = current->right;
			//tmp will reference the address of what current points to
			BSTNode & tmp = *current;
			//then, we'll make that be the max valued node to the left (and we're working directly with current's place in memory)
			tmp = *findMaxRec(tmp.left);
			//and now we use that node pointer we created in the beginning
			tmp.right = right;
			//just checking that the new current is actually what i wanted
			cout << "new current : " << tmp.value <<endl;
			//and, finally, the new current's left node will be the max valued node to the left of the new current node
			tmp.left = findMaxRec(tmp.left);
			//just checking
			cout << "tmp.left = " << tmp.left->value << endl;
		}
		//if the node has one child to the left
		else if(current->value == x && current->left != NULL && current->right == NULL){
			BSTNode & tmp = *current;
			tmp = *current->left;
			cout << "new current value: " << current->value << endl;
		}
		//if the node has one child to the right
		else if(current->value == x && current->right != NULL && current->left == NULL){
			BSTNode * tmp = current;
			tmp = current->right;
			cout << "new current value: " << current->value << endl;
		 }
		
		
   }

    void insertRec(BSTNode * newNode, BSTNode * current){
        //if the list is empty
        if(empty()){
            root = newNode;
        }
        //if the new value is bigger than the current value and the right node is null, just add the newNode to the right
        else if(newNode->value > current->value && current->right == NULL){
            cout << "new value is bigger than current value: " << newNode->value << " > " << current->value << endl;
            cout << "\tadding " << newNode->value << " to the right of current node with value " << current->value << endl;
            current->right = newNode;
            newNode->parent = current;
            return;
        }
        //if the new value is bigger than the current value and the right node is not null, call this method again
        else if(newNode->value > current->value && current->right != NULL){
            cout << "new value is bigger than current value: " << newNode->value << " > " << current->value << endl;
            cout << "\tmoving to the right so we can see how our new value compares to that node" << endl;
            newNode->parent = current;
            insertRec(newNode, current->right);
        }
        //if the new value is smaller than the current value and the left node is null, just add the newNode to the left
        else if(newNode->value < current->value && current->left == NULL){
            cout << "new value is smaller than current value: " << newNode->value << " < " << current->value << endl;
            cout << "\tadding " << newNode->value << " to the left of current node with value " << current->value << endl;
            newNode->parent = current;
            current->left = newNode;
           
            return;
        }
        //if the new value is smaller than the current value and the left node is not null, call this method again
        else if(newNode->value < current->value && current->left != NULL){
            cout << "new value is smaller than current value: " << newNode->value << " < " << current->value << endl;
            cout << "\tmoving to the right so we can see how our new value compares to that node" << endl;
            newNode->parent = current;
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
            cout << "\tcurrent: " << current->value << endl;
            cout << "\tdeleting root" << endl;
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
            cout << "\tleft node = " << current->left->value << endl;
            deleteNodeRec(x, current->left);
        }
        //if the left node is not null, and the left node's value is equal to x, let's destroy it!
        else if( current->left != NULL && current->left->value == x) {
            cout << "\tdeleting node with value = " << current->left->value << endl;
            BSTNode * nodeToDelete;
            nodeToDelete = current->left;
            BSTNode * tmpNode;
            tmpNode = current->left->left;
            delete nodeToDelete;
            current->left = tmpNode;
        }
        //if the right node is not null, and x is greater than the right node, move there to evaluate again
        else if(current->right != NULL && x > current->right->value){
            cout << "\tright node = " << current->right->value << endl;
            deleteNodeRec(x, current->right);
        }
        //if the right node is not null, and the right node's value is equal to x, let's destroy it!
        else if( current->right != NULL && current->right->value == x) {
            cout << "\tdeleting node with value = " << current->value << endl;
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
    
    int heightRec(BSTNode * current){
	if(current->left != NULL){
		heightRec(current->left);
		height++;
	} 
	if(current->right != NULL){
		 heightRec(current->right);
	}
	return height;
    }
};
