//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int mod = 1003;
  
//   int solve(int i, int j, int isTrue,string& s, vector<vector<vector<int>>>&dp)
//     {
//       if( i > j)
//       return 0;
      
//       if( i == j)
//       {
//           if(isTrue == 1)
//           {
//               return s[i] == 'T';
//           }
//           else{
//               return s[i] == 'F';
//           }
//       }
//       if(dp[i][j][isTrue] != -1)
//       return dp[i][j][isTrue];
//       int ways = 0;
//       for(int ind = i+1; ind <= j-1; ind += 2){
         
//          int lT = solve(i,ind-1,1,s,dp);
//          int lF = solve(i, ind-1,0,s,dp);
//          int rT = solve(ind+1,j,1,s,dp);
//          int rF = solve(ind+1,j,0,s,dp);
        
//          if(s[ind] == '&'){
             
//              if(isTrue)
//              {
//                  ways = (ways%mod +  (lT*rT)%mod)%mod;
//              }
//              else{
//                  ways = (ways%mod +  (lT*rF)%mod + (lF*rT)%mod + (lF*rF)%mod)%mod;
//              }
//          }
//          else if(s[ind] == '|')
//         {
//             if(isTrue)
//             {
//                 ways =( ways%mod + (lT*rF)%mod + (lF*rT)%mod + (lT*rT)%mod)%mod;
//             }
//             else{
//                 ways = (ways%mod + (lF*rF)%mod)%mod;
//             }
          
//         }
//         else if(s[ind] == '^')
//         {
//             if(isTrue)
//             {
//                 ways = (ways%mod +  (lT*rF)%mod + (lF*rT)%mod)%mod;
//             }
//             else{
//                 ways = (ways%mod +  (lT*rT)%mod + (lF*rF)%mod)%mod;
//             }
//         }
          
//       }
//       return dp[i][j][isTrue] =  ways%mod;
//     }
    
    // tabulation 
    int countWays(int N, string s){
     //vector<vector<vector<int>>>dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
     vector<vector<vector<int>>>dp(N,vector<vector<int>>(N,vector<int>(2,0)));
     for(int i = 0;i<N;i++)
     {
        dp[i][i][1]  = s[i] == 'T';
        dp[i][i][0]  = s[i] == 'F';
     }
    
     for(int i = N-1;i >= 0;i--)
     {
         for(int j = i+1;j<N;j++)
         {
              for(int isTrue = 0;isTrue <= 1; isTrue++){
                  int ways = 0;
                  for(int ind = i+1; ind <=j-1;ind += 2) {
                      int lT = dp[i][ind-1][1];
                      int lF = dp[i][ind-1][0];
                      int rT = dp[ind+1][j][1];
                      int rF = dp[ind+1][j][0];
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
        dp[i][j][isTrue] =  ways%mod;
                  }
              }
         }
     return dp[0][N-1][1];
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