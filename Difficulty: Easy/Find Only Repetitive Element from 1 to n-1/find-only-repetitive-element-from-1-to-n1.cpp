//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0];
        int fast = arr[0];

        // First phase: finding the intersection point
        do {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while (slow != fast);

        // Second phase: finding the entrance to the cycle
        slow = arr[0];
        while (slow != fast) {
            slow = arr[slow];
            fast = arr[fast];
        }

        return slow;
    }
};



//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.findDuplicate(arr);

        cout << (result) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends