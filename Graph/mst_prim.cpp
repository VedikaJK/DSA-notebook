/*

- This algorithm always starts with a single node and moves through several adjacent nodes, in order to explore all of the connected edges along the way.

- The algorithm starts with an empty spanning tree. The idea is to maintain two sets of vertices. 
- The first set contains the vertices already included in the MST, 
- and the other set contains the vertices not yet included. 
- At every step, it considers all the edges that connect the two sets and picks the minimum weight edge from these edges. 
- After picking the edge, it moves the other endpoint of the edge to the set containing MST. 

- O(E * logV) with the help of a binary heap.

- Using Priority Queue : 
- The idea is, not to insert all vertices in priority queue, but only those which are not MST and 
have been visited through a vertex that has included in MST. 
- We keep track of vertices included in MST in a separate boolean array inMST[]

*/


void Graph::primMST()
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
 
    int src = 0; // Taking vertex 0 as source
 
    vector<int> key(V, INF); 
    vector<int> parent(V, -1); 
    vector<bool> inMST(V, false);
 
    pq.push(make_pair(0, src));
    key[src] = 0;
 
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
         
        if(inMST[u] == true){
            continue;
        }
       
        inMST[u] = true;  // Include vertex in MST
 
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
 
            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
 
    // Print edges of MST using parent array
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);

}
