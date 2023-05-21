//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   
   
//   long long  solve(int coins[], int n, int sum ,vector<vector<long long>>&memo)
//   {    
//       if(sum == 0)
//       return 1;
       
//       if(n == 0)
//       {
//          if(sum % coins[n] == 0)
//          return 1;
//          return 0;
//       }
//       if(memo[n][sum] != -1) return memo[n][sum];
//       long long notTake = solve(coins, n-1, sum,memo);
//         long long  take = 0;
//       if(coins[n] <= sum)
//       take =   solve(coins, n, sum - coins[n],memo);
//       return memo[n][sum] = take + notTake;
//   }
   //tabulation
  
    long long int count(int coins[], int n, int sum) {
       vector<vector<long long int>>dp(n,vector<long long>(sum+1,0));
        for(int ind = 0;ind<n;ind++){
          dp[ind][0] = 1;  
        }
         for(int s = 1;s<=sum;s++)
         {
             if(s % coins[0] == 0) 
             dp[0][s] = 1;
         }
         for(int ind = 1;ind<n;ind++)
         {
             for(int s = 1;s <= sum; s++)
             {
                 dp[ind][s] = dp[ind-1][s];
                 if(coins[ind] <= s)
                 dp[ind][s]  += dp[ind][s - coins[ind]];
             }
         }
       return dp [n-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends