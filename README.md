# simpleTree
the simplest possible binary tree
...made in the most complicated way.. i think it's still pretty ugly

I can't figure out the in order traversal... So, I kind of cheated. While inserting to the tree, I also insert into a list.. This could be wasteful, because.. what if the user never needs an ordered list of elements in the tree? It's always pushing into that list. But, I was getting tired of messing with traversing the tree and this idea seemed simple and easy. The list is initially unsorted, so I just call sort() before returning the ordered list :)

the current output of my test program demonstrates empty(), it explains the insertion, demonstrates find(), findMin() and findMax(), and i cout from the methods just so I can see how the program is working. in the future, i'll get rid of that stuff.
```
at this point, the tree should be empty. Looking for a 1: 1
8 < 10
	adding the newNode to the left (and pushing to the list)
11 > 10
	adding the newNode to the right (and pushing to the list)
9 < 10
	moving to the left because the next node is occupied
9 > 8
	adding the newNode to the right (and pushing to the list)
7 < 10
	moving to the left because the next node is occupied
7 < 8
	adding the newNode to the left (and pushing to the list)
12 > 10
	moving to the right because the next node is occupied
12 > 11
	adding the newNode to the right (and pushing to the list)
6 < 10
	moving to the left because the next node is occupied
6 < 8
	moving to the left because the next node is occupied
6 < 7
	adding the newNode to the left (and pushing to the list)

did we find a 12? we should have a 1!! --> 1

an ordered list representing values in our tree: 6 7 8 9 10 11 12 

Min: 6, Max: 12

```


