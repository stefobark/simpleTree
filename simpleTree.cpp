#include<iostream>
#include"simpleTree.h"
#include<list>
using namespace std;
int main(){
        BST<int> tree;
        list<int> inOrder;
        cout << "at this point, the tree should be empty. Looking for a 1: " << tree.empty() << endl;

        tree.insert(10);
        tree.insert(8);
        tree.insert(11);
        tree.insert(9);
        tree.insert(7);
        tree.insert(12);
        tree.insert(6);

        int found = tree.find(12);
        cout << "did we find a 12? we should have a 1!! --> " << found << endl;
        
        inOrder = tree.getList();
        cout << "an ordered list represent values in our tree: ";
        for(list<int>::iterator itr = inOrder.begin(); itr != inOrder.end(); itr++){
        		cout << *itr << " ";
        }
        cout << endl;
        
        int min = tree.findMin();
        int max = tree.findMax();
        
        cout << "Min: " << min << ", Max: " << max << endl;
}	

