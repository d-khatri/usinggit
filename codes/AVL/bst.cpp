#include "bst.h"
#include <math.h>
using namespace std;

bst::bst()
{
    head=NULL;
}

bst::~bst()
{
    //dtor
}


bool bst::inorderTraversal(node* headNode){
    if(headNode==NULL){
        return(true);
    }else{
        inorderTraversal(headNode->getLeft());
        if(headNode->getParent()!=NULL){
            cout<<"Key is "<<headNode->getKey()<<" Parent is "<<headNode->getParent()->getKey()<<endl;
        }else{
            cout<<"Key is "<<headNode->getKey()<<" Parent is NULL"<<endl;
        }

        inorderTraversal(headNode->getRight());

    }
    return(true);
}

bool bst::treeInsertNode(node* newNode){
    if(head==NULL){
        head=newNode;       
	return(true);
    }else{
        return(insertNode(newNode, head));
    }

}

bool bst::insertNode(node* newNode, node* headNode){

    if(headNode->getKey()==newNode->getKey()){
        cout<<"Cannot insert duplicates for "<<newNode->getKey()<<endl;
        return(false);
    }else if(headNode->getKey()<newNode->getKey()){
        if(headNode->getRight()==NULL){
            headNode->setRight(newNode);
            newNode->setParent(headNode);
            return(true);
        }else{
            return(insertNode(newNode, headNode->getRight()));
        }
    }else if(headNode->getKey()>newNode->getKey()){
        if(headNode->getLeft()==NULL){
            headNode->setLeft(newNode);
            newNode->setParent(headNode);
            return(true);
        }else{
            return(insertNode(newNode, headNode->getLeft()));
        }
    }

}

node* bst::successor(node *findposresult){
node *x ,*y;
	if(findposresult -> getRight()){
	findposresult=findposresult->getRight();
		while(NULL!=findposresult->getLeft()){
		findposresult=findposresult->getLeft();
		}
	return findposresult;
	} else {
	x = findposresult;
	y = findposresult -> getParent();
		while(y ->getLeft()!= x){
		x=y;
		y=y ->getParent();
		}
	return y;
	}
}

void bst::deletepart(node* anynode){
anynode->setParent(NULL);
anynode->setParent(NULL);
anynode->setParent(NULL);
}

void bst::swaps(node *x,node*y){
int temps;
node *temp1,*temp2;
temps = y ->getKey();
y ->setKey(x ->getKey());
x ->setKey(temps);
}


void bst::deleteNode(node* victimNode){
	node* findposresult,*succesr;
	findposresult=victimNode;
	node *x,*y,*z;
	int temps;
/*case1*/if(NULL == findposresult -> getLeft() && NULL == findposresult -> getRight()){    //leaf child 
    	x=findposresult;
    	y=findposresult->getParent();
		if(y ->getLeft()!=NULL ){                
		y ->setLeft(NULL);
		deletepart(x);
		} else {
		y -> setRight(NULL);;
		deletepart(x);
	       }
    return;
    }

/*case2*/if(findposresult -> getLeft()!= NULL && findposresult -> getRight() ==NULL) {         //one with left child            
    	x=findposresult;
    	y=findposresult->getParent();
		if(y ->getLeft()== x){
		//x -> left -> parent = y;
		z=x -> getLeft();
		z->setParent(y);	
		y ->setLeft(x ->getLeft());
		deletepart(x);
		} else{
		//x -> left -> parent = y;
		z=x -> getLeft();
		z->setParent(y);				
		y -> setRight(x ->getLeft());
		deletepart(x);
		}
    return;
    }
    

/*case3*/if(findposresult ->getRight() != NULL && findposresult -> getLeft() ==NULL) {        //onewithrightchild                  
    	x=findposresult;
    	y=findposresult->getParent();
		if(y ->getLeft() ==x){
		//x -> right -> parent = y;
		z=x->getRight();
		z->setParent(y);		
		y ->setLeft(x ->getRight());
		deletepart(x);
		} else{
		//x -> right -> parent = y;
		z=x->getRight();
		z->setParent(y);		
		y ->setRight(x ->getRight());
		deletepart(x);
		}
    return;
    }	
	//if for successor we have to move to parent then possiblities
	 else{						//one with both left and right child
	 node *copyofpos;	 
	 copyofpos=findposresult;
	 succesr=successor(findposresult);
		if(NULL == succesr -> getRight() && NULL == succesr -> getLeft()){
		    swaps(copyofpos,succesr);
		    x=succesr;
		    y=succesr->getParent();
		    y->setRight(NULL);
		    deletepart(succesr);
		    }
		if(succesr->getRight() != NULL && NULL == succesr->getLeft()){ 	//sucsrr with left child not possible and successor
		swaps(copyofpos,succesr);					//with both child also not possible
		x=succesr;
		y=succesr->getParent();
		y->setRight(succesr->getRight());
		//succesr->right->parent=y;
		z=succesr->getRight();
		z->setParent(y);		
		deletepart(x);
		}
    return;
    }
}


node* bst::searchKey(int keyValue, node* headNode){
    if(headNode==NULL){
        return(NULL);
    }

    if(headNode->getKey()==keyValue){
        return(headNode);
    }

    if(headNode->getKey()<keyValue){
        return(searchKey(keyValue, headNode->getRight()));
    }else{
        return(searchKey(keyValue, headNode->getLeft()));
    }


}


node* bst::treeSearchKey(int keyValue){
    return(searchKey(keyValue, head));
}


bool bst::treeInorderTraversal(){
    return(inorderTraversal(head));
}

/*int bst::treeHeight(node *victimnode){
	int hl=0,hr=0;
	if(NULL==victimnode) return 0;
	hl=treeHeight(victimnode->getLeft());
	hr=treeHeight(victimnode->getRight());
	return (max(hl,hr)+1);
	//implement this function to return height of the tree
    //empty tree has height 0
    //tree with single node has height 1
}*/

/*int bst::setHeight(){
return(treeHeight(head));
}*/


bool bst::updateHeight(node *n){
	if(n->getLeft() && n->getRight()){
		if( getHeight(n->getLeft) > getHeight(n->getRight) )	{	n->setHeight(getHeight(n->getLeft)+1);  return true;}
		else { n->setHeight(getHeight(n->getRight)+1);  return true;}
	}
	else if(n->getLeft){
		n->setHeight(getHeight(n->getLeft)+1);
		return true;
	}
	else if(n->getRight){
		n->setHeight(getHeight(n->getRight)+1);
		return true;
	}
	else { n->setRight(0); return true;}
}


int bst::getBalance(node*n){
	if(n->getLeft() && n->getRight()){
		return ((n->getLeft()->getHeight)-(n->getRight()->getHeight));
	}
	else if(n->getLeft){
		return (n->getLeft()->getHeight)
	}
	else if(n->getRight){
		return (n->getRight()->getHeight);
	}
	else return 0;
}

void bst::rotateLeft(node* n){
	node* p=n->getParent();
	
	if(p!=NULL){
		enum {left,right} side;
		if(p->getLeft==n) side=left;
		else side=right;	
	}
	
	node *temp=n->getRight();
	n->setRight(temp->getLeft());	
	temp->setLeft(n);
	
	if(p!=NULL){
		if(side==left) p->setLeft(n);
		else p->setRight(n);
	} else  {
		head=temp;
		if(head!=NULL)head->setParent(NULL);
	}

}

void bst::rotateRight(node* n){
	node* p=n->getParent();
	
	if(p!=NULL){
		enum {left,right} side;
		if(p->getLeft==n) side=left;
		else side=right;	
	}
	
	node *temp=n->getRight();
	n->setRight(temp->getLeft());	
	temp->setLeft(n);
	
	if(p!=NULL){
		if(side==left) p->setLeft(n);
		else p->setRight(n);
	} else  {
		head=temp;
		if(head!=NULL)head->setParent(NULL);
	}

}
