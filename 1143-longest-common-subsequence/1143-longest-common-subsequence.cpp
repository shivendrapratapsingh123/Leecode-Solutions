// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n1 = text1.size();
//         int n2 = text2.size();
        
//         int dp[n1+1][n2+2];
//         memset(dp,0,sizeof(dp));
//         for(int i=1;i<=n1;i++)
//         {
//             for(int j =1;j<=n2;j++)
//             {
//               if(text1[i-1]==text2[j-1])
//               {
//                   dp[i][j]=1+dp[i-1][j-1];
//               }
//                 else
//                 {
//                     dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
//         }
//         return dp[n1][n2];
//     }
// };





class Solution {
public:
    
    
    
  int recursion(string &str1,string &str2, int n1,int n2, int i,int j,vector<vector<int>>&memo)
  {
      if(i<0||j<0)
          return 0;
      
      if(memo[i][j] != -1)
          return memo[i][j];
      
      if(str1[i] == str2[j])
      {
          return memo[i][j] = 1+recursion(str1,str2,n1,n2,i-1,j-1,memo);
      }
      else
      {
          return memo[i][j] =  max(recursion(str1,str2,n1,n2,i-1,j,memo) , recursion(str1,str2,n1,n2,i,j-1,memo));
      }
  }
    
    
    
    
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>>memo(n1,vector<int>(n2,-1));
        return recursion(text1,text2,n1,n2,n1-1,n2-1,memo);
    }
};