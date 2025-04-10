//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
   int minCost(vector<vector<int>>& houses) {
    int n = houses.size();
    vector<bool> inMST(n, false);        // Track nodes included in MST
    vector<int> minDist(n, INT_MAX);     // Minimum distance to the MST
    minDist[0] = 0;                      // Start from the first node
    int result = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        // Find the node with the minimum distance to the MST
        for (int j = 0; j < n; ++j) {
            if (!inMST[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        // Include that node into MST
        inMST[u] = true;
        result += minDist[u];

        // Update the distance of the rest of the nodes
        for (int v = 0; v < n; ++v) {
            if (!inMST[v]) {
                int cost = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                if (cost < minDist[v]) {
                    minDist[v] = cost;
                }
            }
        }
    }

    return result;
}
};;


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends