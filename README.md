# simpleTree
the simplest possible binary tree.. 

I made all the methods recursive. The public methods need access to a private data member(root), for their starting point. So, I for insert, findMin, findMax and find, I made a public method that calls a private method and passes along root... because the main program won't have access to root.

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

Min: 6, Max: 12


```


