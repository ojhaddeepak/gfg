//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int left = 0, curr_sum = 0;

        for (int right = 0; right < arr.size(); right++) {
            curr_sum += arr[right];

            while (curr_sum > target && left <= right) {
                curr_sum -= arr[left];
                left++;
            }

            if (curr_sum == target) {
                return {left + 1, right + 1}; // Convert to 1-based index
            }
        }
        
        return {-1}; // If no subarray found
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends