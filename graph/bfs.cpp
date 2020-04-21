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

		void bfs(int s)
		{
			int j;
			bool *visited = new bool[V];

			for(j = 0; j < V; j++)
				visited[j] = false;

			list<int> queue;

			visited[s] = true;
			queue.push_back(s);

			list<int>::iterator i;

			while(!queue.empty())
			{
				
				s = queue.front();
				printf("%d->",s);
				queue.pop_front();

				for(i = adj[s].begin(); i != adj[s].end(); i++)
				{
					if(!visited[*i])
					{
						visited[*i] = true;
						queue.push_back(*i);
					}
				}
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
	g.bfs(2);
	return 0;
}
