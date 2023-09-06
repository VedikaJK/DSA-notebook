#include<bits/stdc++.h>
using namespace std;

bool checkCycleUtil (int node, 
            bool *visited, bool *inStack){

    if (inStack[node])
        return true;
    if (visited[node])
        return false;
    
    visited[node] = true;
    inStack[node] = true;

    for (int v : adj[node]){
        // Recurse for 'v'.
        if (checkCycleUtil(v, visited, inStack))
            return true;
    }

    inStack[node] = false;
    return false;
}
// Function to check for the cycle.
bool checkCycle(int V, int E){
  
    bool visited[V]; 
    bool inStack[V]; 
    for(int i = 0; i < V; i++){
        visited[i] = false;
        inStack[i] = false;
    }
    
    for (int i = 0; i < V; i++){
        if (checkCycleUtil(i, visited, inStack)){
            return true;
        }
    }

    return false;

}

