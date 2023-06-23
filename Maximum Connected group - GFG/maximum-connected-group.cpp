//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    public: 
    vector<int>size,parent;
    DisjointSet(int v){
        size.resize(v);
        parent.resize(v);
        for(int i = 0;i<v;i++)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int find_set(int u){
        if(u == parent[u]) return u;
        return parent[u] = find_set(parent[u]);
    }

    void union_set(int u, int v){
        u = find_set(u);
        v = find_set(v);

        if(u != v){
            if(size[u] < size[v])
            swap(u,v);
            parent[v] = u;
            size[u]+= size[v];
        }
    }
};





class Solution {
    
     bool isValid(int r, int c, int n)
   {
       if(r < n && r >= 0 && c < n && c >=0) return true;
       return false;
   }
    
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
      DisjointSet dsu(n*n);

      // step1 connecting components 
      int dr[] = {-1, 0, 1, 0};
      int dc[]  = {0,-1,0,1};
      for(int row = 0;row<n;row++)
      {
          for(int col = 0;col<n;col++)
          {
              if(grid[row][col] == 0) continue;
              for(int ind = 0; ind < 4;ind++)
              {
                  int newr = row + dr[ind];
                  int newc = col + dc[ind];
                  if(isValid(newr,newc,n) && grid[newr][newc] )
                  {
                     int nodeNo = row*n+col;
                     int adjNodeNo = newr*n + newc;
                      dsu.union_set(nodeNo, adjNodeNo);
                  }
              }
          }
      } 
      //step 2 ------- trying to convert every zero cell to one 
      int mx = 0;
      for(int row = 0;row<n;row++)
      {
          for(int col = 0;col<n;col++)
        {
            if(grid[row][col] == 1) continue;
            set<int>components;
            for(int ind = 0;ind<4;ind++)
            {
                int newr = row + dr[ind];
                int newc = col + dc[ind];
                if(isValid(newr,newc,n) && grid[newr][newc]){
                 components.insert(dsu.find_set(newr*n + newc));
                }
            }
            int sizeTotal = 0;
            for(auto it : components){
               sizeTotal  += dsu.size[it];
            }
            mx = max(mx,sizeTotal+1);
        }
      } 
      // if only ones are there in the grid
      for(int row = 0;row < n;row++){
          for(int col = 0;col < n;col++)
          {
              int node = dsu.find_set(row*n + col);
              mx = max(mx, dsu.size[node]);
          }
      }
      return mx; 
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends