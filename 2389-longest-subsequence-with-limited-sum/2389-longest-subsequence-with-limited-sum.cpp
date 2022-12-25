class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int n= nums.size();
        for(int i =1;i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        
        for(auto &q : queries)
        {
            int len = upper_bound(nums.begin(), nums.end(),q) -nums.begin();
            ans.push_back(len);
        }
        return ans;
    }
};