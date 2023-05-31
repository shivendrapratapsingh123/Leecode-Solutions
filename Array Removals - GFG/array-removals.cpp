//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //binary search approach 
    int removals(vector<int>& arr, int k){
        
        int n = arr.size();
        int ans = n-1;
        sort(arr.begin(),arr.end());
        for(int i = 0;i<n;i++)
        {
            int pos = upper_bound(arr.begin(),arr.end(),arr[i]+k) - arr.begin();
            ans = min(ans,n - (pos-i));
        }
        return  ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends