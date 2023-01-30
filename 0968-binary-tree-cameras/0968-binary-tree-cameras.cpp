/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   int cnt = 0;

// 0 -------> not being watched or is not there not 
// 1 ----------> being watched by any camera 
// 2 -------> has camera on it 

  int dfs(TreeNode* root)
  {
      if(root == NULL)
      return 0;

      int left = dfs(root-> left);
      int right = dfs(root -> right);

      if((root -> left && left == 0) ||( root -> right && right  == 0))
      {
          cnt++;
          return 2;
      }

      else if(left == 2 || right == 2)
      {
        return 1;
      }
     
      return 0;  
  }


    int minCameraCover(TreeNode* root) {
       int ans =  dfs(root);
       if(ans == 0)
       cnt++;
        return cnt ;
    }
};