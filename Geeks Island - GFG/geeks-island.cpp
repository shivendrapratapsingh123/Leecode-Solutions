//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
  int cnt = 0;
  vector<vector<bool>>pacific;
  vector<vector<bool>>atlantic;  // these vector will work as visited 
  
  
   void dfs(int r , int c, vector<vector<int>>&mat,vector<vector<bool>>&visited,int rows,int cols)
   {
       if(visited[r][c])
       return;
       visited[r][c] = true;
       if(pacific[r][c] && atlantic[r][c])
       {
           cnt++;
       }
       
       if(r+1 < rows && mat[r+1][c] >= mat[r][c]) dfs(r+1,c,mat,visited,rows,cols);
       if(r-1 >= 0 && mat[r-1][c] >= mat[r][c] ) dfs(r-1,c,mat,visited,rows,cols);
       if(c+1 < cols && mat[r][c+1] >= mat[r][c]) dfs(r,c+1,mat,visited,rows,cols);
       if(c-1 >= 0 && mat[r][c-1]  >= mat[r][c]) dfs(r,c-1,mat,visited,rows,cols);
   }
  
  
  
    int water_flow(vector<vector<int>> &mat,int rows,int cols){
       
      pacific = vector<vector<bool>>(rows,vector<bool>(cols,false));
      atlantic = vector<vector<bool>>(rows,vector<bool>(cols,false));
      // make dfs from first row and last row
      for(int col = 0;col<cols;col++)
      {
          dfs(0,col,mat,pacific,rows,cols);
          dfs(rows-1,col,mat,atlantic,rows,cols);
      }
      
       for(int row = 0;row<rows;row++)
      {
          dfs(row,0,mat,pacific,rows,cols);
          dfs(row,cols-1,mat,atlantic,rows,cols);
      }
      return cnt;
    }
};

// we will try to go from first row , first col, last row , last col 
// to all the cells in the matrix if we are able to reach any cell from both the
// oceans then that cell is the cell from where water will flow in all the directions
//we will consider any cell only first time visit if all ready visited we will ignore



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends