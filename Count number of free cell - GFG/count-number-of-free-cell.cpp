//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      vector<long long int >res;
      vector<int>row(n+1,0);
      vector<int>col(n+1,0);
      
      long long int ans = 0,rowcnt=0,colcnt=0;
      
      long long zero = n*n;
      
      long long cnt  = 2*n-1;
      
      for(int i = 0; i<k;i++)
      {
          int r = arr[i][0];
          int c  = arr[i][1];
          if(row[r] == 0)
          {
              rowcnt++;
              row[r] = 1;
          }
          if(col[c] == 0)
          {
              colcnt++;
              col[c] = 1;
          }
          
          ans = zero - (n*(rowcnt+colcnt) - rowcnt*colcnt);
          res.push_back(ans);
      }
      return res;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends