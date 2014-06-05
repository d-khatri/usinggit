#include <iostream>
#include "Graph.h"
//How to compile code:  g++ main.cpp Graph.cpp
//How to run code: ./a.out < input1

using namespace std;

int main()
{

    int choice,v1,v2,source;
    Graph* g=NULL;

do{
	/*cout<<"1. Create new graph"<<endl;
	cout<<"2. Add a new edge to the graph"<<endl;
	cout<<"3. Delete an edge from the graph"<<endl;
	cout<<"4. BFS of graph"<<endl;
	cout<<"5. DFS of graph"<<endl;
	cout<<"6. Print the lists of the Graph"<<endl;
	cout<<"Any other choice to exit"<<endl;*/
	cout<<"Enter your choice:";
	cin>>choice;
	cout<<"You entered "<<choice<<endl;
	switch(choice){
		case 1:
			if(g!=NULL){
				delete g;
			}
			int vcount;
			cout<<"How many vertices in your graph? \t";
			cin>>vcount;
			g = new Graph(vcount);
			//create graph with zero edges
			//vertices are labeled as 0, 1, 2...vcount-1
			//it is a simple undirected unweighted graph
			//you can use adjacency list of matrix to represent the graph

			break;

		case 2:
			if(g==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}
			cout<<"Enter first endpoint of edge\t";
			cin>>v1;
			cout<<"Enter second endpoint of edge\t";
			cin>>v2;
			g->addEdge(v1,v2);
			break;

		case 3:
			if(g==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}
			cout<<"Enter first endpoint of edge";
			cin>>v1;
			cout<<"Enter second endpoint of edge";
			cin>>v2;
			g->deleteEdge(v1,v2);
			break;

		case 4:
			if(g==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}
		    cout<<"Enter source vertex for BFS\t";
		    cin>>source;
		    cout<<endl;
		    g->BFS(source);

		    break;

		case 5:
			if(g==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}
		    cout<<"Enter source vertex for DFS\t";
		    cin>>source;
		    cout<<endl;
		   	g->DFS(source);
		    //Read section 22.3 from Cormen book
		    //DFS can be performed with multiple sources as well. However we will stick to the convention that DFS starts from a source and covers only reachable vertices
			break;
		
		case 6:
			if(g==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			} else
			g->printgraph();
			break;
			
		default:
			return(0);
	}

}while(true);

   return 0;
}
