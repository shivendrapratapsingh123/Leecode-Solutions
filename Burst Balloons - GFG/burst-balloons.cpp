//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/* this is t

this is the variation of mcm here we have to think that initailly there is only one element to delete
but range is as whole arrray after that there are only two element and range have been srink to one
element less and excluded element is that element which was deleted in the last in this way we will 
remove the steps thinking from bottom and intially range is full and is srinking slowly 
that is when there is only one element in the array then range is full and so on 
in this way we will get independent subproblems that will lead to the result
*/
class Solution {
public:

int f(int i, int j, vector<vector<int>>&memo,vector<int>&arr)
{
    if(i>j)
    return 0;
    if(memo[i][j] != -1)
    return memo[i][j];
    int maxCoins = INT_MIN;
    for(int idx = i; idx<=j;idx++)             //making partition
    {
       int coins = arr[i-1]*arr[idx]*arr[j+1] + f(i,idx-1,memo,arr) + f(idx+1,j,memo,arr); 
       maxCoins = max(maxCoins,coins);
    }
    
    return memo[i][j] = maxCoins;
}


    int maxCoins(int N, vector<int> &arr) {
        vector<vector<int>>memo(N+1,vector<int>(N+1,-1));
        
        arr.push_back(1);
        arr.insert(arr.begin(),1);
         
         return f(1,N,memo,arr);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends