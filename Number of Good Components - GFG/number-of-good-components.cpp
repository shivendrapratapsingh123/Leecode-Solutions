//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  void dfs(int node , vector<int>&vis,vector<vector<int>>&adj,int &vertex,int &edges)
  {
      vis[node] = 1;
      vertex++;
      for(auto adjNode : adj[node])
     {
        edges++;
      if(!vis[adjNode])
      {
           
          dfs(adjNode,vis,adj,vertex,edges);
      }
     }
  }
  
  
  
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
       
       vector<int>vis(V+1,0);
       int res = 0 , vertex = 0,edges=0;
       for(int i = 1;i<=V;i++)
       {
           if(!vis[i])
           {
               vertex = 0;
               edges = 0;
               dfs(i,vis,adj,vertex,edges);
               if(edges/2 == (vertex*(vertex-1))/2)
               res++;
           }
           
       }
       return res; 
    }
};

// if there are vc2 edges in each component then it is good component




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends