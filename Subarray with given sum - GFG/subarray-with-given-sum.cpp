//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        if(s == 0)
        return {-1};
        vector<int>ans;
        int i = 0;
        int j = 0;
        long long sum = 0;
        while(j<n){
            sum += (long long int)arr[j];
            while(sum > s){
                sum -= (long long int)arr[i];
                i++;
            }
            if(sum == s){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            j++;
        }
        if(ans.size())
        return ans;
        return {-1};
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends