class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        
        vector<pair<int,int>>adj[n];
        for(auto it : flights)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        q.push({0,{src,0}});
        dist[src] =0;
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            if(stops >k)
                continue;
            for( auto it : adj[node])
            {
                int adjnode = it.first;
                int cost = it.second;
                if(cost + dis < dist[adjnode] && stops <= k)
                {
                    dist[adjnode] = cost + dis;
                    q.push({1+stops,{adjnode,dist[adjnode]}});
                }
            }
        }
        if(dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};