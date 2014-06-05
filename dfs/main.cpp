#include <iostream>
#include <cstdio>
#include <vector>
#include <list>

using namespace std;

class Graph{
    int V;
    int *flags,*starttime,*finishtime,*parent;                            //flag ==0 color=> WHITE
                                                                         //flags==1  color=>grey
                                                                         //flags==2 color=>black
    public:
    list<int> *adj;
    Graph(int v);
    void addedge(int u,int v);
    void setflag(int v,int flag);
    void setparent(int v,int parent);
    void setstarttime(int v,int time);
    void setfinishtime(int v,int ftime);
    int returnflag(int v);
    int returnvertices();
};

Graph::Graph(int vertex){
    this->V=vertex;
    adj = new list<int>[V];
    flags=new int[vertex];
    starttime=new int[vertex];
    finishtime=new int[vertex];
    parent =new int[vertex];
}

void Graph::addedge(int u,int v){
    adj[u].push_back(v);
}

void Graph::setflag(int v,int flag){
    flags[v]=flag;
}

void Graph::setparent(int v,int parentofv){
    parent[v]=parentofv;
}

void Graph::setstarttime(int v,int stime){
    starttime[v]=stime;
}

void Graph::setfinishtime(int v,int ftime){
    finishtime[v]=ftime;
}

int Graph::returnflag(int v){
    return flags[v];
}

int Graph::returnvertices(){
    return V;
}

class DFS{
    int time;
public:
    DFS(Graph G);
    void DFSVISIT(Graph G,int start_vertex);
    void dfs(Graph G);
};

DFS::DFS(Graph G){
    time=0;
}

void DFS::dfs(Graph G){
    int i;
    int no_vertex=G.returnvertices();

    for(i=0;i<no_vertex;i++){
        G.setparent(i,-1);
        G.setflag(i,0);
    }

    for(i=0;i<no_vertex;i++){
        if(0==G.returnflag(i))
            DFSVISIT(G,i);
    }
}

void DFS::DFSVISIT(Graph G,int v){
    time++;
    G.setstarttime(v,time);
    G.setflag(v,2);
    int i;
    for(i=(G.adj[v][0]));i<(G.adj[v]).size;i++){
        if(0==G.returnflag(i)){
            G.setparent(i,v);
            DFSVISIT(G,i);
        }
    }

    G.setflag(v,2);
    time++;
    G.setfinishtime(v,time);
}


int main(){






}
