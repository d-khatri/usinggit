#include <iostream>
#include "node.h"
#include "bst.h"

using namespace std;

int main()
{
    bst* tree1=NULL;
    int key;
    int choice;
    node* n1=NULL;
    bool result;

do{
	/*cout<<"1. Create new tree"<<endl;
	cout<<"2. Add new key to the tree"<<endl;
	cout<<"3. Search a key in the tree"<<endl;
	cout<<"4. Delete a key from the tree"<<endl;
	cout<<"5. Inorder traversal of the tree"<<endl;
	//cout<<"6. not now active Height of the tree"<<endl;
	cout<<"Any other choice to exit"<<endl;*/
	cout<<"Enter your choice:";
	cin>>choice;
	cout<<"You entered "<<choice<<endl;
	switch(choice){
		case 1:
			if(tree1!=NULL){
				delete tree1;
			}
			tree1 = new bst();
			break;

		case 2:
			if(tree1==NULL){
				cout<<"Create a new tree first"<<endl;
				break;
			}
			cout<<"Enter key to add ";
			cin>>key;
			n1=new node(key);
			result=tree1->treeInsertNode(n1);
			if(result==false){
		                cout<<"Could not insert key"<<endl;
			}else{
                		cout<<"Inserted key "<<key<<endl;
			}
			break;

		case 3:
			if(tree1==NULL){
				cout<<"Create a new tree first"<<endl;
				break;
			}
			cout<<"Enter key to search";
			cin>>key;
			n1=tree1->treeSearchKey(key);
			if(n1==NULL){
                		cout<<"Key "<<key<<" not found."<<endl;
			}else{
		                cout<<"Key "<<key<< "found"<<endl;
			}
			break;

		case 4:
			if(tree1==NULL){
				cout<<"Create a new tree first"<<endl;
				break;
			}
			cout<<"Enter key to delete";
			cin>>key;
			n1=tree1->treeSearchKey(key);
			if(n1==NULL){
                cout<<"Key "<<key<<" not found."<<endl;
			}else{
                cout<<"Entered key is "<<key<<endl;
                tree1->deleteNode(n1);
			}
			break;

		case 5:
			if(tree1==NULL){
				cout<<"Create a new tree first"<<endl;
				break;
			}
		        tree1->treeInorderTraversal();
			break;

		/*case 6:
			if(tree1==NULL){
				cout<<"Create a new tree first"<<endl;
				break;
			}
            		cout<<"height of tree is "<<tree1->setHeight()<<endl;
			break;
		*/

		default:
			return(0);
	}

}while(true);

    return 0;
}
