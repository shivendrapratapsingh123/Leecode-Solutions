class Solution {
public:
    int minJumps(vector<int>& arr) {
        int steps =0;
        int n = arr.size();
        unordered_map<int, vector<int>>valuesOfInd;
        
        for(int i =0;i<n;i++)
        {
            valuesOfInd[arr[i]].push_back(i);
        }
        queue<int>q;
        vector<bool>visited(n,false);
        q.push(0);
        visited[0]= true;
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0;i<size;i++)
            {
                int curr = q.front();
                q.pop();
                
                if(curr == n-1)
                    return steps;
                vector<int>next = valuesOfInd[arr[curr]];
                next.push_back(curr-1);
                next.push_back(curr+1);
                for(auto x : next)
                {
                    if(x>=0 && x<n&&!visited[x])
                    {
                        visited[x] = true;
                        q.push(x);
                    }
                }
                valuesOfInd[arr[curr]].clear();
            }
            steps++;
        }
        return steps;
    }
};