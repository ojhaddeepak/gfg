//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int maxPartitions(string &a) {
       int n=a.size(),cnt=0;
       unordered_map<char,int>mp,mp2;
        vector<vector<int>>v(n,vector<int>(26,0));
        for(int i=0;i<n;i++)mp[a[i]]++;
        
        for(int i=0;i<n;i++){
            mp2[a[i]]++;
            mp[a[i]]--;
            bool fl=0;
            for(auto it: mp2){
                if(mp[it.first]>0){
                    fl=1;
                    break;
                }
            }
            if(!fl)cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends