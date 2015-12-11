# simpleTree
the simplest possible binary tree.. 

With:
	* find()
	* findMin()
	* findMax()
		* These all call private methods return pointers to nodes
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

