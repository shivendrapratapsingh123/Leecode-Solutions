//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
   int solve(int ind, int target,int pr, int arr[],int n )
   {
       if(ind >= n)
       {
         if(pr >=0 && pr <= target)
         return 1;
         return 0;
       }
       
       int notTake = solve(ind+1,target,pr,arr,n);
       
       int take = 0;
        if(pr == -1)
        take = solve(ind+1,target,arr[ind],arr,n);
       else if( pr*arr[ind] <= target)
       take = solve(ind+1,target,pr*arr[ind],arr,n);
       
       return take+notTake;
   }
  
    int numOfSubsets(int arr[], int n, int k) {
      
      return solve(0,k,-1,arr,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends