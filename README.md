# simpleTree
the simplest possible binary tree
...made in the most complicated way.. i think it's still pretty ugly

I can't figure out the in order traversal

Here's what I have so far:

```
 //this is the function that gets called from the main program.
               list<Object> getList(){
               	inOrder(root);
               	return ourList;
               }
               
               //this isn't right.. i can only work the left side of the tree. 
               //and I haven't dug into the book yet to see the correct way to do this.
               //trying to feel my way through it..
               
               void inOrder(BSTNode * current){
               	//we want to get to the lowest values first, so if current->left is not null, follow it (recursively)
                	 if(current->left != NULL) inOrder(current->left);
                	 
                	 //else if current->left *is* null, then we know we've reached the lowest value, 
                	 //so push this value to the list
                	 else if(current->left == NULL){ 
                	 	ourList.push_back(current->value);
                	 	
                	 	//now, we will work back up the list, using the parent pointer i added to the BSTNode struct
                	 	//so, while the parent is not null, and only the root's parent will be null
                	 	while(current->parent != NULL){
                	 		current = current->parent;
                	 		ourList.push_back(current->value);
                	 		
                	 		//if there is an element to the right, push it to the list.
                	 		//but, this won't get at the nested elements on the left side!! and it won't go past root->right
                	 		if(current->right != NULL){
                	 			 ourList.push_back(current->right->value); 
                	 		}
                	 	}
                	 }
              	}
```

the current output of my test program demonstrates empty(), it explains the insertion, demonstrates find(), findMin() and findMax(), but I'm getting stuck at creating an ordered list... and i cout from the methods just so I can see how the program is working. in the future, i'll get rid of that stuff.
