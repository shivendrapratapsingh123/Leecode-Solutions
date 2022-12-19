//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
       int inf = 1e9;
        vector<int>dist(n+1,inf);
        int size = flights.size();
        vector<pair<int,int>>adj[n+1]; // stores adjnode then wt
        for(int i = 0;i<size;i++)
        {
            int node = flights[i][0];
            int adjNode = flights[i][1];
            int wt = flights[i][2];
            adj[node].push_back({adjNode,wt});
        }
        dist[k] = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //wt then adjnode
        pq.push({0,k});
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int wt = it.second;
                
                if(dis + wt < dist[adjNode])
                {
                  dist[adjNode] = dis + wt;  
                  pq.push({dist[adjNode],adjNode});
                }
            }
        }
        int maxi = -1;
        for(int i = 1;i<=n;i++)
        {
            maxi = max(maxi,dist[i]);
        }
        
        if(maxi == inf)
        return -1;
        return maxi;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends