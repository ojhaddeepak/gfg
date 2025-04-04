//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    typedef pair<int,int>pa;
    bool isCycle(int V, vector<vector<int>>& edges) {
        // At first lets convert the edges to the adjacency list 
        vector<list<int>>adj(V,list<int>());  //we need to resize it at the begining 
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            //as it is undirected graph so it is bi directional 
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        //now lets se a set to have the track of visited neighbors 
        unordered_set<int>visited;
        //now lets traverse on the base of adj
        for(int i=0;i<V;i++)
        {
            if(visited.find(i)!=visited.end())   continue;  //as already visited next vertex Turn 
            //lets use a q 
            queue<pa>q; //as this will store the node along with its parent means that if we find a neighbour of a node then that neighbour will bw store as a node but the node will be the parent at that case-> help us for detecting cycle 
            q.push({i,-1});  //as the parent of this unvisitd ith vertex previosuly not calculated 
            //now lets mark the ith node as visited 
            visited.insert(i);
            //now lets check the neighbours of this ith node using BFS 
            while(q.size()>0)
            {
                int node=q.front().first;
                int parent=q.front().second;
                q.pop();
                //lets visit the neighbors of this node 
                for(auto neighbor : adj[node])
                {
                    if(visited.find(neighbor)==visited.end())   //means previosuly this vertex was not visited 
                    {
                        //so now this neighbor will be pushed into the q where the current node will be the parent of that neighbor 
                        q.push({neighbor,node});
                        //now lets mark as visited 
                        visited.insert(neighbor);
                    }
                    else if(parent!=node) //means previously visited now we check if the parent during the 1st visit and now the current parent(node) if it not same then its says that cycle found --> as for 0->2 0->1 1->2 here a cycle exist for the same neighbor of 1 & 2 while parents are different 
                    {
                        return true;
                    }
                }
            }
        }
        return false;   //no cycle exists 
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends