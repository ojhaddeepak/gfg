//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int robLinear(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        
        int prev2 = 0, prev1 = 0;
        for (int num : arr) {
            int curr = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int maxValue(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0]; // Only one house to rob
        
        vector<int> case1(arr.begin(), arr.end() - 1);  // Exclude last house
        vector<int> case2(arr.begin() + 1, arr.end());  // Exclude first house

        return max(robLinear(case1), robLinear(case2));
    }
};




//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends