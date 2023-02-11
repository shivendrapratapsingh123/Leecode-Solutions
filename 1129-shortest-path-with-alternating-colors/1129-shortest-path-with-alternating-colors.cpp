class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<int>answer(n,-1);
        vector<vector<pair<int,int>>>adj(n);
        vector<vector<bool>>vis(n,vector<bool>(2,0));
        // make adjacency list that contains node with it's colour 
        // let red color = 0, blue color = 1
        for(auto it : redEdges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v,0});
        }
         for(auto it : blueEdges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v,1});
        }
        // queue will contain current node , steps so far and color of the node
        queue<vector<int>>q;
        q.push({0,0,-1});  // node zero, steps = 0 and color = -1

        vis[0][0] = vis[0][1] = 1;
        answer[0] = 0;
        while(!q.empty())
        {
            int node = q.front()[0];
            int steps = q.front()[1];
            int prevcolor = q.front()[2];
            q.pop();
            for(auto it : adj[node]){
                int adjNode = it.first;
                int color = it.second;
                if(!vis[adjNode][color] && color != prevcolor)
                {
                    vis[adjNode][color] = 1;
                    q.push({adjNode,steps+1,color});
                    if(answer[adjNode] == -1)
                    answer[adjNode] = 1 + steps;
                }
            }
        }
        return answer;
    }
};