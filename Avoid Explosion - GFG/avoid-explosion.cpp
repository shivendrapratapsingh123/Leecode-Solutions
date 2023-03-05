//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
   int find(int node, vector<int>&parent){
       if( node == parent[node])
       return node;
       parent[node] = find(parent[node],parent);
   }
  
void unionn(int u , int v, vector<int>&parent, vector<int>&rank){
    
    if(rank[u] < rank[v])
    {
      parent[u] = v;
      rank[v]++;
    }
    else if(rank[v] < rank[u])
    {
        parent[v] = u;
        rank[u]++;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}
  
    vector<string> avoidExplosion(vector<vector<int>> mix, int n,vector<vector<int>> danger, int m){
       vector<string>ans;
        vector<int>parent(n+1);
        vector<int>rank(n+1,1);
        for(int i = 0;i<= n;i++)
        parent[i] = i;
        
        for(int i = 0;i<mix.size();i++)
        {
            int u = mix[i][0];
            int v  = mix[i][1];
            u = find(u,parent);
            v = find(v,parent);
            bool isSafe = true;
            for(int j = 0;j<danger.size();j++)
            {
                int x = danger[j][0];
                int y = danger[j][1];
                x = find(x,parent);
                y = find(y,parent);
                if( (u == x && v == y ) || (u == y && v == x)){
                    isSafe = false;
                    break;
                }
            }
             if(isSafe)
             ans.push_back("Yes");
             else
             ans.push_back("No");
             if(isSafe)
            unionn(u,v,parent,rank);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends