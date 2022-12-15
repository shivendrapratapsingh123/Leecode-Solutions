// same as house robber here we exclude one element at a time

class Solution {
public:
   
int solve(vector<int>&nums)
{
 int n = nums.size();
      
        if(n==0)
            return 0;
         int val1 = nums[0];
        if(n == 1)
            return val1;
       
        int val2 = max(nums[0],nums[1]);
        if(n==2)
            return val2;
        int max_val;
        for(int i = 2;i<n;i++)
        {
            max_val = max(val1+nums[i],val2);
            val1 = val2;
            val2 = max_val;
        }
        
        return max_val;
}


    int rob(vector<int>& nums) {
       
       
        int n = nums.size();
        if(n==1)
        return nums[0];
        vector<int>temp1,temp2;
        for(int i = 0;i<n;i++)
        {
            if(i!= 0) temp1.push_back(nums[i]);
            if(i!= n-1) temp2.push_back(nums[i]);
        }
        
        return max(solve(temp1),solve(temp2));
    }
};