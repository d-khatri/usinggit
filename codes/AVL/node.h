#ifndef NODE_H
#define NODE_H
#include<iostream>

using namespace std;

class node
{
    public:
        node();
        node(int keyValue);
        virtual ~node();
        node* getParent();
        bool setParent(node* parentNode);
        node* getLeft();
        bool setLeft(node* leftNode);
        node* getRight();
        bool setRight(node* rightNode);
        int getKey();
        int getHeight(node *n);
        bool setHeight(int);
		void setKey(int i);
    protected:
    private:
        node* parent;
        node* left;
        node* right;
        int height;
        int key;
};

#endif // NODE_H
