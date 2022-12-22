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
//post order traversal 
  TreeNode* removeNode(TreeNode*root,vector<TreeNode*>&remaining,unordered_set<int>&toDelete)
  {
    if(root == NULL)
    return NULL;
    root -> left = removeNode(root->left,remaining,toDelete);
    root -> right = removeNode(root->right,remaining,toDelete);
    if(toDelete.find(root->val) != toDelete.end())
    {
        if(root->left)
        remaining.push_back(root->left);
        if(root->right)
        remaining.push_back(root->right);
        return NULL;
    }
    return root;
  }


    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>remaining; //stores referances to remaining node 

        unordered_set<int>toDelete; // stores nodes that are to be deleted
        for(int i = 0; i< to_delete.size();i++)
        toDelete.insert(to_delete[i]);

        removeNode(root,remaining,toDelete);
        
        if(toDelete.find(root->val) == toDelete.end())  //if root is not in the toDelete then add to
        //remaing list as we are traversing bottom up
        //  so we have to take care of the remaing nodes 
        //connected to root if that is not in the toDelete list 
        {
            remaining.push_back(root);
        }
        return remaining;
    }
};