//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
                                      
        int n = image.size();
        int m = image[0].size();
        
        if(image[sr][sc]==newColor)
           return image;
        
        int orignal = image[sr][sc];
        vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        image[sr][sc] = newColor;
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(auto &dir:directions) {
                int nx = x+dir[0];
                int ny = y+dir[1];
                
                if(nx>=0 && nx<n && ny>=0 && ny<m && image[nx][ny]==orignal) {
                    image[nx][ny] = newColor;
                    q.push({nx,ny});
                }
            }
            
        }
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends