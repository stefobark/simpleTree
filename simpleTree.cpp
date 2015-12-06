#include<iostream>
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

        int found = tree.find(12);
        cout << "did we find a 12? we should have a 1!! --> " << found << endl;
        
        /*inOrder = tree.getList();
        cout << "an ordered list represent values in our tree: ";
        for(list<int>::iterator itr = inOrder.begin(); itr != inOrder.end(); itr++){
        		cout << *itr << " ";
        }
        cout << endl;
        */
        
        int min = tree.findMin();
        int max = tree.findMax();
        
        cout << "Min: " << min << ", Max: " << max << endl;
}	


