// class Solution {
// public:
    
    
//     int decideJump(vector<int>&nums, int n ,int currPos)
//     {
//         if(currPos>=n-1)
//             return 0;
        
//         int minJump = 1000007;
//         int maxSteps = nums[currPos];
//         while(maxSteps>0)
//         {
//             minJump = min(minJump,1+decideJump(nums, n, currPos+maxSteps));
            
//             maxSteps = maxSteps-1;
//         }
        
//         return minJump;
//     }
    
    
//     int jump(vector<int>& nums) {
//         return decideJump(nums, nums.size(),0);
//     }
// };




// memoisation 

// class Solution {
// public:
    
    
//     int decideJump(vector<int>&nums, int n ,vector<int>&memo, int currPos)
//     {
//         if(currPos>=n-1)
//             return 0;
        
//         int minJump = 1000007;
//         if(memo[currPos] !=-1) return memo[currPos];
//         int maxSteps = nums[currPos];
//         while(maxSteps>0)
//         {
//             minJump = min(minJump,1+decideJump(nums, n,memo, currPos+maxSteps));
            
//             maxSteps = maxSteps-1;
//         }
        
//         memo[currPos] = minJump;
        
//         return minJump;
//     }
    
    
//     int jump(vector<int>& nums) {
//         vector<int>memo(nums.size(),-1);
//         return decideJump(nums, nums.size(),memo,0);
//     }
// };





// 3.0 tabulation dp 

 
// class Solution {
// public:    
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         int dp[n];
//         memset(dp,1000007,sizeof(dp));
        
//         dp[0]=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j =i+1;j<min(i+nums[i]+1,n);j++)
//             {
//                 dp[j] = min(dp[j],1+dp[i]);
//             }
//         }
//         return dp[n-1];
//     }
// };









// 4.0 greedy solution 



class Solution {
public:    
    int jump(vector<int>& nums) {
       
        int n = nums.size();
        int start=0;
        int end = 0;
        int jump =0;
        int farthest;
        while(end<n-1)
        {
           farthest =0;
            for(int i =start;i<=end;i++)
            {
                farthest = max(farthest,i+nums[i]);
               
            }
             start = end+1;
                end = farthest;
                jump++;
        }
        return jump;
    }
};