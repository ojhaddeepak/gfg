//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;

        int firstBuy = INT_MAX, firstSell = 0;
        int secondBuy = INT_MAX, secondSell = 0;

        for (int price : prices) {
            firstBuy = min(firstBuy, price);                
            firstSell = max(firstSell, price - firstBuy);     
            secondBuy = min(secondBuy, price - firstSell);    
            secondSell = max(secondSell, price - secondBuy); 
        }

        return secondSell; 
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends