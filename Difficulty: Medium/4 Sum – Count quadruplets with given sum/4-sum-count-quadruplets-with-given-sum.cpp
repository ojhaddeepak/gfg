//{ Driver Code Starts

#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;


// } Driver Code Ends

class Solution {
public:
    int countSum(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, vector<pair<int, int>>> pairSum;
        int count = 0;

        // Store the sums of all pairs along with their indices
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int currSum = arr[i] + arr[j];
                int complement = target - currSum;

                // Check if complement exists
                if (pairSum.find(complement) != pairSum.end()) {
                    for (auto &p : pairSum[complement]) {
                        int a = p.first;
                        int b = p.second;

                        // Ensure all indices are different
                        if (a != i && a != j && b != i && b != j)
                            count++;
                    }
                }
            }

            // Add current pairs to map after checking to avoid reuse
            for (int k = 0; k < i; ++k) {
                pairSum[arr[i] + arr[k]].push_back({k, i});
            }
        }

        return count;
    }
};


//{ Driver Code Starts.
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t-- > 0) {
        string input;
        getline(std::cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline character after reading k

        Solution solution;
        int ans = solution.countSum(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends