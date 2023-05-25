//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
     int mod = 1e9+7;
     int solve(long long n,vector<long long >&dp)
     {
         if(n<=2)
         return n;
         if(dp[n] != -1)
         return dp[n];
         long long single = solve(n-1,dp);
         long long pair = (n-1)*solve(n-2,dp);
         return dp[n] = ((single%mod) + (pair%mod))%mod;
     }
    
    int countFriendsPairings(int n) 
    { 
        vector<long long>dp(n+1,-1);
        return solve(n,dp);
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends