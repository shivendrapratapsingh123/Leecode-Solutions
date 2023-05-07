//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
 int solve(string &str, string &pat,int n, int m)
 {
     if((n == 0 && m == 0 ) || m == 0)
     return 1;
     if(n == 0)
     return 0;
     if(str[n-1] == pat[m-1]){
         return solve(str,pat, n-1, m - 1) + solve(str,pat,n-1, m);
     }
     else{
         return solve(str,pat,n-1,m);
     }
 }
    int countWays(string S1, string S2){
        int n = S1.size();
        int m = S2.size();
        return solve(S1,S2,n, m);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}
// } Driver Code Ends