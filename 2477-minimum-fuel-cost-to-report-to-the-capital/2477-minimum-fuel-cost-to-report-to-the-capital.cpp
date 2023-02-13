class Solution {
public:
long long int fuel = 0;

  long long int dfs(int node , int parent , vector<int>adj[],int seats)
  {
      long long int people = 1; // at each node 1 people 

      for(auto adjNode : adj[node])
      {
          if(adjNode != parent)
          {
              people += dfs(adjNode , node, adj, seats);
          }
      }
      if(node != 0)
      fuel += ceil((double)people/seats);
      return people;
  }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        // make adjacency list
        int n = roads.size()+1;
        vector<int>adj[n];
        for(int i  = 0;i<roads.size();i++)
        {
            int u = roads[i][0];
            int v  = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // function will contain current node that is 0  , its parent that we
        // will take as -1 and adjacency list and seats in the car
        dfs(0,-1,adj,seats);
        return fuel;
    }
};