//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   
   
   long long  solve(int coins[], int n, int sum ,vector<vector<long long>>&memo)
   {    
       if(sum == 0)
       return 1;
       
       if(n == 0)
       {
         if(sum % coins[n] == 0)
         return 1;
         return 0;
       }
       if(memo[n][sum] != -1) return memo[n][sum];
       long long notTake = solve(coins, n-1, sum,memo);
        long long  take = 0;
       if(coins[n] <= sum)
       take =   solve(coins, n, sum - coins[n],memo);
       return memo[n][sum] = take + notTake;
   }
  
    long long int count(int coins[], int N, int sum) {
       vector<vector<long long int>>memo(N,vector<long long>(sum+1,-1));
       return solve(coins, N-1,sum,memo);
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