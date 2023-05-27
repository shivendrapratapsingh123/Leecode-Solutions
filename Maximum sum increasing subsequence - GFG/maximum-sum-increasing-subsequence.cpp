//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int>dp(n);
	    for(int ind = 0;ind<n;ind++)
	    dp[ind] = arr[ind];
	    int maxi  = arr[0];
	    for(int ind = 1;ind<n;ind++)
	    {
	        for(int prev = 0;prev < ind ; prev++)
	        {
	            if(arr[prev] < arr[ind])
	            {
	                dp[ind] = max(dp[ind],arr[ind] + dp[prev]);
	                maxi = max(maxi,dp[ind]);
	            }
	        }
	    }
	    return maxi;
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

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends