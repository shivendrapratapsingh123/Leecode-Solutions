//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string s1, string s2, string s3) 
    {
         if(s1.size() + s2.size() != s3.size())
        return false;
         int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
     
        dp[n][m] = true;
        for(int i = m-1;i>=0;i--)
        {
            if(s2[i] == s3[i+n] && dp[n][i+1])
            dp[n][i] = true;
        }
        for(int i = n-1;i>=0;i--)
        {
            if(s1[i] == s3[i+m] && dp[i+1][m])
            dp[i][m] = true;
        }
        for(int i = n-1;i>=0;i--)
        {
            for(int j = m-1;j>=0;j--)
            {
                if(s1[i] == s3[i+j] && dp[i+1][j])
                dp[i][j] = true;
                if(s2[j] == s3[i+j] && dp[i][j+1])
                dp[i][j] = true;
            }
        }
        return dp[0][0];
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends