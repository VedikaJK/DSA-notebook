
/*
Floyd–Warshall algorithm is an algorithm for finding the shortest paths 
in a weighted graph with positive or negative edge weights (but with no negative cycles).
*/


#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> floydwarshall(vector<vector<int>> graph, int n){

    vector<vector<int>> dist = graph;

    for(int i=0; i<n; i++){
        // edge jk -> ji + ik
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if( dist[j][i]!=INT_MAX && dist[i][k]!=INT_MAX && dist[j][k]>dist[j][i]+dist[i][k] ){
                    dist[j][k] = dist[j][i]+dist[i][k];
                }
            }
        }
    }

    return dist;

}

int main()
{
    // cout<<"Welcome to Online IDE!! Happy Coding :)";

    vector<vector<int>> graph = { { 0, 5, 2, INT_MAX },
                        { 5, 0, 1, 1 },
                        { 2, 1, 0, 4 },
                        { INT_MAX, 1, 4, 0 } }; 
    
    vector<vector<int>> SP = floydwarshall(graph,4);

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<SP[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

