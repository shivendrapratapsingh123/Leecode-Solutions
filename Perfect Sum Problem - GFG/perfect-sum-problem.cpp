//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<int>prev(sum+1,0),curr(sum+1,0);
	    
        //return solve(0,arr,n,sum,dp);
        prev[0] = 1;
        for(int i = n-1;i >= 0; i--){
            for(int j = 0;j<=sum;j++){
                curr[j] = prev[j];
	       if(arr[i] <= j)
	           curr[j]  = (curr[j]%mod + prev[j-arr[i]]%mod)%mod;
	            curr[j] = (curr[j])%mod;
            }
            prev = curr;
        }
        return curr[sum];
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