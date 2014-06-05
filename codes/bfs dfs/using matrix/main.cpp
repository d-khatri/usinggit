#include <iostream>
#include "Graph.h"
//How to compile code:  g++ main.cpp Graph.cpp
//How to run code: ./a.out < input1

using namespace std;

int main()
{

    int choice,source,v1,v2;
    Graph* g=NULL;

do{
	/*cout<<"1. Create new graph"<<endl;
	cout<<"2. Add a new edge to the graph"<<endl;
	cout<<"3. Delete an edge from the graph"<<endl;
	cout<<"4. BFS of graph"<<endl;
	cout<<"5. DFS of graph"<<endl;

	cout<<"Any other choice to exit"<<endl;*/
	cout<<"Enter your choice:\n";
	cin>>choice;
	cout<<"You entered "<<choice<<endl;
	switch(choice){
		case 1:
			if(g!=NULL){
				delete g;
			}
			int vcount;
			cout<<"How many vertices in your graph? ";
			cin>>vcount;
			cout<<vcount<<"vertices in graph\n";
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
			cout<<"Enter first endpoint of edge";
			cin>>v1;
			cout<<" v1 is "<<v1<<"\t";
			cout<<"Enter second endpoint of edge";
			cin>>v2;
			cout<<" v2 is "<<v2<<endl;
			g->addEdge(v1,v2);
			break;

		case 3:
			if(g==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}
			cout<<"Enter first endpoint of edge";
			cin>>v1;
			cout<<" v1 is "<<v1<<"\t";
			cout<<"Enter second endpoint of edge";
			cin>>v2;
			cout<<" v2 is "<<v2<<endl;
			g->deleteEdge(v1,v2);
			break;

		case 4:
			if(g==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}
		    cout<<"Enter source vertex for BFS";
		    cin>>source;
		    cout<<"and you source vertex is "<<source<<endl;
		    g->BFS(source);

		    break;

		case 5:
			if(g==NULL){
				cout<<"Create a new graph first"<<endl;
				break;
			}
		    cout<<"Enter source vertex for DFS";
		    cin>>source;
		    cout<<"and you source vertex is "<<source<<endl;
		    g->DFS(source);
		    //Read section 22.3 from Cormen book
		    //DFS can be performed with multiple sources as well. However we will stick to the convention that DFS starts from a source and covers only reachable vertices
			break;


		default:
			return(0);
	}

}while(true);




    return 0;
}
