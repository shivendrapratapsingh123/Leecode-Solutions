//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
//  3 approaches 1-brute force 2- dynamic programming 3- expand from center

    string longestPalindrome(string s){
        int n = s.size();
        if(n == 1)
        return s.substr(0,1);
        int start = 0;
        int length  = 1;
      vector<vector<int>>dp(n,vector<int>(n,0));  
      int maxLength = 1;
      for(int i = 0;i<n;i++){
          dp[i][i] = 1;  
      }
      for(int i = 0;i<n-1;i++)
      {
          if(s[i] == s[i+1]){
              dp[i][i+1] = 2; 
              length = 2;
              if(length > maxLength)
              {
                 maxLength = length;
                start = i;   
              }
              
          }
      }
      if(n == 2)
      return s.substr(start,maxLength);
      // checking for every length from each index;
      for(int len = 3;len <= n;len++)
      {
          for(int i = 0;i<(n-len+1);i++)
          {
             // end index
             int j = i + len-1;
             if(dp[i+1][j-1] && s[i] == s[j])
             {
                 dp[i][j] = 1;
                 if(len > maxLength){
                     start = i;
                     maxLength = len;
                 }
                
             }
          }
      }
      return s.substr(start, maxLength);
      
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends