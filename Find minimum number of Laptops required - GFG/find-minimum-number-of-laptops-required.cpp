//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int n, int arr[], int dep[]) {
        sort(arr,arr+n);
       sort(dep,dep+n);
       
       int plat_needed =1;
       int result = 1;
       int i =0;
       int j=1;
       while(i<n&&j<n)
       {
           if(arr[j]<dep[i])
           {
               plat_needed++;
               j++;
           }
           else if(arr[j]>=dep[i])
           {
               plat_needed--;
               i++;
           }
           if(plat_needed > result)
           result = plat_needed;
       }
       return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends