#include"simpleTree.h"
#include<list>
using namespace std;
int main(){
        BST<int> tree;
        list<int> inOrder;
        cout << "at this point, the tree should be empty. Looking for a 1: " << tree.empty() << endl;

        tree.recursiveInsert(10);
        tree.recursiveInsert(8);
        tree.recursiveInsert(11);
        tree.recursiveInsert(9);
        tree.recursiveInsert(7);
        tree.recursiveInsert(12);
        tree.recursiveInsert(6);
        tree.recursiveInsert(13);
        tree.recursiveInsert(22);
        tree.recursiveInsert(18);
        tree.recursiveInsert(17);
        tree.recursiveInsert(16);
        tree.recursiveInsert(15);
        tree.recursiveInsert(23);
        tree.recursiveInsert(5);
        tree.recursiveInsert(24);
        
		  int f = tree.f();
		  cout << "f = " << f << endl;
        inOrder = tree.getList();
        cout << "an ordered list representing values in our tree: ";
        for(list<int>::iterator itr = inOrder.begin(); itr != inOrder.end(); itr++){
        		cout << *itr << " ";
        }
        cout << endl;
        cout << endl;
        
        cout << "Deleting Node with value of 10" << endl;
        tree.delNodeTwo(10);
        
        inOrder = tree.getList();
        cout << "an ordered list representing values in our tree: ";
        for(list<int>::iterator itr = inOrder.begin(); itr != inOrder.end(); itr++){
        		cout << *itr << " ";
        }
        cout << endl;
        cout << endl;
        
        cout << "Deleting Node with value of 6" << endl;
			tree.delNodeTwo(6);
			
		  inOrder = tree.getList();
        cout << "an ordered list representing values in our tree: ";
        for(list<int>::iterator itr = inOrder.begin(); itr != inOrder.end(); itr++){
        		cout << *itr << " ";
        }
        cout << endl;
        cout << endl;
			
			cout << "Deleting Node with value of 5" << endl;
			tree.delNodeTwo(5);
			
			inOrder = tree.getList();
        cout << "an ordered list representing values in our tree: ";
        for(list<int>::iterator itr = inOrder.begin(); itr != inOrder.end(); itr++){
        		cout << *itr << " ";
        }
        cout << endl;
        cout << endl;
		
			cout << "Deleting Node with value of 23" << endl;
			tree.delNodeTwo(23);
			
			inOrder = tree.getList();
        cout << "an ordered list representing values in our tree: ";
        for(list<int>::iterator itr = inOrder.begin(); itr != inOrder.end(); itr++){
        		cout << *itr << " ";
        }
        cout << endl;
        cout << endl;


	cout << "find height" << endl;
	int height = tree.findHeight();
	cout << "height: " << height << endl;
}	


