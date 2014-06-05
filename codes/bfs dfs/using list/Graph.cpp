#include "Graph.h"
using namespace std;


Graph::Graph(int num){
	v=num;
	adjlst=new list<int>[v];
}

bool Graph::addEdge(int v1,int v2){
		adjlst[v1].push_back(v2);
		adjlst[v2].push_back(v1);	
		adjlst[v1].sort();
		adjlst[v2].sort();
	}

bool Graph::deleteEdge(int v1,int v2){
	list<int>::iterator it1=find(adjlst[v1].begin(),adjlst[v1].end(),v2);
	list<int>::iterator it2=find(adjlst[v2].begin(),adjlst[v2].end(),v1);
	if( *it1==v2 && *it2==v1 ){
		adjlst[v1].remove(v2);
		adjlst[v2].remove(v1);
	} else cout<<"no such edge\n";
}


void Graph::printgraph(){
	cout<<"graph  is " <<endl;
	cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
	for(int i=0;i<v;i++){
		if(!adjlst[i].empty()){
			list<int>::iterator it;
			cout<<i<<" th list element are ->\t";
			for( it=adjlst[i].begin();it!=adjlst[i].end();it++){
				cout<<*it<<"\t";
			}
			cout<<endl;
		}
	}
	cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
}

bool Graph::BFS(int start){
	int i,j,temp,count=0,u=start;
	int visited[v];
	int finalbfs[v];
	vector<int>queue;
	list<int>::iterator it;
	for(i=0;i<v;i++) visited[i]=0;
	
	visited[u]=1;
	queue.push_back(u);
	
	while(!queue.empty()){
		finalbfs[count++]=queue.front();
		queue.erase(queue.begin());
		
		for(it=adjlst[u].begin();it!=adjlst[u].end();it++){
			if(visited[*it]!=1){
				queue.push_back(*it);
				visited[*it]=1;
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
	list<int>::iterator it;
	vector<int>::iterator mt;
	u=start;
	visited[u]=1;
	finaldfs[count++]=u;
		for(it=adjlst[u].begin();it!=adjlst[u].end();it++){
			if(visited[*it]!=1)  stack.push_back(*it);
		}
	
	while(!stack.empty()){
		//for(mt=stack.begin();mt!=stack.end();mt++)cout<<*mt<<"\t"; cout<<endl;
		u=stack.back();
		//cout<<"u is \t"<<u<<endl;
		stack.erase( ( stack.begin()+((stack.size())-1) ) );
		if(visited[u]!=1) {
			finaldfs[count++]=u;
			visited[u]=1;
		}
		if(!adjlst[u].empty()){
			for(it=adjlst[u].begin();it!=adjlst[u].end();it++){
					if(visited[*it]!=1) stack.push_back(*it);
				}
		}
	}
	for(i=0;i<count;i++) cout<<finaldfs[i]<<"\t"; cout<<endl;
	//for(i=0;i<v;i++) cout<<visited[i]<<"\t";
	cout<<endl;
}
