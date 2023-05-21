//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
     int solve(int W, int wt[], int val[], int n,vector<vector<int>>&memo){
         if(n == 0)
         {
             if(wt[n] <= W)
              return val[0];
              return 0;
         }
         if(memo[n][W] != -1)
          return memo[n][W];
         int nottake = solve(W,wt,val,n-1,memo);
         int take = INT_MIN;
         if(wt[n] <= W)
         take = val[n] + solve(W-wt[n],wt,val,n-1,memo);
         return memo[n][W]  = max(take,nottake);
     }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>memo(n,vector<int>(W+1,-1));
       return solve(W,wt,val,n-1,memo);
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends