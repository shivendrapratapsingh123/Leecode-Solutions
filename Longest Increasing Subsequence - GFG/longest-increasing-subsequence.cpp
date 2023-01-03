//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
        vector<int>nums;
       for(int i =0; i < n; i++)
       nums.push_back(arr[i]);
        vector<int>LIS;
        LIS.push_back(nums[0]);
        for(int i = 1; i < n ; i++)
        {
            if(nums[i] > LIS.back())
            {
               LIS.push_back(nums[i]);
            }
            else
            {
              int idx = lower_bound(LIS.begin(),LIS.end(),nums[i]) - LIS.begin();
              LIS[idx] = nums[i];
            }
        }
        return LIS.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends