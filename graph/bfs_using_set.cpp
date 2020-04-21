#include<cstdio>
#include<cstdlib>
#include<unordered_set>
#include<list>

using namespace std;

struct Graph {

	int node;
	unordered_set<int>* adj;
};

Graph *init(int V)
{
	Graph *graph = new Graph;
	graph->node = V;
	graph->adj = new unordered_set<int>[V];
	return graph;
}

void addEdge(Graph *graph, int u, int v)
{
	graph->adj[u].insert(v);
	graph->adj[v].insert(u);
}


void bfs(Graph *graph, int s)
{

	bool *visited = new bool[graph->node];
	int j;

	for(j = 0; j < graph->node; j++)
		visited[j] = false;

	visited[s] = true;
	
	list<int> queue;
	queue.push_back(s);
	
	while(!queue.empty())
	{

		printf("%d->",queue.front());
		queue.pop_front();

		unordered_set<int>::iterator i;



		for(i = graph->adj[s].begin(); i != graph->adj[s].end(); i++)
		{
			if(!visited[*i])
			{
				queue.push_back(*i);
				visited[*i] = true;
			}
		}
	}	
	

}


int main() 
{ 
    // Create the graph given in the above figure 
    int V = 4; 
    struct Graph* graph = init(V); 
    /*addEdge(graph, 0, 1); 
    addEdge(graph, 0, 2); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 
  */
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 2); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 2, 0); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 3); 



    // Print the adjacency list representation of 
    // the above graph 
    bfs(graph, 2); 
  
    return 0; 
} 
