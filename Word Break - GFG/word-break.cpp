//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:

    // int solve(int ind, string& s, unordered_map<string,int>&mp,vector<int>&dp)
    // {
    //     if(ind >= s.size())
    //     return true;
    //     if(dp[ind] != -1)
    //     return dp[ind];
    //     for(int k = 1; k <= s.size()-ind;k++)
    //     {
    //         if(mp.find(s.substr(ind,k))!= mp.end() && solve(ind+k,s,mp,dp))
    //         return dp[ind] = true;
    //     }
    //     return dp[ind] = false;
    // }
// tabulation 
    int wordBreak(string A, vector<string> &B) {
         int n = A.size();
         unordered_map<string,int>mp;
         for(int i = 0;i<B.size();i++)
         mp[B[i]]++;
         vector<bool>dp(A.size()+1,false);
         dp[n] = true;
         for(int ind = n-1;ind>=0;ind--)
         {
             for(int k = 1;k<=n-ind;k++)
             {
                 if(mp.find(A.substr(ind,k))!= mp.end() && dp[ind+k])
                 dp[ind] = true;
             }
         }
         return dp[0];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends