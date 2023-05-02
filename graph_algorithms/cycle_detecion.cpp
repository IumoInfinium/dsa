#include <bits/stdc++.h>

using namespace std;

// Algorithms for Cycle Detection in directed graph

class Graph{
public:

    // the idea is to keep track of the parent from which it occurered and current span of dfs at node
    // if parent and current span's node are same and marked, then there exists a cycle
    // it can be solved with two approaches - dfs/bfs
    
    // DFS Approach
    bool isCyclic(int n, vector<vector<int>>& adj){
        vector<bool> vis(n, false);
        vector<bool> dfsVis(n, false);

        for(int i=0; i<n; i++){
            if(!vis[i] && checkCycle(i, adj, vis, dfsVis)) return true;
        }
        return false;
    }

    bool checkCycle(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& dfsVis){
        vis[node] = true;
        dfsVis[node] = true;

        for(int x :  adj[node]){
            if(!vis[x] && checkCycle(x, adj, vis, dfsVis)) return true;
        }
        dfsVis[node] = false;
        return false;
    }

    // BFS Approach - based on the indegree of the nodes
    // if there is no vertex with indegree with 0, there is for sure a cycle
    // Otherwise we set its indegree to be -1 to prevent from visiting it again and
    // reduce the indegrees of its neighbors by 1
    // This process will be repeated for n (number of nodes) times.
    bool isCyclicBFS(int n, vector<vector<int>>& adj){
        vector<int> degrees(n,0);

        for(auto it : adj)
            for(int x : it)
                degrees[x]++;
        
        for(int i=0; i<n; i++){
            int processed_nodes = 0;
            
            // making processed_node reach till the node with 0 indegree, else till end
            for(; processed_nodes < n; processed_nodes++){
                if(!degrees[processed_nodes]) break;
            }
            if(processed_nodes == n) return false;

            degrees[processed_nodes]--;
            for(int nei : adj[processed_nodes]){
                degrees[nei]--;
            }
        }
        return true;
    }
};


int main(){

    Graph g;
    int n = 5;
    vector<vector<int>> edgeList = {{0,1},{1,3},{1,2},{3,4},{2,4},{4,1}};
    vector<vector<int>> adj(5);

    for(auto &it : edgeList){
        adj[it[0]].push_back(it[1]);
    }
    cout << ((g.isCyclicBFS(5, adj))?"no cycle":"yes cycle") << endl;
    return 0;
}