//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
 
 int Palindrome(string& temp)
 {
     int i =0;
     int j = temp.size()-1;
     while(i<j){
         if(temp[i] != temp[j])
         return false;
         i++;
         j--;
     }
     return true;
 }
 
 int solve(int ind, string& str, vector<int>&dp)
 {
     if(ind == str.size())
     return 0;
     if(dp[ind] != -1)
     return dp[ind];
     int min_cost = INT_MAX;
     int cost = 0;
     string temp = "";
     for(int i = ind; i<str.size();i++)
     {
         temp += str[i];
         if(Palindrome(temp))
         {
             cost = 1 + solve(i+1,str,dp);
             min_cost = min(min_cost,cost);
         }
     }
     return dp[ind] =  min_cost;
 }

    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<int>dp(n+1,-1);
        return solve(0,str,dp)-1; //one extra partition so subtract one from the ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends