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

    int traversal(TreeNode* root,int &moves)
    {
        if(root == NULL)
        return 0;
       int left =  traversal(root -> left,moves);
       int right =  traversal(root -> right,moves);
       moves += abs(left)+abs(right);
       return root->val + left + right-1;
        
    }

    int distributeCoins(TreeNode* root) {
        int moves =0;
         traversal(root,moves);
         return moves;
    }
};