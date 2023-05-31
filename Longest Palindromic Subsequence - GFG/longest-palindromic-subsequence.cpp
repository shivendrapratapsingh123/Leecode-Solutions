//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
  int solve(int n1, int n2, string& str1 , string& str2,vector<vector<int>>&dp)
  {
      if(n1 == 0 || n2 == 0)
      return 0;
       if(dp[n1][n2] != -1)
       return dp[n1][n2];
      if(str1[n1-1] == str2[n2-1])
        return dp[n1][n2] =  1 + solve(n1-1,n2-1,str1,str2,dp);
        else{
            return dp[n1][n2] =  max(solve (n1-1,n2,str1,str2,dp),solve(n1,n2-1,str1,str2,dp));
        }
      
  }
  
    int longestPalinSubseq(string str1) {
        string str2 = str1;
        int n = str1.size();
        reverse(str1.begin(),str1.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(n,n,str1,str2,dp);
        
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends