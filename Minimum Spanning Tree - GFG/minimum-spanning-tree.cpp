//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet 
{  
    vector<int>rank,parent;
    public:
  
    DisjointSet(int v){
        rank.resize(v);
        parent.resize(v);
        for(int i = 0; i < v; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }
    
   int find_set(int u)
   {
       if( u == parent[u])
       return u;
       return parent[u] = find_set(parent[u]);
   }
   
   void union_set(int u, int v)
   {
       u = find_set(u);
       v = find_set(v);
       
       if(rank[u] < rank[v])
       swap(u,v);
       parent[v] = u;
       rank[u]++;
   }
  
  
};




class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //make edges
        vector<pair<int,pair<int,int>>>edges;
        //traverse adjacency list of every vertex
        for(int i = 0;i<V;i++)
        {
            for(auto it : adj[i])
            {
                int v = it[0];
                int wt = it[1];
                int u = i;
                edges.push_back({wt,{u,v}});
            }
        }
        //apply kruskals algorithm for every edge if it is in same component or int defferent
       DisjointSet dsu(V);
       sort(edges.begin(),edges.end());
        int mstWt = 0;
        for(int i = 0;i<edges.size();i++)
        {
            int wt = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            if(dsu.find_set(u) != dsu.find_set(v)){
                mstWt += wt;
                
                dsu.union_set(u,v);
            }
            
        }
        return mstWt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends