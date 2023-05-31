//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  long long mod = 1e9+7;
  
  long long solve(long long int  n,vector<long long>&dp)
  {
      if(n == 0 || n == 1)
      return 1;
      if( n == 2)
      return 3;
      if(dp[n] != -1)
      return dp[n];
      long long countOne = solve(n-1,dp);
      long  long countTwo = solve(n-2,dp);
      long long total = ((2LL*(countOne%mod)*(countTwo%mod))%mod + ((countOne%mod)*(countOne%mod))%mod)%mod;
      return dp[n] = total;
  }
  
    long long int countBT(int h) { 
        vector<long long>dp(h+1,-1);
        return solve(h,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

// } Driver Code Ends