#include <bits/stdc++.h>

using namespace std;

void dfs(int node,vector<bool>& visited, vector<vector<int>>& adj){
    if(visited[node]) return;
    cout << node << " ";
    visited[node]= true;

    for(int nei : adj[node])
        dfs(nei, visited, adj);
    return;
}

int first_white_neighbour(int n, int source, vector<int>& color, vector<vector<int>>& adj){
    for(int nei : adj[source])
        if(color[nei] == 0) return nei;
    return -1;
}
void iterative_dfs_visit(int n, int curr, int& curr_time, vector<int>& color,
    vector<int>& parent, vector<int>& discovery_time,vector<int>& finish_time,
    vector<vector<int>>& adj){
        stack<int> st;

        st.push(curr);
        curr_time +=1;
        discovery_time[curr] = curr_time;
        color[curr] = 1;  // grayed

        while(!st.empty()){
            curr = st.top();

            int nei = first_white_neighbour(n,curr,color,adj);
            if(nei == -1){
                st.pop();
                curr_time += 1;
                finish_time[curr]= curr_time;
                color[curr] = 2; // blacked the node
            }
            else{
                parent[nei] = curr;
                curr_time += 1;
                discovery_time[nei] = curr_time;
                color[nei] = 1; // grayed the neihbour // newly discovered
                st.push(nei);
            }
        }
    }

void iterative_dfs(int n, vector<vector<int>>& adj){
    vector<int> color(n,0);
    vector<int> parent(n,-1);
    vector<int> discovery_time(n,-1);
    vector<int> finish_time(n,-1);

    int curr_time = 0;

    for(int i=0;i<n;i++){
        if(color[i] == 0)
            iterative_dfs_visit(n,i,curr_time,color,parent,discovery_time,finish_time,adj);
    }

    cout << "start time of the nodes after dfs\n";
    for(int i : discovery_time) cout << i << " ";
    cout << "\nfinish time of the nodes after dfs\n";
    for(int i : finish_time) cout << i << " ";
    cout << endl;
    return;
}

void dfs_visit_CLRS(int n ,int curr,int& timestamp, vector<int>& color,
 vector<int>& parent, vector<int>& discovery_time, vector<int>& finish_time, vector<vector<int>>& adj){
    timestamp += 1;

    discovery_time[curr]= timestamp;
    color[curr]=1;      // colored to gray, "just discovered"

    for(int nei : adj[curr]){
        if( color[nei] == 0){
            parent[nei]=curr;       // mark the curr as the parent of adjacent node
            dfs_visit_CLRS(n,nei, timestamp, color,parent,discovery_time,finish_time, adj);
        }
    }
    color[curr] = 2;            // blacked the node, "completely discovered"
    timestamp +=1;
    finish_time[curr] = timestamp;
    return;
}

void dfs_CLRS(int n , vector<vector<int>>& adj){
    vector<int> color(n,0);
    vector<int> parent(n,-1);
    vector<int> discovery_time(n);
    vector<int> finish_time(n);
    int timestamp=0;

    for(int i=0; i<n; i++){
        if(color[i]==0)
            dfs_visit_CLRS(n,i,timestamp,color,parent,discovery_time,finish_time,adj);
    }
    
    cout << "start time of the nodes after dfs\n";
    for(int i : discovery_time) cout << i << " ";
    cout << "\nfinish time of the nodes after dfs\n";
    for(int i : finish_time) cout << i << " ";
    cout << endl;
}

int main(){
    int n = 5;
/*
    0 ----- 1
    | \       \
    |   \      2
    4 ----" 3-"

*/
    vector<vector<int>> edges{
        {0,1},{1,2},{2,3},
        {3,4},{3,0},{4,0}
    };
    vector<vector<int>> adj(n);
    for(auto& e :edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    int source_node =0;
    vector<bool> visited(n);

    // 1. 
    cout << "DFS of the graph is:\n";
    dfs(source_node, visited,adj);
    cout << endl;

    
    // 2.
    // cout << "DFS using iterative version - stack\n";
    // iterative_dfs(n, adj);


    // 3.
    // cout << "CLRS based DFS";
    // dfs_CLRS(n,adj);
    // cout << endl;
    return 0;
}