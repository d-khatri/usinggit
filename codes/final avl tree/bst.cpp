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


int bst::updateHeight(node *n){
	if(n->getLeft() && n->getRight()){
		if( n->getLeft()->getHeight() > n->getRight()->getHeight() )	{	n->setHeight((n->getLeft()->getHeight())+1);  return true;}
		else { n->setHeight((n->getRight()->getHeight())+1); }
	}
	else if(n->getLeft()){
		n->setHeight((n->getLeft()->getHeight())+1);
	}
	else if(n->getRight()){
		n->setHeight((n->getRight()->getHeight())+1);
	}
	else { n->setHeight(0); }
	return (n->getHeight());
}


int bst::getBalance(node*n){
	if(n->getLeft()!=NULL && n->getRight()!=NULL){
		return ( ( n->getLeft()->getHeight() ) - ( n->getRight()->getHeight() ) );
	}
	else if(n->getLeft()!=NULL){
		return (n->getLeft()->getHeight()+1);
	}
	else if(n->getRight()!=NULL){
		return (-1*((n->getRight()->getHeight())+1));
	}
	else return 0;
}

void bst::rotateLeft(node* n){
	node* p=n->getParent();
	enum {left,right} side;
	int flag=0;
	if(p!=NULL){
		if(p->getLeft()==n) side=left;
		else side=right;	
	}
	
	node *temp=n->getRight();
	if(temp->getRight()) flag=1;
	if(temp->getLeft()!=NULL){
		n->setRight(temp->getLeft());
		temp->getLeft()->setParent(n);	
	} else {
		n->setRight(NULL);
	}
	temp->setLeft(n);
	n->setParent(temp);
	
	if(p!=NULL){
		if(side==left) { p->setLeft(temp); temp->setParent(p); }
		else { p->setRight(temp); temp->setParent(p); }
	} else  {
		head=temp;
		if(head!=NULL)head->setParent(NULL);
	}
	
	if(flag==1){n->setHeight((n->getHeight())-2); }
	else{n->setHeight((n->getHeight())-1);temp->setHeight((temp->getHeight())+1);  }
	//cout<<"passed key's and its parent's height "<<n->getHeight()<<" "<<n->getParent()->getHeight()<<endl;
}

void bst::rotateRight(node* n){
	node* p=n->getParent();
	enum {left,right} side;
	int flag=0;
	if(p!=NULL){
		if(p->getLeft()==n) side=left;
		else side=right;	
	}
	
	node *temp=n->getLeft();
	if(temp->getLeft())flag=1;
	if(temp->getRight()!=NULL){
		n->setLeft(temp->getRight());
		temp->getRight()->setParent(n);	
	} else{
		n->setLeft(NULL);
	}
	temp->setRight(n);
	n->setParent(temp);
	if(p!=NULL){
		if(side==left) { p->setLeft(temp); temp->setParent(p); }
		else { p->setRight(temp); temp->setParent(p); }
	} else  {
		head=temp;
		if(head!=NULL)head->setParent(NULL);
	}
	
	if(flag==1){
		n->setHeight((n->getHeight())-2) ;
	} else{
		cout<< n->setHeight((n->getHeight())-1); temp->setHeight((temp->getHeight())+1); 
	}
	
	//cout<<"passed key's and its parent's height "<<n->getHeight()<<" "<<n->getParent()->getHeight()<<endl; 
}

void bst::balanceatNode(node* n){
	int bal=getBalance(n);
	//cout<<"balance at "<<n->getKey()<<"is "<<bal<<endl;
	if(bal>1){
		if( getBalance(n->getLeft()) < 0 ){ rotateLeft(n->getLeft()); }
		rotateRight(n);
	}
	else if(bal<-1){
		if( getBalance(n->getRight()) > 0 ){rotateRight(n->getRight()); }
		rotateLeft(n);
	}
}



bool bst::treeInsertNode(node* newNode){
    if(head==NULL){
        head=newNode;
        head->setHeight(0);       
	return(true);
    }else{
        return(insertNode(newNode, head));
    }

}

bool bst::insertNode(node* newNode, node* headNode){
	if(headNode->getKey()==newNode->getKey()){
	cout<<"Cannot insert duplicates for "<<newNode->getKey()<<endl;
	return(false);
	} 
	
	else if(newNode->getKey() > headNode->getKey()){
		if(headNode->getRight()==NULL){
			headNode->setRight(newNode);
			newNode->setParent(headNode);
			node* temp=newNode,*var=NULL;
			while(temp!=NULL){
				var=temp->getParent();
				updateHeight(temp);
	        	balanceatNode(temp);
	        	temp = var;
	        }
	        return(true);
		}
		else{
			return(insertNode(newNode, headNode->getRight()));
		}
	}
	
	else if(newNode->getKey() < headNode->getKey()){
		if(headNode->getLeft()==NULL){
			headNode->setLeft(newNode);
			newNode->setParent(headNode);
			node* temp=newNode,*var=NULL;
			while(temp!=NULL){
				//cout<<"temp is "<<temp->getKey()<<endl;
				var=temp->getParent();
	        	updateHeight(temp);
	        	balanceatNode(temp);
	        	temp = var;
	        }
			return(true);
			} else{
				return(insertNode(newNode, headNode->getLeft()));
			}
		}

	}


void bst::deleteNode(node* victimNode){
	int temps;
	node *succesr,*temp;
	enum {left,right} side;
	node *p=victimNode->getParent();
	int bal=getBalance(victimNode);
	if(p!=NULL){
		if(p->getLeft()==victimNode) side=left;
		else side=right;
	}
	
/*case1*/if(NULL == victimNode -> getLeft() && NULL == victimNode -> getRight()){    //leaf child 
		if(p!=NULL){
			if(side==left) victimNode -> getParent() -> setLeft(NULL);
			else victimNode -> getParent()->setRight(NULL);
	      	updateHeight(p);
	      	balanceatNode(p);
	      } else head=NULL;
	     delete victimNode;
    return;
    }

/*case2*/if(victimNode -> getLeft()!= NULL && victimNode -> getRight() ==NULL) {         //one with left child            
		if(p!=NULL){
			if(side==left){
				victimNode->getLeft()->setParent(p);
				p->setLeft(victimNode->getLeft());
			} else{
				p->setRight(victimNode->getLeft());
				victimNode->getLeft()->setParent(p);
			}
			delete victimNode;
			updateHeight(p);
			balanceatNode(p);
		} else { head=victimNode->getLeft(); }
		delete victimNode;
    return;
    }
    

/*case3*/if(victimNode ->getRight() != NULL && victimNode -> getLeft() ==NULL) {        //onewithrightchild                  
		if(p!=NULL){
			if(side==left){
				victimNode->getRight()->setParent(p);
				p->setLeft(victimNode->getRight());
			} else{
				victimNode->getRight()->setParent(p);
				p->setRight(p);
			}
			updateHeight(p);
			balanceatNode(p);
		}
		else head=victimNode->getRight();
		delete victimNode;
    return;
    }	
							
	 else{					//victim with both left and right child
		node* replacement;
	 	succesr=successor(victimNode);
		if(bal>0){
			if(NULL == victimNode->getRight()-> getLeft()){
				replacement=victimNode->getRight();
				replacement->setLeft(victimNode->getLeft());
				victimNode->getLeft()->setParent(replacement);
				replacement->setRight(NULL);
				temp=replacement;
				}
			else{ 										//sucsrr with left child not possible and successor  with both child also not possible
				replacement=succesr;				// successr with 0 child or onr right child
				if(replacement->getRight()){
					replacement->getRight()->setParent(replacement->getParent());
					replacement->getParent()->setLeft(replacement->getRight());
				}
				else { replacement->getParent()->setLeft(NULL);}
				temp=replacement->getParent();
				replacement->setLeft(victimNode->getLeft());
				replacement->setRight(victimNode->getRight());
			}
		}
		else{            														//bal<0
			if(NULL == victimNode->getLeft()->getRight() ){
				replacement=victimNode->getLeft();
				replacement->setRight(victimNode->getRight());
				victimNode->getRight()->setParent(replacement);
				temp=replacement;
				}
			else{ 															//sucsrr with left child not possible and successor
				replacement=succesr;
				if(replacement->getRight()){									//with both child also not possible
					replacement->getRight()->setParent(replacement->getParent());	
					replacement->getParent()->setLeft(replacement->getRight());
				}
				else { replacement->getParent()->setLeft(NULL);}
				temp=replacement->getParent();
				replacement->setLeft(victimNode->getLeft());
				replacement->setRight(victimNode->getRight());											
			}
		
		}
	if(p!=NULL){
		if(side == left) {
			p->setLeft(replacement);
			replacement->setParent(p);
		}
        else { p->setRight(replacement); replacement->setParent(p); }
        delete victimNode;
	}
	else{
		head=replacement;
		replacement->setParent(NULL);
		delete victimNode;
	}
    balanceatNode(temp);
    return;
    }
}


