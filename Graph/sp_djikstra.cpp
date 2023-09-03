
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ip;

vector<int> djikstra(vector<vector<pair<int,int>>> adj, int n, int src){

    vector<int> SP(n,INT_MAX);
    priority_queue<ip, vector<ip>, greater<ip>> pq;

    SP[src]=0;
    pq.push({src,0});

 // BFS with priority queue, relax edges
  
  while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(auto v: adj[u]){
            if(SP[v.first] > SP[u]+v.second){
                SP[v.first] = SP[u]+v.second;
                pq.push({SP[v.first], v.first});
            }
        }        
    }

    return SP;

}

int main()
{
    // cout<<"Welcome to Online IDE!! Happy Coding :)";
    vector<vector<pair<int,int>>> adj(4);
    
    adj[0].push_back({1,5});
    adj[1].push_back({0,5});

    adj[0].push_back({2,2});
    adj[2].push_back({0,2});

    adj[1].push_back({2,1});
    adj[2].push_back({1,1});

    adj[1].push_back({3,1});
    adj[3].push_back({1,1});
    
    adj[2].push_back({3,4});
    adj[3].push_back({2,4});
        
    vector<int> SP = djikstra(adj,4,0);
    
    for(int i=0; i<4; i++) 
        cout<<"0-->"<<i<<" = "<<SP[i]<<"\n";
    
    
    return 0;
}

