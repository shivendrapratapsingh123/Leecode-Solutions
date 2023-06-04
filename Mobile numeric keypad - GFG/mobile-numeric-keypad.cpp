//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	
	
	long long getPresses(int r, int c, int n,int count,vector<int>&dr,vector<int>&dc, vector<vector<int>>&keypaid,vector<vector<long long int>>&dp){
	  
	  if(count == n)
	  return 1;
	  if(dp[count][keypaid[r][c]] != -1)
	  return dp[count][keypaid[r][c]];
	   long long int ans = 0;
	   for(int i = 0;i<dr.size();i++){
	       int tr = r + dr[i];
	       int tc = c + dc[i];
	       if(tr >= 0 && tr < keypaid.size() && tc >=0 && tc < keypaid[0].size() && keypaid[tr][tc] != -1)
	       {
	           ans += getPresses(tr,tc,n,count+1,dr,dc,keypaid,dp);
	       }
	   }
	   return dp[count][keypaid[r][c]] =  ans;
	}
	
	//tabulation 
	long long getCount(int N)
	{
		vector<vector<int>>keypaid{
		    {1,2,3},
		    {4,5,6},
		    {7,8,9},
		    {-1,0,-1}
		};
		
		vector<int>dr{0,-1,0,1,0};
		vector<int>dc{0,0,1,0,-1};
		vector<vector<long long int>>dp(N+1,vector<long long int>(10,0));
		for(int i = 0;i<10;i++)
		dp[1][i] = 1;
		long long ans  = 0;
		int r,c,count = 0;
		for(int cnt = 2;cnt <= N; cnt++)
		{
		   	for(int r = 0;r<keypaid.size();r++)
	    	{
		    for(int c = 0;c<keypaid[0].size();c++){
		        if(keypaid[r][c] != -1){
		             for(int x = 0;x<dr.size();x++){
	                 int tr = r + dr[x];
	                 int tc = c + dc[x];
	               if(tr >= 0 && tr < keypaid.size() && tc >=0 && tc < keypaid[0].size() && keypaid[tr][tc] != -1)
	                {
	                   dp[cnt][keypaid[r][c]] += dp[cnt-1][keypaid[tr][tc]];
	                }
	          }
		        }
		      }
	     	}   
		}
	  for(int i = 0;i<10;i++)
	    ans += dp[N][i];
	    return ans;
	}


};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends