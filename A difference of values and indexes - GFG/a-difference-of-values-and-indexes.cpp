//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends

// we will try to rearrange the given expression then only two cases will be there 
//a[i] > a[j] && i>j
 // a[i]>a[j] && i<j
 // through this we can calculate the answer in linear time by taking absoulte value see code
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        int maxi1 = arr[0]+0;
        int mini1 = arr[0]+0;
        int maxi2 = arr[0]-0;
        int mini2 = arr[0]-0;
        for(int i = 1; i<n; i++)
        {
            maxi1 = max(maxi1, arr[i]+i);
            mini1 = min(mini1,arr[i]+i);
            maxi2 = max(maxi2,arr[i]-i);
            mini2 = min(mini2,arr[i]-i);
        }
        
        return max(abs(maxi1-mini1),abs(maxi2-mini2));
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends