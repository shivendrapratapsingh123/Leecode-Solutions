// //simple bfs
// class Solution {
// public:
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         int n = rooms.size();
//         vector<int>vis(n,0);

//         queue<int>q;
//         q.push(0);
//         while(!q.empty())
//         {
//             int node = q.front();
//             q.pop();
//             vis[node] = 1;
//             for(auto  adjNode : rooms[node])
//             {
//                 if(!vis[adjNode])
//                 {
//                     q.push(adjNode);
//                     vis[adjNode] = 1;
//                 }
                
//             }
//         }
//         for(int i = 0; i< n; i++)
//         {
//             if(vis[i] == 0)
//             return false;
//         }
//         return true;
//     }
// };


//simple dfs solution

class Solution {
public:

    void dfs(int node , vector<int>&vis,vector<vector<int>>&rooms,int n)
    {
        vis[node] = 1;
        for(auto adjNode : rooms[node])
        {
            if(!vis[adjNode])
            {
                dfs(adjNode,vis,rooms,n);
            }
        }
    }


    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n,0);
               dfs(0,vis,rooms,n);

     for(int i = 0; i< n;i++)
     {
         if(vis[i] == 0)
         return false;
     }
     return true;
    }
};