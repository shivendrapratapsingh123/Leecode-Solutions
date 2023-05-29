//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    // int solve( int ind, int k,int arr[],vector<int>&dp)
    // {
    //     if(ind <=0)
    //     return 0;
    //     if(dp[ind] != -1) 
    //     return dp[ind];
    //     int notTake = solve(ind-1,k,arr,dp);
    //     int take   = 0;
    //     if(  arr[ind] - arr[ind-1] < k)
    //     take =  arr[ind] + arr[ind-1] + solve(ind-2,k,arr,dp);
    //     return dp[ind] = max(notTake, take);
    // }
    
    // tabulation 
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        sort(arr,arr+n);
        vector<int>dp(n,0);
        for(int i = 1;i<n;i++)
        {
            int notTake = dp[i-1];
            int take = 0;
            if(arr[i]-arr[i-1] < k)
            take = arr[i] + arr[i-1] + dp[i-2];
            dp[i] = max(notTake , take );
        }
         return dp[n-1];
        //return solve(n-1,k,arr,dp);
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends