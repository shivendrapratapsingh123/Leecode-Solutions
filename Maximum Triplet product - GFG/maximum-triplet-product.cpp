//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	long long int mini1,mini2,maxi1,maxi2,maxi3;
    	mini1 = mini2 =  INT_MAX;
    	maxi1 = maxi2 = maxi3 = INT_MIN;
    	
    	for(int i = 0;i<n;i++)
    	{
    	    if(arr[i] < mini1)
    	    {
    	        mini2 = mini1;
    	        mini1  = arr[i];
    	    }
    	    else if(arr[i] < mini2)
    	    {
    	        mini2 = arr[i];
    	    }
    	 
    	    
    	}
    	for(int  i = 0;i<n;i++)
    	{
    	      if(arr[i] > maxi1)
    	    {
    	        maxi3 = maxi2;
    	        maxi2 = maxi1;
    	        maxi1 = arr[i];
    	    }
    	    else if(arr[i] > maxi2)
    	    {
    	        maxi3 = maxi2;
    	        maxi2 = arr[i];
    	    }
    	    else if(arr[i] > maxi3)
    	    {
    	        maxi3 = arr[i];
    	    }
    	}
    	long long ans1 = mini1*mini2*maxi1;
    	long long ans2 = maxi1*maxi2*maxi3;
    	return max(ans1 , ans2);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends