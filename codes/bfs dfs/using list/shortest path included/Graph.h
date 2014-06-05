#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

class Graph{
	public:		
		Graph(int);
		bool addEdge(int,int);
		bool deleteEdge(int,int);
		bool BFS(int);
		bool DFS(int);
		void printgraph();
		int distance(int *,int);
	private:
		int v;
		list<int> *adjlst;
	protected:	
};
