//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   
   int solve(int ind, int prev, int n, int arr[]){
       if(ind == n)
       {
           return 0;
       }
       
       int notTake = solve(ind+1,prev,n,arr);
       int take  = 0;
       if(prev == -1){
           take = solve(ind+1,ind,n,arr); 
       }
      
       else if(abs(arr[prev] - arr[ind]) == 1)
       {
          
           take = 1 + solve(ind+1,ind,n,arr);
           
       }
       return max(notTake,take);
       }
   
    int longestSubsequence(int N, int A[])
    {
       return solve(0,-1,N,A)+1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends