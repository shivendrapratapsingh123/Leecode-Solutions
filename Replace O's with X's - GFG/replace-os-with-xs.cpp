//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:


 void dfs(int r, int c, int rows, int cols,vector<vector<int>>&vis,vector<vector<char>>&board)
  {
      vis[r][c] = 1;
      
      if(r+1 < rows && !vis[r+1][c] && board[r+1][c] == 'O')
      dfs(r+1,c,rows,cols,vis,board);
      if(r-1 >=0 && !vis[r-1][c] && board[r-1][c] == 'O')
      dfs(r-1,c,rows,cols,vis,board);
      if(c+1 < cols && !vis[r][c+1] && board[r][c+1] == 'O')
      dfs(r,c+1,rows,cols,vis,board);
      if(c-1 >= 0 && !vis[r][c-1] && board[r][c-1] == 'O')
      dfs(r,c-1,rows,cols,vis,board);
  }

    vector<vector<char>> fill(int rows, int cols, vector<vector<char>> board)
    {
         vector<vector<int>>vis(rows,vector<int>(cols,0));
        
        // for first row 
        for(int j = 0;j<cols;j++)
        {
            if(board[0][j] == 'O' && !vis[0][j])
            dfs(0,j,rows,cols,vis,board);
        }
        //for last row
         for(int j = 0;j<cols;j++)
        {
            if(board[rows-1][j] == 'O' && !vis[rows-1][j])
            dfs(rows-1,j,rows,cols,vis,board);
        }
        //first column
         for(int i = 0;i<rows;i++)
        {
            if(board[i][0] == 'O' && !vis[i][0])
            dfs(i,0,rows,cols,vis,board);
        }
        // last column
        for(int i = 0;i<rows;i++)
        {
            if(board[i][cols-1] == 'O' && !vis[i][cols-1])
            dfs(i,cols-1,rows,cols,vis,board);
        }
        int cnt = 0;
        for(int i = 0;i<rows;i++)
        {
            for(int j = 0;j<cols;j++)
            {
                if(!vis[i][j] && board[i][j] == 'O')
                board[i][j] = 'X';
            }
        }
        return board;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends