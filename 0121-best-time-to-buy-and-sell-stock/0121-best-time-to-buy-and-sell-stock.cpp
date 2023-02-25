// recursive +memoization 

// class Solution {
// public:
    
//     int solve(vector<int>&prices, int k ,int buy, int idx,vector<vector<int>>&memo)
//     {
//         if(idx>=prices.size() || k<=0)
//             return 0;
//         if(memo[idx][buy]!=-1)
//             return memo[idx][buy];
//         if(buy)
//         {
//             return memo[idx][buy]=max(-prices[idx]+solve(prices,k,!buy,idx+1,memo),solve(prices, k, buy, idx+1,memo));
//         }
//         else{
//             return memo[idx][buy]=max(prices[idx]+solve(prices, k-1,!buy,idx+1,memo), solve(prices, k,buy, idx+1,memo));
//         }
//     }
    
    
    
//     int maxProfit(vector<int>& prices) {
//         vector<vector<int>>memo(prices.size(),vector<int>(2,-1));
//        return  solve(prices, 1,1,0,memo);
//     }
// };








class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini = prices[0];
        int profit =0;
        for(int i =1;i<prices.size();i++)
        {
            profit = max(profit, prices[i]-mini);
            mini = min(mini,prices[i]);
        }
        return profit;
    }
};