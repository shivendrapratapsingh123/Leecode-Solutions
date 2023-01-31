class Solution {
public:

 long long int solve(vector<int>&nums,int curr,int isEven, vector<vector<long long>>&dp)
 {
     if(curr >= nums.size())
     return 0;
      
      if(dp[curr][isEven] != -1)
      return dp[curr][isEven];
     long long int  notTakeSum = solve(nums,curr+1,isEven,dp);
     long long int takeSum = 0;
     if(isEven)
     {
         takeSum += nums[curr];
     }
     else{
         takeSum -= nums[curr];
     }
     takeSum  += solve(nums,curr+1, !isEven,dp);

     return  dp[curr][isEven] = max(takeSum,notTakeSum);
 }

    long long maxAlternatingSum(vector<int>& nums) {

      int n = nums.size();
      vector<vector<long long>>dp(n+1,vector<long long >(2,-1));
      return solve(nums,0,1,dp);

    }
};