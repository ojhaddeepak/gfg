//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            if(!((edges[i][0]==c && edges[i][1]==d) || (edges[i][0]==d && edges[i][1]==c))){
                adj[edges[i][0]].push_back(edges[i][1]);
                adj[edges[i][1]].push_back(edges[i][0]);
            }
        }
        
        int comp1=0,comp2=0;
        vector<bool>vis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                comp1++;
                dfs(adj,i,vis);
            }
        }
        
        adj[c].push_back(d);
        adj[d].push_back(c);
        std::fill(vis.begin(), vis.end(), false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                comp2++;
                dfs(adj,i,vis);
            }
        }
        if(comp1!=comp2)return true;
        return false;
    }
    
    void dfs(vector<vector<int>>&adj,int i,vector<bool>&vis){
        vis[i]=true;
        for(auto node:adj[i]){
            if(!vis[node]){
                dfs(adj,node,vis);
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends