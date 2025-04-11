//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User Function Template
class Solution {
        // steps 
        //  Correctly built the adjacency list.
       // Used a priority queue with {distance, node} to ensure min-distance is processed first.
       //Initialized dist[src] = 0 and the rest to 1e9 (infinity).
       //Relaxed edges only if a shorter path is found.
      //Pushed updated {distance, node} pairs back into the priority queue.
    
    
  public:  // implementing dijkstra's algorithm using priority queue
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // create adj list
        vector<vector<pair<int,int>>>adj(V);
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v=  edges[i][1];
            
            int wt=  edges[i][2];
            
            adj[u].push_back({v,wt});
             adj[v].push_back({u,wt}); // undirected graph
        }
        
        // create priority queue
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      
      // push the source with distance zero in pq
      pq.push({0,src});
      
      // make distance array intitalising src to 0 and rest to infinity
      vector<int>dist(V,1e9);
      dist[src]  = 0;
      
      
      
      while(!pq.empty()){
          int node = pq.top().second;
          int distance = pq.top().first;
           pq.pop();
          
          // all neighbors of node 
          for(auto ad: adj[node]){
              int nd = ad.first;
              int wt = ad.second;
              
              if(distance+wt<dist[nd]){
                  dist[nd] = distance  + wt;
                  pq.push({dist[nd],nd});
              }
          }
      }
      
        return dist;

        
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends