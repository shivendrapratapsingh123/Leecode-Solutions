//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution {
   public:
    int removeStudents(int arr[], int n) {
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
        return n-LIS.size();
    }
};



















// lis bottom up 

 
// class Solution {
//   public:
//     int removeStudents(int nums[], int n) {
//          // int n = nums.size();
//         vector<int>LIS(n,1);
        
//         for(int i = n-1;i>=0;i--)
//         {
//             for(int j = i+1;j<n;j++)
//             {
//                 if(nums[i]<nums[j])
//                     LIS[i] =max(LIS[i],1+LIS[j]) ;
//             }
//         }
        
//         int ans = LIS[0];
//         for(int i =1;i<n;i++)
//             ans = max(ans, LIS[i]);
//         return n-ans;
//     }
// };

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends