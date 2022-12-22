// class Solution {
// public:
  
//   int preprocessing(int src, int parent,vector<int>adj[],vector<int>&subtreeSize,vector<int>&subtreeAns)
//   {
//       int distForNode =0; // counts distance of given node from its children
//       int countOfNodes =1;  //counts number of children below a node (included)

//       for(auto adjNode : adj[src])
//       {
//           if(adjNode == parent)
//           continue;
//           noOfNodes += preprocessing(adjNode,src,adj,subtreeSize,subtreeAns);
//           distForNode += 
//       }
//   }


//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    
//         vector<int>adj[n]; // adjacency list 
//         vector<int>subtreeSize(n); //answer for subtree rooted with node
//         vector<int>subtreeAns(n);   //answer for subtree rooted with node
       
//        preprocessing(0,-1,adj,subtreeSize,subtreeAns); // calculates size and and 
//        //sumofdistances of rooted node from its childrens that is the ans
//     }
// };




class Solution{
    public:
       vector<unordered_set<int>> tree;
    vector<int> res, count;

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        tree.resize(N);
        res.assign(N, 0);
        count.assign(N, 1);
        for (auto e : edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return res;

    }

    void dfs(int root, int pre) {
        for (auto i : tree[root]) {
            if (i == pre) continue;
            dfs(i, root);
            count[root] += count[i];
            res[root] += res[i] + count[i];
        }
    }

    void dfs2(int root, int pre) {
        for (auto i : tree[root]) {
            if (i == pre) continue;
            res[i] = res[root] - count[i] + count.size() - count[i];
            dfs2(i, root);
        }
    }
};