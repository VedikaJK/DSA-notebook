vector<int> bfs(vector<vector<int>> adj, int n){
    
    // Main data structure in bfs is queue
  
    vector<int> bfsOrder;
    vector<int> visited(n,false);
    queue<int> q;

    // start with any node as source
    // source can be made particular when a problem pertains to specific node
  
    int src = 0;
    visited[src] = true;
    q.push(src);

    // this for loop takes care of disconnected components
  
    for(int i=0; i<n; i++){
        if(!visited[i]){

            // actual bfs 
          
            while(!q.empty()){
                int u = q.front();
                q.pop();

                for(auto v: adj[u]){
                    if(!visited[v]){
                        visited[v]=true;
                        q.push(v);
                    }
                }

                bfsOrder.push_back(u);
            }


        }
    }

    return bfsOrder;

}
