class Solution {
public:


 void dfs(string node , unordered_map<string , multiset<string>>&adj,vector<string>&ans)
 {
     while(!adj[node].empty())
     {
         string next = *adj[node].begin();
         adj[node].erase(adj[node].begin());
         dfs(next,adj,ans);
     }

     ans.push_back(node);
 }



    vector<string> findItinerary(vector<vector<string>>& tickets) {

       // adjacency list 
       unordered_map<string,multiset<string>>adj;
       
       vector<string>ans;
       int n = tickets.size();
       for(int i = 0 ; i<n;i++)
       {
           adj[tickets[i][0]].insert(tickets[i][1]);
       }
       dfs("JFK",adj,ans);
       reverse(ans.begin(),ans.end());
       return ans;

    }
};