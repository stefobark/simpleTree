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

	void makeList(BSTNode * current){
	      	ourList.push_back(current->value);
	      	if(current->left != NULL) makeList(current->left);
	      	if(current->right != NULL) makeList(current->right);
      	}
```

Now, the output looks like this:
```
at this point, the tree should be empty. Looking for a 1: 1

new value is smaller than current value: 8 < 10
	adding 8 to the left of current node with value 10
new value is bigger than current value: 11 > 10
	adding 11 to the right of current node with value 10
new value is smaller than current value: 9 < 10
	moving to the right so we can see how our new value compares to that node
new value is bigger than current value: 9 > 8
	adding 9 to the right of current node with value 8
new value is smaller than current value: 7 < 10
	moving to the right so we can see how our new value compares to that node
new value is smaller than current value: 7 < 8
	adding 7 to the left of current node with value 8
new value is bigger than current value: 12 > 10
	moving to the right so we can see how our new value compares to that node
new value is bigger than current value: 12 > 11
	adding 12 to the right of current node with value 11
new value is smaller than current value: 6 < 10
	moving to the right so we can see how our new value compares to that node
new value is smaller than current value: 6 < 8
	moving to the right so we can see how our new value compares to that node
new value is smaller than current value: 6 < 7
	adding 6 to the left of current node with value 7
	
did we find a 12? we should have a 1!! --> 1

an ordered list representing values in our tree: 6 7 8 9 10 11 12 

Min: 6, Max: 12
```


