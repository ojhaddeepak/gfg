//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to calculate power without using pow()
    long long power(long long base, int exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {  // If exponent is odd
                result *= base;
            }
            base *= base;
            exp /= 2;
        }
        return result;
    }

    int nthRoot(int n, int m) {
        int low = 1, high = m;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long midPower = power(mid, n);

            if (midPower == m) return mid;
            else if (midPower < m) low = mid + 1;
            else high = mid - 1;
        }

        return -1; // No integer root found
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends