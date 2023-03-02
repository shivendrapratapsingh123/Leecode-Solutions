//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        int k = costs[0].size();
        if(k == 1 && n>1)
        return -1;
        int mini = INT_MAX,smini = INT_MAX;
        vector<vector<int>>dp(n,vector<int>(k,0));
        
        for(int color = 0;color<k;color++){
                
                    dp[0][color] = costs[0][color];
                    if(dp[0][color] < mini)
                    {
                        smini = mini;
                        mini = dp[0][color];
                    }
                    else if(dp[0][color] < smini){
                      smini = dp[0][color];  
                    }
                }
        
        for(int wall  = 1;wall < n;wall++)
        {
            int cmini = INT_MAX;
            int csmini = INT_MAX;
            for(int color = 0;color<k;color++){
                  if(dp[wall-1][color] == mini)
                    dp[wall][color] += costs[wall][color] + smini;
                    else
                    dp[wall][color] += costs[wall][color] + mini;
                    if(dp[wall][color] < cmini)
                    {
                        csmini = cmini;
                        cmini = dp[wall][color];
                    }
                    else if(dp[wall][color] < csmini)
                    {
                        csmini = dp[wall][color];
                    }
                }
                mini = cmini;
                smini = csmini;
        }
       
        return mini;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends