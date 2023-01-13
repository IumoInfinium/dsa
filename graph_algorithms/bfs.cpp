#include <bits/stdc++.h>
using namespace std;

void recursive_bfs(int node, vector<bool>& visited, vector<vector<int>>& adj){
	if(visited[node]) return;
	cout << node << " ";
	visited[node] = true;
	for(int& nei : adj[node])
		recursive_bfs(nei, visited,adj);
	return ;
}

vector<int> iterative_bfs(int n, vector<vector<int>>& adj){
	vector<int> discovered;
	vector<bool> visited(n, false);
	queue<int> q;
	int curr;
	
	// bfs starting from 0th vertex
	q.push(0);

	while(!q.empty()){
		curr = q.front();
		q.pop();
		if(visited[curr]) continue;
		visited[curr]= true;
		discovered.push_back(curr);
		for(int nei : adj[curr]){
			q.push(nei);
		}
	}
	return discovered;
}

void bfs_CLRS(vector<vector<int>>& adj, int source,int n){
	// 0 -> white, not yet discovered
	// 1 -> gray, discovered
	// 2 -> black, found all neighbours
	vector<int> color(n,0);
	vector<int> d(n,INT_MAX);
	vector<int> pie(n,-1); // visited array

	color[source] = 1;
	d[source] = 0;
	pie[source]=-1;

	queue<int> q;
	q.push(source);
	while(!q.empty()){
		int curr = q.front();
		q.pop();

		for(int nei : adj[curr]){
			if(color[nei] == 0){
				color[nei] = 1;
				d[nei] +=1;
				pie[nei] = curr;
				q.push(nei);
			}
		}
		color[curr]=2; 	// visited all surroundings
	}
	cout << "colors of vertices(all should be 2, if it is visited)\n";
	for(int i : color) cout << i << " ";
	cout <<"\n";
	return;
}

int main(){
	int n=5;
	vector<vector<int>> edges{
		{0,1}, {1,2}, {2,3},
		{3,4}, {4,0}, {0,2}
	};
	// adjancency list down below
	vector<vector<int>> adj(n);

	for(auto& e : edges){
		adj[e[0]].push_back(e[1]);
		adj[e[1]].push_back(e[0]);
	}
	// array to maintain if the vertex is visited or not
	vector<bool> visited(n,false);

	// recursive_bfs(0,visited, adj);


	// vector<int> traversed = iterative_bfs(n,adj);
	// for(int i: traversed) cout << i << " ";
	// cout << endl;

	bfs_CLRS(adj,0,n);  
	return 0;
}
