//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  int kandansAlgo(vector<int>&temp,int c)
  {
      int max_sum = INT_MIN;
      int sum = 0;
      for(int i = 0;i<c;i++)
      {
          sum = max(temp[i],temp[i]+sum);
          max_sum = max(max_sum,sum);
      }
      return max_sum;
  }
  
    int maximumSumRectangle(int r, int c, vector<vector<int>>mat) {
        
        int res = INT_MIN;
        for(int i = 0;i<r;i++)
        {
            vector<int>temp(c);
            for(int j = i;j<r;j++)
            {
               for(int col = 0;col<c;col++)
               {
                   temp[col] += mat[j][col];
               }
               int t = kandansAlgo(temp,c);
               res = max(res,t);
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends