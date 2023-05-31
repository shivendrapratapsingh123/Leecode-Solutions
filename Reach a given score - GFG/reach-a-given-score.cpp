//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function

 long long int solve(long long int n, vector<long long>&arr,int ind)
 {
     if(n == 0)
     return 1;
     if(n<0)
     return 0;
     if(n > 0 && ind < 0)
     return 0;
     return solve(n-arr[ind],arr,ind) + solve(n,arr,ind-1);
 }

long long int count(long long int n)
{
    vector<long long int>arr = {3,5,10};
    ve
   return solve(n,arr,2);
 
}

//{ Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends