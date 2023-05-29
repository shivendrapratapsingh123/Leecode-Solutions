//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
 
   int solve(int r, int c,int n,  vector<vector<int>>&arr,vector<vector<int>>&dp){
       if(r == n-1)
       return arr[r][c];
       if(dp[r][c] != INT_MIN)
       return dp[r][c];
       int left = INT_MIN;
       if(c-1 >= 0)
       left = arr[r][c] + solve(r+1,c-1,n,arr,dp);
       int bottom = arr[r][c] + solve(r+1,c,n,arr,dp);
       int right = INT_MIN;
       if(c+1 < n)
       right = arr[r][c] + solve(r+1,c+1,n,arr,dp);
       return dp[r][c] = max({left,bottom,right});
   }

    int maximumPath(int N, vector<vector<int>>arr)
    {   vector<vector<int>>dp(N,vector<int>(N,INT_MIN));
        int max_val = INT_MIN;
        for(int i =0;i<N;i++)
         max_val = max(max_val,solve(0,i,N,arr,dp));
         return max_val;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends