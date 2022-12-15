/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
    unordered_map<TreeNode*, int >mp;
    
    int findMaxMoney(TreeNode* root)
    {
     if(root == NULL)
         return 0;
        if(mp[root])
            return mp[root];
        int left_max = 0;
        int right_max =0;
        if(root->left)
        {
            left_max = findMaxMoney(root->left->left) + findMaxMoney(root->left->right);
        }
        if(root->right)
        {
            right_max = findMaxMoney(root->right->left) + findMaxMoney(root->right->right); 
        }
        
        return mp[root] = max((root->val + left_max + right_max) , (findMaxMoney(root->left)+findMaxMoney(root->right)));
    }
        
        
        int rob(TreeNode *root) {
            
            return findMaxMoney(root);
        }
};