//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        int n = s.size();
        int count = 0;

        // Function to expand around the center and count palindromes
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2) count++; // Count only length >= 2
                left--;
                right++;
            }
        };

        // Try every index as a center
        for (int i = 0; i < n; i++) {
            expandAroundCenter(i, i);     // Odd-length palindromes
            expandAroundCenter(i, i + 1); // Even-length palindromes
        }

        return count;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends