//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class DisjointSet{
    
    vector<int>rank,parent;
    public:
    
    DisjointSet(int v)
    {
        rank.resize(v);
        parent.resize(v);
      for(int i = 0;i<v;i++)
      {
          rank[i] = 0;
          parent[i] = i;
      }
    }
    int find_set(int u)
    {
        if(u == parent[u])
        return u;
       else 
       return parent[u] = find_set(parent[u]);
    }
    
    void union_set(int u, int v)
    {
        u = find_set(u);
        v = find_set(v);
       
            if(rank[u] < rank[v])
              swap(u,v);
              parent[v] = u;
             if(rank[u] == rank[v])
              rank[u]++; 
    }
};


class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        
        DisjointSet dsu(n);
        int extra = 0;
        for(int i = 0;i<edge.size(); i++)
        {
             int u = edge[i][0];
             int v = edge[i][1];
             if( dsu.find_set(u) == dsu.find_set(v))
            extra++;
            else
            dsu.union_set(u,v);
        }
        int cnt = 0;
        for(int i = 0;i<n;i++)
        {
            if(dsu.find_set(i) == i)
            cnt++;
        }
        int ans = cnt-1;
        if(extra >= ans)
        return ans;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends