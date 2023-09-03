
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;

/* ------------------------------
   VERSION 1: RETURNS BOOLEAN IF GRAPH IS SCC OR NOT 
*/

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

/* ------------------------------
   VERSION 2: RETURNS ALL SCCs in GRAPH 

    Ulta DFS from nodes in order of stack
*/


#include<bits/stdc++.h>
using namespace std;
#define V 8
#define pb push_back

unordered_map<int,vector<int>> adj,rev;

void DFS1(int i,vector<bool>& visited,stack<int>& mystack)
{
	visited[i]=true;
	for(int j: adj[i])
		if(visited[j]==false)
			DFS1(j,visited,mystack);

	mystack.push(i);
}

void reverse()
{
	for(int i=0;i<V;++i)
	{
		for(int j: adj[i])
			rev[j].pb(i);
	}
}

void DFS2(int i,vector<bool>& visited)
{
	cout<<i<<" ";
	visited[i] = true;
	for(int j: rev[i])
		if(!visited[j])
			DFS2(j,visited);
}

void findSCCs()
{
	stack<int> mystack;

	vector<bool> visited(V,false);
	for(int i=0;i<V;++i)
		if(!visited[i])
			DFS1(i,visited,mystack);

	reverse();

	for(int i=0;i<V;++i)
		visited[i] = false;

	cout<<"Strongly Connected Components are:\n";
	while(!mystack.empty())
	{
		int curr = mystack.top();
		mystack.pop();
		if(visited[curr]==false)
		{
			DFS2(curr,visited);
			cout<<"\n";
		}
	}
}

int main()
{
	adj[0].pb(1);
	adj[1].pb(2);
	adj[2].pb(0);
	adj[2].pb(3);
	adj[3].pb(4);
	adj[4].pb(5);
	adj[4].pb(7);
	adj[5].pb(6);
	adj[6].pb(4);
	adj[6].pb(7);

	findSCCs();
	return 0;
}

//TIME COMPLEXITY: O(V+E)
