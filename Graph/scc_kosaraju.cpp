
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> adj, int src, vector<bool>& vis){

    vis[src]=true;
    for(auto v: adj[src]){
        if(!vis[v]){
            dfs(adj,v,vis);
        }
    }

}

// First DFS traversal from any vertex
// Reverse edges 
// Second DFS traversal from same vertex
bool scc_kosaraju(vector<vector<int>> adj, int n){

    vector<bool> vis(n,false);
    dfs(adj,0,vis);

    for(auto x: vis){
        if(!x) return false;
    }

    vis.clear();
    vis = vector<bool> (n,false);

    vector<vector<int>> reverseadj(n);

    for(int i=0; i<n; i++){
        for(auto v: adj[i]){
            reverseadj[v].push_back(i);
        }
    }

    dfs(reverseadj,0,vis);

    for(auto x: vis){
        if(!x) return false;
    }

    return true;

}

int main()
{
    vector<vector<int>> adj(4);
    
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(0);
    
    // defining edge -> if not present then not SCC, else is SCC
    adj[1].push_back(3);

    bool is_scc = scc_kosaraju(adj,4);
    cout<<is_scc;

    return 0;
}

