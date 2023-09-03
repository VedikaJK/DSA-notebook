vector<int> topoSort(vector<vector<int>> adj, int n){


    vector<int> indegree(n,0);
    vector<int> topoOrder;
    queue<int> q;

    for(int i=0; i<n; i++){
        for(auto v: adj[i]){
            indegree[v]++;
        }
    }

    int src = -1;

    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v: adj[u]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
        topoOrder.push_back(u);
    }

    return topoOrder;

}
