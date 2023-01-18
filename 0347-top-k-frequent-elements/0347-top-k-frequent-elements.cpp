// by using minheap we can get the result in nlogk t.c.
//we will always keep size of min heap equal to k 
// more optimisation using bucket sort t.c (n);
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {

//         unordered_map<int,int>mp;
//         priority_queue<pair<int,int>>pq;

//         for(int i = 0; i < nums.size();i++)
//         {
//             mp[nums[i]]++;
//         }
//         vector<int>ans;
//         int cnt = 0;
//         for(auto it : mp)
//         {
//           pq.push({it.second,it.first});
//         }
//         while(!pq.empty() && cnt < k)
//         {
//             auto top = pq.top();
//             pq.pop();
//             ans.push_back(top.second);
//             cnt++;
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int>mp;
       
       int n = nums.size();
       vector<vector<int>>bucket(n+1);
       
        for(int i = 0; i < nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<int>ans;
       for(auto it : mp)
       {
           bucket[it.second].push_back(it.first);
       }
       for(int i = n ; i>= 0; i--)
       {
           if(ans.size() >=k)
           break;
           if(!bucket[i].empty())
           ans.insert(ans.end(),bucket[i].begin(),bucket[i].end());
       }
        return ans;
    }
};