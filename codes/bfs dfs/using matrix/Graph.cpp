#include "Graph.h"
using namespace std;


Graph::Graph(int num){
	int i,j;
	v=num;
	mygraph=new int *[v];
	
	for(i=0;i<v;i++)
	mygraph[i]=new int[v];
	
	for(i=0;i<v;i++){
		for(j=0;j<v;j++)
			mygraph[i][j]=0;
	}
}

bool Graph::addEdge(int v1,int v2){
	mygraph[v1][v2]=1;
	mygraph[v2][v1]=1;
}

bool Graph::deleteEdge(int v1,int v2){
	mygraph[v1][v2]=0;
	mygraph[v2][v1]=0;
}

bool Graph::check(int *a,int num,int siz){
	for(int i=0;i<siz;i++){
		if(a[i]==num)
		return true;
	}
return false;	
}

bool Graph::BFS(int start){
	int i,j,temp,count=0,u=start;
	int visited[v];
	int finalbfs[v];
	bool result;
	vector<int>queue;
	
	for(i=0;i<v;i++) visited[i]=0;
	
	cout<<"adjancey matrix is " <<endl;
	cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++)
			cout<<mygraph[i][j]<<"\t";
		cout<<endl;
	}
	cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
	
	visited[u]=1;
	queue.push_back(u);
	
	while(!queue.empty()){
		finalbfs[count++]=queue.front();
		queue.erase(queue.begin());
		for(i=0;i<v;i++){
			if(mygraph[u][i]==1 && visited[i]!=1){
				queue.push_back(i);
				visited[i]=1;
			}
		}
		u=queue.front();
	}
	
	for(i=0;i<count;i++)cout<<finalbfs[i]<<"\t";
	
	cout<<endl;

return true;
}

bool Graph::DFS(int start){
	int i,u,count=0,visited[v];
	int finaldfs[v];
	for(i=0;i<v;i++) visited[v]=0;
	vector<int>stack;

	cout<<"adjancey matrix is " <<endl;
	cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
	for(i=0;i<v;i++){
		for(int j=0;j<v;j++)
			cout<<mygraph[i][j]<<"\t";
		cout<<endl;
	}
	cout<<"---------------------------------------------------------------------------------------------------------"<<endl;

	u=start;
	visited[u]=1;
	finaldfs[count++]=u;
	for(i=0;i<v;i++){
		if(mygraph[u][i]==1 && visited[i]!=1)  stack.push_back(i);
	}
	
	while(!stack.empty()){
		u=stack.back();
		stack.erase( ( stack.begin()+((stack.size())-1) ) );
		if(visited[u]!=1) finaldfs[count++]=u;
		visited[u]=1;
		for(i=0;i<v;i++){
			if(mygraph[u][i]==1 && visited[i]!=1) stack.push_back(i);
		}
	}
	for(i=0;i<count;i++) cout<<finaldfs[i]<<"\t"; cout<<endl;
}
