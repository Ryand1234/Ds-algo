#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

void dfs(int i, int j, bool visit[3][3],  int adj[3][3], int n, int m)
{
	visit[i][j] = true;

	//left side
	if( adj[i-1][j] <= adj[i][j] && i - 1 >= 0 && !visit[i-1][j] )
		dfs(i-1, j, visit, adj, n, m);

	//right side
	if( adj[i+1][j] <= adj[i][j] && i + 1 < n && !visit[i+1][j] )
		dfs(i+1, j, visit, adj, n, m);

	//up side 
	if( adj[i][j-1] <= adj[i][j] && j -1 >= 0 && !visit[i][j-1] )
		dfs(i, j-1, visit, adj, n, m);

	//down side  
	if( adj[i][j+1] <= adj[i][j] && j + 1 < m && !visit[i][j+1] )
		dfs(i, j+1, visit, adj, n, m);
}



void printMinVertices(int adj[3][3], int n, int m)
{

	int i,j;
	bool visit[3][3];
	memset(visit, false, sizeof(visit));

	vector<pair<int, pair<int, int> > > V;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			V.push_back(make_pair(adj[i][j], make_pair(i, j)));
		}
	}

	sort(V.begin(), V.end());

	//for(auto x:V)
	//	printf("%d->",x.first);
	//printf("\n");
	for(i = V.size()-1; i >= 0; i--)
	{
		if(!visit[V[i].second.first][V[i].second.second])
		{
			printf("%d %d\n", V[i].second.first, V[i].second.second);
			dfs(V[i].second.first, V[i].second.second, visit, adj, n, m);
		}
	}
}



int main()
{
	int n = 3, m = 3;
	int adj[3][3] = {{1, 2, 3},
			{2, 3, 1},
			{1, 1, 1}};

	printMinVertices(adj, n, m);
	return 0;
}
