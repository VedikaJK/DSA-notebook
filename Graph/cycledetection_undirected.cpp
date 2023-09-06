bool dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& vis){
    vis[u] = true;
    bool ret = false;
    for(auto w: adj[u]){
        if(w!=parent){
            if(vis[w]) return true;
            ret = ret || dfs(w,u,adj,vis);
            if(ret) return ret;
        }
    }
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
        if(A<=2) return 0;
        vector<vector<int>> adj(A+1);
        int u,v;
        for(int i=0; i<B.size();i++){
            u = B[i][0];
            v = B[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(A+1,0);
        bool ret = false;
        
        for(int i=1; i<=A; i++){
            if(!vis[i]){
               ret = ret || dfs(i,-1,adj,vis);
               if(ret) return ret; 
            }
        }

        return ret;
}

