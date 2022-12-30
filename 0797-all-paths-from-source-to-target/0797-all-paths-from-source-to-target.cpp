class Solution {
public:


void dfs(vector<vector<int>>&graph,int node,vector<vector<int>>&res,vector<int>&temp)
{
    temp.push_back(node);
    if(node == graph.size()-1)
    {
        res.push_back(temp);
    }
    for(auto it : graph[node])
    {
        dfs(graph,it,res,temp);
    }
    temp.pop_back();
    return;
}


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       vector<vector<int>>res;
       vector<int>temp;
       dfs(graph,0,res,temp);
       return res; 
    }
};