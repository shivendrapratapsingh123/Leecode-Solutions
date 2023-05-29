//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int solve(int eggs, int floors,vector<vector<int>>&dp)
    {
      if(eggs == 1 || floors == 1 || floors == 0)
      return floors;
      if(dp[eggs][floors] != -1)
      return dp[eggs][floors];
      int min_move = INT_MAX;
      // droping eggs from every floors
      for(int k = 1;k<= floors;k++)
      {
          int temp = 1 + max(solve(eggs,floors - k,dp), solve(eggs-1,k-1,dp));
          min_move = min(min_move,temp);
      }
      return dp[eggs][floors] = min_move;
    }
    
    int eggDrop(int eggs, int floors) 
    {
        vector<vector<int>>dp(eggs+1,vector<int>(floors+1,-1));
        return solve(eggs,floors,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends