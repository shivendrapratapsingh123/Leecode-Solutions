//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //minimum element is first or last element then to avoid overflow applying following rule 
        int low = 0;
        int high = n-1;
        int mid,prev,next;
        while( low <= high){
            mid  = low + (high - low)/2;
            prev = (mid - 1 + n)%n;
            next = (mid + 1 )%n;
            if(arr[mid] < arr[prev] && arr[mid ] < arr[next])
            return arr[mid];
            else if(arr[mid] < arr[high])
            {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
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