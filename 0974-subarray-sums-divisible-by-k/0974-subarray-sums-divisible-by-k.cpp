class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int currSum = 0;
        int cnt = 0;
        vector<int>group(k,0);
        group[0] = 1; // in case whole array sum is divisible be k or ongoing prefix itself is divisible byk

        for(int i = 0; i < nums.size();i++)
        {
            currSum =  (currSum + nums[i]%k + k)%k;
            cnt += group[currSum];
            group[currSum]++;
        }
        return cnt;
    }
};