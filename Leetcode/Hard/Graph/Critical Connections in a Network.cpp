#define pb push_back 

class Solution {
public:

    int time = 0;

    void tarjanDFS(
        int i,
        int parent,
        vector<int>& low,
        vector<int>& disc,
        vector<vector<int>>& adj,
        vector<vector<int>>& critical){

        low[i] = time;
        disc[i] = time;
        time++;

        for(auto v: adj[i]){
            if(v==parent) continue;
            if(disc[v]==-1){
                tarjanDFS(v,i,low,disc,adj,critical);
                low[i] = min(low[i],low[v]);
                if(low[v]>disc[i]){
                    critical.push_back({i,v});
                }
            }
            else{
                low[i] = min(low[i], disc[v]);
            }
        }


    }


    void findCriticalConnections(vector<vector<int>> adj, int n,vector<vector<int>>& critical){
        vector<int> low(n,-1), disc(n,-1);
        for(int i=0; i<n; i++){
            if(disc[i]==-1){
                tarjanDFS(i,-1,low,disc,adj,critical);
            }
        }    
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(auto v: connections){
            adj[v[0]].pb(v[1]);
            adj[v[1]].pb(v[0]);
        }

        vector<vector<int>> critical;

        findCriticalConnections(adj,n,critical);

        return critical;
    }

};
