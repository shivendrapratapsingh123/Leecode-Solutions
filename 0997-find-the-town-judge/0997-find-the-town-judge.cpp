class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)
        return 1;
        if(trust.size()==0&&n>1)
        return -1;
        unordered_set<int>graph[n+1];
        for(int i =0; i<trust.size();i++)
        {
            graph[trust[i][0]].insert(trust[i][1]);
        }

    //    cout<<graph.size()<<"\n";

       int flag = 0,cnt=0;
        for(int i  = 1;i<= n;i++)
        {
            if(graph[i].size()==0)
            {
                flag = i;
                cnt++;
            }

        }
        if(cnt >1)
        return -1;
        if(flag)
        {
            for(int i = 1;i<=n;i++)
            {
                if(graph[i].size())
                {
                   if(graph[i].find(flag) == graph[i].end())
                   return -1;
                }
            }
        }
         if(flag == 0)
         return -1;
        return flag;
    }
};