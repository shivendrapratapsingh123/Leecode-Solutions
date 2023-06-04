//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int mod = 1003;
  
  int solve(int i, int j, int isTrue,string& s, vector<vector<vector<int>>>&dp)
    {
      if( i > j)
      return 0;
      
      if( i == j)
      {
          if(isTrue == 1)
          {
              return s[i] == 'T';
          }
          else{
              return s[i] == 'F';
          }
      }
      if(dp[i][j][isTrue] != -1)
      return dp[i][j][isTrue];
      int ways = 0;
      for(int ind = i+1; ind <= j-1; ind += 2){
         
         int lT = solve(i,ind-1,1,s,dp);
         int lF = solve(i, ind-1,0,s,dp);
         int rT = solve(ind+1,j,1,s,dp);
         int rF = solve(ind+1,j,0,s,dp);
        
         if(s[ind] == '&'){
             
             if(isTrue)
             {
                 ways = (ways%mod +  (lT*rT)%mod)%mod;
             }
             else{
                 ways = (ways%mod +  (lT*rF)%mod + (lF*rT)%mod + (lF*rF)%mod)%mod;
             }
         }
         else if(s[ind] == '|')
        {
            if(isTrue)
            {
                ways =( ways%mod + (lT*rF)%mod + (lF*rT)%mod + (lT*rT)%mod)%mod;
            }
            else{
                ways = (ways%mod + (lF*rF)%mod)%mod;
            }
          
        }
        else if(s[ind] == '^')
        {
            if(isTrue)
            {
                ways = (ways%mod +  (lT*rF)%mod + (lF*rT)%mod)%mod;
            }
            else{
                ways = (ways%mod +  (lT*rT)%mod + (lF*rF)%mod)%mod;
            }
        }
          
      }
      return dp[i][j][isTrue] =  ways%mod;
    }
    
    
    int countWays(int N, string S){
     vector<vector<vector<int>>>dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
     return solve(0,N-1,1,S,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends