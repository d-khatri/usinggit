#include <iostream>
#include <vector>

using namespace std;

class Graph{
	public:		
		Graph(int);
		bool addEdge(int,int);
		bool deleteEdge(int,int);
		bool BFS(int);
		bool DFS(int);
		bool check(int*,int,int);
	private:
		int v;
		int  **mygraph;
	protected:	
};
