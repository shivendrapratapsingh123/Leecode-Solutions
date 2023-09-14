//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	int solve(int ind, int arr[], int n, int sum,vector<vector<int>>&dp){
	      if(ind >= n){
	          if(sum == 0)
	          return 1;
	          return 0;
	      }
	      
	      if(dp[ind][sum] != -1) return dp[ind][sum];
	    int skip = solve(ind+1,arr,n,sum,dp);
	    if(arr[ind] <= sum)
	     skip  = (skip%mod + (solve(ind+1,arr,n,sum - arr[ind],dp))%mod)%mod;
	     return dp[ind][sum] = (skip)%mod;
	}
	
	
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(0,arr,n,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends