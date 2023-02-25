class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<int>pq;

        int minval = INT_MAX;
        for(int i = 0; i<nums.size();i++)
        {
            if(nums[i]&1)
            {
                nums[i] = nums[i]*2;
            }
            pq.push(nums[i]);
            minval = min(minval , nums[i]);
        }
        int minDeviation  = INT_MAX;
        while(true)
        {
            int maxVal = pq.top();
            pq.pop();
            minDeviation = min(minDeviation , maxVal - minval);
            if(maxVal %2 == 1)break;
            maxVal = maxVal/2;

            minval = min(minval , maxVal);
            pq.push(maxVal);
        }
        return minDeviation;
    }
};