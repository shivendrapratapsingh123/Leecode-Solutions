// recursive approach 

// class Solution {
// public:
    
//     int find_max_money(vector<int>&nums,int n)
//     {
//         if(n<0)
//             return 0;
//         if(n==0)
//             return nums[0];
//         int pick = nums[n]+find_max_money(nums,n-2,dp);
//         int notpick = find_max_money(nums,n-1,dp);
//         return  max(pick,notpick);
//     }
    
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         return find_max_money(nums,n-1);
        
//     }
// };



 // recursion with memoisation  top down approach 


class Solution {
public:
    
    int find_max_money(vector<int>&nums,int n,vector<int>&dp)
    {
        if(n<0)
            return 0;
        if(n==0)
            return nums[0];
        if(dp[n]!=-1)
            return dp[n];
        int pick = nums[n]+find_max_money(nums,n-2,dp);
        int notpick = find_max_money(nums,n-1,dp);
        return dp[n] = max(pick,notpick);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return find_max_money(nums,n-1,dp);
        
    }
};



// optimised dp bottom up approach 

// class Solution {
// public:
   
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>dp(n,0);
//         if(n==0)
//             return 0;
//         if(n == 1)
//             return nums[0];
//         if(n==2)
//             return max(nums[0],nums[1]);
//         dp[0]= nums[0];
//         dp[1] = max(nums[0],nums[1]);
//         for(int i = 2;i<n;i++)
//             dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
//         return dp[n-1];
        
//     }
// };




// space optimisation in dp 

// class Solution {
// public:
   
//     int rob(vector<int>& nums) {
//         int n = nums.size();
      
//         if(n==0)
//             return 0;
//          int val1 = nums[0];
//         if(n == 1)
//             return val1;
       
//         int val2 = max(nums[0],nums[1]);
//         if(n==2)
//             return val2;
//         int max_val;
//         for(int i = 2;i<n;i++)
//         {
//             max_val = max(val1+nums[i],val2);
//             val1 = val2;
//             val2 = max_val;
//         }
        
//         return max_val;
        
//     }
// };


