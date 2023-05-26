//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++



class Solution{
  public:
  
//   int solve(int ind, int line, vector<vector<int>>&a,vector<vector<int>>&T,vector<int>&e,vector<vector<int>>&dp){
       
//       if( ind == 0) 
//       {
//           return a[line][ind] + e[line];
//       }
//       if(dp[ind][line] != -1)
//       return dp[ind][line];
       
//       if(line == 0)
//       {
//           return dp[ind][line] =  a[0][ind] + min(solve(ind-1,0,a,T,e,dp),T[1][ind] + solve(ind-1,1,a,T,e,dp));
//       }
//       else{
//           return dp[ind][line] =  a[1][ind] + min(solve(ind-1,1,a,T,e,dp),T[0][ind] + solve(ind-1,0,a,T,e,dp));
//       }
//   }
  
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
      int n = a[0].size();
     // vector<vector<int>>dp(n,vector<int>(2,0));
      vector<int>prev(2,0),curr(2,0);
      //start from any line and take minimum of them
      prev[0] = a[0][0] + e[0];
      prev[1] = a[1][0] + e[1];
      for(int ind = 1;ind<n;ind++)
      {
          curr[0] = a[0][ind] + min(prev[0],T[1][ind]+prev[1]);
          curr[1] = a[1][ind] + min(prev[1],T[0][ind] + prev[0]);
          prev = curr;
      }
      return min(prev[0]+x[0],prev[1]+x[1]);
  }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(2,vector<int>(n)), T(2,vector<int>(n));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>T[i][j];
            }
        }   
        vector<int> e(2), x(2);
        for(int i=0;i<2;i++){
            cin>>e[i];
        }
        for(int i=0;i<2;i++){
            cin>>x[i];
        }
        
        Solution ob;
        int ans = ob.carAssembly(a,T,e,x);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends