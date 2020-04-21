#include<cstdlib>
#include<cstdio>
#include<list>
using namespace std;

class Graph{

	int V;

	list<int> *adj;

	public:

		Graph(int v)
		{
			V = v;
			adj = new list<int>[V];
		}

		void add_edge(int u, int v)
		{
			adj[u].push_back(v);
			
		}

		void dfs(int s)
		{
			int j;
			
			bool *visited = new bool[V];

			for(j = 0; j < V; j++)
				visited[j] = false;
			
			dfs_recur(s, visited);
		}
		
		void dfs_recur(int s, bool visited[])
		{
			visited[s] = true;

			printf("%d->",s);
			list<int>::iterator i;
			for(i = adj[s].begin(); i != adj[s].end(); i++)
			{
				if(!visited[*i])
					dfs_recur(*i, visited);
			}

		}

};



int main()
{
	Graph g(4);
	g.add_edge(0, 1);
	g.add_edge(0, 2);
	g.add_edge(1, 2);
	g.add_edge(2, 0);
	g.add_edge(2, 3);
	g.add_edge(3, 3);
	
	printf("BFS: \n");
	g.dfs(2);
	return 0;
}
