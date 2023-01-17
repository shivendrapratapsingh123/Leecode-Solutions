// //first approach traversing all the diagonal in same direction and reversing even diagonal 
// class Solution {
// public:
//     vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
//       vector<int>ans;
//       int n = mat.size();
//       int m = mat[0].size();
//       for(int d = 0; d< m+n-1; d++)
//       {
//           vector<int>intermediate;
          
//           int r = d < m ? 0 : d-m+1;
//           int c = d < m ? d : m-1; 

//           while(r < n && c >= 0)
//           {
//               intermediate.push_back(mat[r][c]);
//               r++;
//               c--;
//           }
//           if( d%2 == 0)
//           reverse(intermediate.begin(),intermediate.end());
          
//           for( auto it : intermediate)
//           {
//               ans.push_back(it);
//           }
//       }

//       return ans; 
//     }
// };



//second approach simulating the problem statement 
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
   
      int n = mat.size();
      int m = mat[0].size();

         vector<int>ans(n*m);
        
        int r = 0;

        int row = 0; 
        int col = 0;
        int direction = 1;
        
        while(row < n && col < m)
        {
            ans[r++] = mat[row][col];

            int new_row = row + (direction == 1 ? -1 : 1);
            int new_col = col + (direction == 1 ? 1 :  -1);

            if(new_row < 0  || new_row == n || new_col < 0 || new_col == m )
            {
                if(direction == 1)
                {
                  row += (col == m-1) ? 1 : 0;
                  col += (col == m-1) ? 0 : 1;  
                }
                else
                {
                    col += (row == n-1 ) ? 1 : 0;
                    row += (row == n-1 ) ? 0 : 1;
                }
                direction = 1 - direction;
            }
            else 
            {
                row = new_row;
                col = new_col;
            }
        }
        return ans;
    }
};
