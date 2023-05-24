//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   
   int solve(int ind1, int ind2 , string& s, string& t,vector<vector<int>>&memo){
       if(ind1 < 0 )
       return ind2+1;
       if(ind2 < 0) 
       return ind1+1;
      
       if(memo[ind1][ind2] != -1)
       return memo[ind1][ind2];
      
       if(s[ind1] == t[ind2])
       {
           memo[ind1][ind2] = 0 + solve(ind1-1,ind2-1,s,t,memo);
       }
       else{
           int x =  1 + solve(ind1-1,ind2,s,t,memo);
           int y  = 1 + solve(ind1,ind2-1,s,t,memo);
           int z =  1 + solve(ind1-1,ind2-1,s,t,memo);
           memo[ind1][ind2] = min({x,y,z});
       }
       return memo[ind1][ind2];
     
   }
  
    int editDistance(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>>memo(n+1,vector<int>(m+1,-1));
    return solve(n-1,m-1,s,t,memo);
     
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends