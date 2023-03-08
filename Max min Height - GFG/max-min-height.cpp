//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
     
     bool isPossible(int n  , int k, int w , vector<int>&arr, long long int mid)
     
     {
         vector<long long>prefix(n,0);
         long long days = 0;
         for(int i = 0;i<n;i++)
         {
             if(i > 0)
             prefix[i] += prefix[i-1];
             
             if((long long)arr[i] + prefix[i] < mid){
                 
                 long long int req = mid - (long long )arr[i] - prefix[i];
                 days += req;
                 // we have to add this req height till window size
                 prefix[i] += req;
                 
                 if(i+w <n)
                 prefix[i+w] -= req;
             }
             
         }
         
         return (days <=(long long) k );
     }
    
    
    
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
           long long int low = 1; // minimum height that we get let in x days 
           
           long long int high = 1e10; // maximum height that we can get
           
           long long ans = 0;
           
           while(low <= high )
           {
               long long int mid  =  low + (high - low )/2;  // let we want mid height 
               
               if(isPossible(n,k,w,a,mid)){
                   ans = mid;
                   low = mid + 1;
               }
               else{
                   high = mid - 1;
               }
           }
           return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends