//using BFS

// class Solution
// {
//     public:
//         bool isBipartite(vector<vector < int>> &graph)
//         {

//             int n = graph.size();
//             int m = graph[0].size();
//             queue<int> q;

//             vector<int> color(n, -1);

//             for (int i = 0; i < n; i++)
//             {
//                 if (color[i] == -1)
//                 {
//                     q.push(i);
//                     color[i] = 0;
//                 }

//                 while (!q.empty())
//                 {
//                     int node = q.front();
//                     q.pop();

//                     for (auto adjacent: graph[node])
//                     {
//                         if (color[adjacent] == -1)
//                         {
//                             color[adjacent] = !color[node];
//                             q.push(adjacent);
//                         }
//                         else if (color[adjacent] == color[node])
//                         {
//                             return false;
//                         }
//                     }
//                 }
//             }
//             return true;
//         }
// };





// using dfs

class Solution
{
    public:
    
    
    bool dfs(int node ,int col,vector<int>&color,vector<vector<int>>&graph)
    {
        color[node] = col;
        
        for( auto adj : graph[node])
        {
            if(color[adj] ==-1)
            {
                if(dfs(adj, !col, color,graph) ==false)
                    return false;
            }
            else if(color[adj]==col)
                return false;
        }
        return true;
    }
    
    
    
    
        bool isBipartite(vector<vector < int>> &graph)
        {

            int n = graph.size();
            int m = graph[0].size();

            vector<int> color(n, -1);

            for (int i = 0; i < n; i++)
            {
                if (color[i] == -1)
                {
                   if (dfs(i,0,color,graph)== false)
                       return false;
                }
            }

               
            return true;
        }
};