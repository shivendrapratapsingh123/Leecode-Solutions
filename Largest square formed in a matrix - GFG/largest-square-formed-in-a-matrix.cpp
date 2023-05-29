//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> arr){
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        int max_val = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(arr[i][j] == 1)
                {
                   dp[i][j] = 1;
                   max_val = 1;
                }
               
            }
        }
        for(int i = 1;i<n;i++)
        {
            for(int j = 1;j<m;j++)
            {
                if(arr[i][j] == 0)
                {
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] =  1 + min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                    max_val = max(max_val,dp[i][j]);
                }
            }
        }
        return max_val;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends