//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
       
       if(arr[0] < arr[1] && arr[0] < arr[n-1])
       return arr[0];
       if(arr[n-1] < arr[n-2] && arr[n-1] < arr[0])
       return arr[n-1];
       int l  = 0;
       int r = n-1;
       int mid;
       while(l <= r){
           mid = l + (r-l)/2;
           if(arr[mid] < arr[mid-1] && arr[mid] < arr[mid+1])
           return arr[mid];
           else if(arr[mid] < arr[r])
            r = mid - 1;
            else
            l = mid + 1;
       }
       return -1;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends