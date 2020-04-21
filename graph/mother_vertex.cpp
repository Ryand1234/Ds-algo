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

		void addEdge(int u, int v)
		{
			adj[u].push_back(v);
			
		}

		int bfs(int s)
		{
			int j;
			bool *visited = new bool[V];

			for(j = 0; j < V; j++)
				visited[j] = false;

			list<int> queue;

			visited[s] = true;
			queue.push_back(s);
			int cont = 0;
			list<int>::iterator i;

			while(!queue.empty())
			{
				
				cont ++;
				s = queue.front();
	//			printf("%d->",s);
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
	//		printf("\nCOnt: %d\n",cont);
			return cont;
		}

};



int main()
{/*
	Graph g(4);
	g.add_edge(0, 1);
	g.add_edge(0, 2);
	g.add_edge(1, 2);
	g.add_edge(2, 0);
	g.add_edge(2, 3);
	g.add_edge(3, 3);*/
	int V = 7;
	Graph g(V); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0); 
//	printf("BFS: \n");
	for(int i = 0; i<V; i++)
	{
	    	if(g.bfs(i) == V)
	    {
		    printf("%d->",i);
	    }
	}
	return 0;
}
