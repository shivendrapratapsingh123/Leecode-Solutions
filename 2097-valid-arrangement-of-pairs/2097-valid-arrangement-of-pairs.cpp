// see the euclidian path concept // see dicussion for good solution explanation
// here stack is used for the purpose of removing edges as we can visit each edge exactly one 
class Solution {
public:



void eular(int currNode ,vector<vector<int>>&ans,unordered_map<int,stack<int>>&mp)
{
   auto &stk = mp[currNode];

   while(!stk.empty())
   {
       int neighbour = stk.top();
       stk.pop();
       eular(neighbour,ans,mp);
       ans.push_back({currNode,neighbour});
   }
}

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
       unordered_map<int,stack<int>>mp;
       int n = pairs.size();
       unordered_map<int,int>indegree;
       unordered_map<int,int>outdegree;
       vector<vector<int>>ans;
       

       for(int i = 0; i<n; i++)
       {
           int u = pairs[i][0];
           int v = pairs[i][1];
           mp[u].push(v);
           indegree[v]++;
           outdegree[u]++;
       }
       int start = -1;
       for(auto it : mp)
       {
           int x = it.first;
           if(outdegree[x] - indegree[x] == 1)
           {
               start = x;
               break;
           }
       }
       if(start == -1)
       start = mp.begin()->first;

    eular(start, ans,mp);
    
    reverse(ans.begin(),ans.end());
       return ans;
    }
};