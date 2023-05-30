//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
	
// 	int solve(int n,int w, int cost[],vector<vector<int>>&dp)
// 	{
// 	    if(n == 0 && w)
// 	    return 1e8;
// 	    if(w == 0)
// 	    return 0;
// 	    if(dp[n][w] != -1)
// 	    return dp[n][w];
// 	    int notTake = solve(n-1,w,cost,dp);
// 	    int take = 1e8;
// 	    if(cost[n-1] != -1 && w - n >=0)
// 	    take = cost[n-1] + solve(n,w-n,cost,dp);
// 	    return dp[n][w] = min(take,notTake);
// 	}
     
	public:
	// tabulation 
	int minimumCost(int cost[], int N, int W) 
	{ 
	    //vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
	    vector<vector<int>>dp(N+1,vector<int>(W+1,0));
	    for(int wt = 0;wt<=W;wt++)
	    dp[0][wt] = 1e8;
	    for(int ind = 1;ind <= N ; ind++)
	    {
	        for(int wt = 1;wt <= W;wt++)
	        {
	            int notTake = dp[ind-1][wt];
	            int take = 1e8;
	            if(cost[ind-1] != -1 && wt -ind >=0)
	            take = cost[ind-1] + dp[ind][wt-ind];
	            dp[ind][wt] = min(take,notTake);
	        }
	    }
      int res =  dp[N][W];
      if(res >= 1e8)
      return -1;
      return res;
	} 
	
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends