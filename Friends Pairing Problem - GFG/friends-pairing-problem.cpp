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
    // taulation 
    int countFriendsPairings(int n) 
    { 
        vector<long long>dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i<=n;i++)
        {
            dp[i] = ((dp[i-1]%mod)+ ((i-1)*dp[i-2]%mod))%mod;
        }
        return (int)dp[n];
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