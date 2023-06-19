//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n+1];
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        for(auto it  : edges)
        {
            adj[it[0]].push_back({it[1],it[2]}); // stores node and weight;
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int>parent(n+1); for(int i = 0;i<=n;i++) parent[i] = i;
        vector<int>dist(n+1,1e9);
        vector<int>ans;
        
        pq.push({0,1});  // stores dist  of the node from root and tht node;
        dist[1]=0;
        parent[1]=1;
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node])
            {
                int adjnode = it.first;
                int edgewt = it.second;
                if(dis + edgewt < dist[adjnode])
                {
                    dist[adjnode] = dis+edgewt;
                    pq.push({dis+edgewt,adjnode});
                    parent[adjnode] = node;
                }
            }
        }
        
        int node = n;
        while(parent[node] != node)
        {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(node);
        
        reverse(ans.begin(),ans.end());
        if(dist[n] == 1e9)
        return {-1};
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends