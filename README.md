# simpleTree
the simplest possible binary tree.. 

With:
	* find()
	* findMin()
	* findMax()
		* These all call private methods return pointers to nodes
	* two versions of delete
	* insert
The output of the program looks like:

```
root@ubuntu:~/simpleTree# ./simpleTree
at this point, the tree should be empty. Looking for a 1: 1
f = 2
an ordered list representing values in our tree: 5 6 7 8 9 10 11 12 13 15 16 17 18 22 23 24 

Deleting Node with value of 10
deleting a root
an ordered list representing values in our tree: 5 6 7 8 9 11 12 13 15 16 17 18 22 23 24 

Deleting Node with value of 6
deleting a node with one child to the left
an ordered list representing values in our tree: 5 7 8 9 11 12 13 15 16 17 18 22 23 24 

Deleting Node with value of 5
deleting node with no children
an ordered list representing values in our tree: 7 8 9 11 12 13 15 16 17 18 22 23 24 

Deleting Node with value of 23
deleting a node with one child to the right
an ordered list representing values in our tree: 7 8 9 11 12 13 15 16 17 18 22 24 

Deleting Node with value of 22
deleting a node with two children
an ordered list representing values in our tree: 7 8 9 11 12 13 15 16 17 18 24 

find height
height: 6


```

