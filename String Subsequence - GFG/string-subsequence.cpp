//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(string str, string pat){
       int n = str.size();
      int m = pat.size();
  vector<vector<int>>dp(m+1,vector<int>(n+1,0));
 //if string is empty then no matching
  for(int i = 0;i<=m;i++)
  {
    dp[i][0] = 0;
  }
  // if pattern empty then always matching 
  for(int i = 0;i<=n;i++)
  {
    dp[0][i] = 1;
  }
  //according to recurrance relation
  for(int i  = 1;i<=m;i++)
  {
    for(int j = 1;j<=n;j++)
    {
        if(pat[i-1] == str[j-1])
        {
          dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
        }
        else{
            dp[i][j]  = dp[i][j-1];
        }
    }
  }
   return dp[m][n];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}
// } Driver Code Ends