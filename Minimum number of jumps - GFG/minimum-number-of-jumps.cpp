//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int nums[], int n){
       int res = 0;
       int l , r;
       l = r = 0;
       int fardest = 0;
     
       while(r < n-1)
       {
           fardest = 0;
           for (int i = l ; i <= r ; i++)
           {
               fardest = max(fardest , i + nums[i]);
           }
            l = r + 1;
            r = fardest;
            if( l > r)   //condition for not reachability
            return -1;
            res += 1;
       } 
       return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends