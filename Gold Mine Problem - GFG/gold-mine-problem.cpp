//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>>arr)
    {
        int max_ans = 0;
       vector<vector<int>>dp(n,vector<int>(m,0));
       for(int i = 0;i<n;i++)
       {
           dp[i][m-1] = arr[i][m-1];
           max_ans = max(max_ans,dp[i][m-1]);
       }
       
       for(int j = m-2 ;j >= 0; j--)
       {
           for(int i = 0;i<n;i++)
           {
               if(i-1>=0)
               dp[i][j]  = max(dp[i][j],arr[i][j] + dp[i-1][j+1]);
               dp[i][j] = max(dp[i][j],arr[i][j] + dp[i][j+1]);
               if(i+1 < n)
               dp[i][j] = max(dp[i][j],arr[i][j] + dp[i+1][j+1]);
               max_ans = max(max_ans,dp[i][j]);
           }
       }
       return max_ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends