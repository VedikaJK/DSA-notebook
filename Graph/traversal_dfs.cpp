void dfs(vector<vector<int>>& adj, int src, vector<int>& visited, vector<int>& order){

   // simple recursion on unvisited nodes
  
    visited[src] = true;
    order.push_back(src);

    for(auto v: adj[src]){
        if(!visited[v]){
            dfs(adj,v,visited,order);
        }
    }

}

