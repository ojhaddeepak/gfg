//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int countWays(string &digits) {
        int n = digits.size();
        if (n == 0 || digits[0] == '0') return 0;
        
        int prev2 = 1, prev1 = 1; // dp[i-2] and dp[i-1]
        
        for (int i = 1; i < n; i++) {
            int curr = 0;

            // Single digit decoding
            if (digits[i] != '0')
                curr += prev1;

            // Two-digit decoding (10-26)
            int twoDigit = stoi(digits.substr(i - 1, 2));
            if (twoDigit >= 10 && twoDigit <= 26)
                curr += prev2;

            // Update states
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends