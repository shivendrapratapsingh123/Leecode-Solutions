//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

 
 class DisjointSet{
     public:
     vector<int>size,parent;
     DisjointSet(int n){
         size.resize(n);
         parent.resize(n);
         for(int i = 0;i<n;i++)
         {
             size[i] = 1;
             parent[i] = i;
         }
     }
     
     int find_set(int u){
         if(u == parent[u])
          return u;
          return parent[u] = find_set(parent[u]);
     }
     
     void union_set(int u ,int v){
         u =  find_set(u);
         v = find_set(v);
         if(u != v){
             if(size[u] < size[v])
              swap(u,v);
              parent[v] = parent[u];
              size[u] += size[v];
         }
     }
 };

 


class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        
        // calculate range of rows and columns
        int maxRows = 0;
        int maxCols = 0;
        for(auto it : stones){
            maxRows = max(maxRows,it[0]);
            maxCols = max(maxCols,it[1]);
        }
        DisjointSet dsu(maxRows + maxCols + 2);
        unordered_map<int,int>stoneMap;
        for(auto it : stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRows+1;
            dsu.union_set(nodeRow, nodeCol);
            stoneMap[nodeRow] = 1;
            stoneMap[nodeCol] = 1;
        }
        int cnt  = 0;
        for(auto it : stoneMap){
            if(dsu.find_set(it.first) == it.first)
            cnt++;
        }
        return n-cnt;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends