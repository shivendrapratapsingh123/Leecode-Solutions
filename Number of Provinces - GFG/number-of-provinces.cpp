//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++



class DisjointSet
{  
    public:
    vector<int>size,parent;
    
    DisjointSet(int v){
        size.resize(v);
        parent.resize(v);
        for(int i = 0;i<v;i++)
        {
            size[i]  = 1;
            parent[i] = i;
        }
    }
    
    int find_set(int u){
        if(u == parent[u]) return u;
        parent[u] = find_set(parent[u]);
    }
    
    void union_set(int u, int v)
    {
        u = find_set(u);
        v = find_set(v);
        if( u != v)
        {
            if(size[u] < size[v])
            swap(u,v);
            parent[v] = u;
            size[u] += size[v];
        }
    }
};







class Solution {
  public:
  // by using disjoint set union
  
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet dsu(V);
       // if there is edge between two node then we try to make union of them 
       for(int i = 0;i<adj.size();i++)
       {
           for(int j = 0;j<adj[0].size();j++)
           {
               if(adj[i][j] == 1)
               dsu.union_set(i,j);
           }
       }
       int cnt = 0;
       for(int i = 0;i<V;i++)
       {
           if(dsu.find_set(i) == i)
           cnt++;
       }
       return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends