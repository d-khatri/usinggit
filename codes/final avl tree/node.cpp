#include "node.h"

using namespace std;

node::node()
{
    parent=NULL;
    left=NULL;
    right=NULL;
    key=0;
    height=0;
}

node::node(int keyValue)
{
    parent=NULL;
    left=NULL;
    right=NULL;
    key=keyValue;

}

node::~node()
{
    //dtor
}

int node::getKey(){
    return(key);
}

void node::setKey(int i){
key=i;
return;
}

node* node::getParent(){
    return(parent);
}

node* node::getLeft(){
    return(left);
}

node* node::getRight(){
    return(right);
}

bool node::setParent(node* parentNode){
    parent=parentNode;
    return(true);
}

bool node::setLeft(node* leftNode){
    left=leftNode;
    return(true);
}

bool node::setRight(node* rightNode){
    right=rightNode;
    return(true);
}

bool node::setHeight(int num){
height=num;
return true;
}

int node::getHeight(){
return (height);
}
