class Solution {
public:
int mod = 1e9+7;
  int solve(int n , vector<int>&memo)
  {
      if(n == 1)
      return 1;
      if(n == 2)
      return 2;
      if(n == 3)
      return 5;

      if(memo[n] != -1)
      return memo[n];
      
      int  combination =  (2*solve(n-1,memo)%mod+ solve(n-3,memo)%mod)%mod;
      return  memo[n] = combination;
  }

    int numTilings(int n) {
        
        vector<int >memo(n+1,-1);
        return solve(n,memo);
    }
};