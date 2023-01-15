//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     bool conn[16][16];
     long long int dp[1<<15][15];
  long long int  findLuckyPerm(vector<int>&arr,int mask,int prev){
      
      
      if(dp[mask][prev] != -1)
      return dp[mask][prev];
      if(mask == 0)
      return 1;
      
      
      
      long long int  cnt = 0;
      for(int i = 0; i<arr.size();i++)
      {
          
          if( (mask & (1<<i)) > 0)
         {
             int curr = arr[i];
             if(prev == -1 || conn[prev][curr])
             {
                 cnt += findLuckyPerm(arr,mask^(1<<i),curr);
             }
         }
      }
      dp[mask][prev] = cnt;
      return cnt;
  }
  
  
    long long int luckyPermutations(int N, int M, vector<int> arr,
                                    vector<vector<int>> graph) {
        
        int mask = ((1<<N)-1);  // mask is 2^N -1 through dry run
       
       memset(dp,-1,sizeof(dp));
       memset(conn,false,sizeof(conn));
        for(int i = 0; i<graph.size();i++)
        {
            int u = graph[i][0];
            int v = graph[i][1];
            conn[u][v] = true;
            conn[v][u] = true;
        }
        return findLuckyPerm(arr,mask,-1);  // -1 as the previous element in start
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<int> arr(N);
        vector<vector<int>> graph(M, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> graph[i][j];
            }
        }
        Solution obj;
        cout << obj.luckyPermutations(N, M, arr, graph) << endl;
    }
}

// } Driver Code Ends