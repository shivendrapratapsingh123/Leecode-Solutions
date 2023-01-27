//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int mod = 1e9+7;
	
	int solve(int idx, string& str,int n,vector<int>&memo)
	{
	    if(str[idx] == '0')
	    return 0;
	  if(idx >= n)
	  {
	       return 1;
	  }
	  if(memo[idx] != -1)
	  return memo[idx];
	  int ans = 0;
	  if(idx+1<n && str[idx+1] == '0')
	    ans +=  solve(idx+2,str,n,memo);
	
	  else
	  {
	     ans+= solve(idx+1,str,n,memo);
	     if(idx+1<n && ((str[idx] =='1' && str[idx+1] <='9') || (str[idx] =='2' && str[idx+1] <='6')))
	         ans+= solve(idx+2,str,n,memo);
	     
	  }
	  memo[idx] = ans%mod;
	  return memo[idx];
	}
	
		int CountWays(string str){
		    
		     int n = str.size();
		    for(int i = 0; i<n;i++)
		    {
		       
		        if(i == 0 and str[i]=='0')
		        return 0;
		        if(i == n-1 && ((str[i-1]=='0'||str[i-1]>'2') && str[i]=='0'))
		        return 0;
		        if(str[i] =='0' && str[i-1]>'2')
		        return 0;
		        if(str[i]=='0' && str[i-1] == '0')
		        return 0;
		    }
		    vector<int>memo(n+1,-1);
		    solve(0,str,n,memo);
		    
		    return memo[0];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends