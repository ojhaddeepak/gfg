//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        int result = 0;
        
        // Iterate over every bit position (assuming 32-bit signed integers)
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            int bit = (1 << i);
            for (int num : arr) {
                if (num & bit) {
                    sum++;
                }
            }
            // If sum % 3 is not 0, that bit belongs to the unique number
            if (sum % 3 != 0) {
                result |= bit;
            }
        }
        
        return result;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends