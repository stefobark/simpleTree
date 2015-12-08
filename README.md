# simpleTree
the simplest possible binary tree.. 

I made all the methods recursive. The public methods need access to a private data member(root), for their starting point. So, for insert(), findMin(), findMax() and find(), I made a public method that calls a private method and passes along root... because the main program won't have access to root.

I'm getting closer to properly creating an ordered list that represents elements in the tree! Previously, I inserted values into a list every time I inserted into a tree.. That was wasteful. Now, I have a recursive method that starts at root and traverses all nodes of the tree and pushes the values into a list until it reaches NULL (until it hits the leaves). Still, I think it could be better. To actually order the list that is generated, i just use the standard library's list.sort() before returning the list to the user.

The getList() and makeList() methods are really simple, but like the others, it gets called from a public method so I can pass root to it. Each time it moves to a node it will check if there are left and right nodes, if there are, it will move to them and push their values. Playing with recursion more helped me understand how to do this...:
```
public:
	list<Object> getList (){
        	makeList(root);
        	ourList.sort();
        	return ourList;
        }
private:
	void makeList(BSTNode * current){
	      	ourList.push_back(current->value);
	      	if(current->left != NULL) makeList(current->left);
	      	if(current->right != NULL) makeList(current->right);
      	}
```
After adding a delete method, and adding a few more values to the tree... the output looks like this (I also changed findMin and findMax to return pointers to nodes instead of ints.. more useful.. and I ommitted all the details about inserting to the tree, because that part works now):

```
at this point, the tree should be empty. Looking for a 1: 1

did we find a 12? we should have a 1!! --> 1

an ordered list representing values in our tree: 6 7 8 9 10 11 12 13 15 16 17 18 22 

Deleting Node with value of 16
	right node = 11
	right node = 12
	right node = 13
	using findMinRec... right node = 22
	left node = 18
	left node = 17
deleting node with value = 16

an ordered list representing values in our tree: 6 7 8 9 10 11 12 13 15 17 18 22 

```
There are conditions that check if the node has one child or two, and if the node is the root.. more details in comments in simpleTree.h

