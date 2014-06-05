#ifndef BST_H
#define BST_H

#include "node.h"

using namespace std;

class bst
{
    public:
        bst();
        bool insertNode(node* newNode, node* headNode);
        bool treeInsertNode(node* newNode);
		node* successor(node* findposresult);       
		void deleteNode(node* victimNode);
        node* searchKey(int, node*);
        node* treeSearchKey(int);
        bool inorderTraversal(node* headNode);
        bool treeInorderTraversal();
        //int treeHeight(node *victimnode);
		//int setHeight();
		int updateHeight(node* n);
		int getBalance(node* n);
		void rotateLeft(node* n);
		void rotateRight(node* n);
		void balanceatNode(node* n);
		
        virtual ~bst();
    protected:
    private:
        node* head;
};

#endif // BST_H
