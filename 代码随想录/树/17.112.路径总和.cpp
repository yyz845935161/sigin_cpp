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

    bool dfs(TreeNode* root,int& targetSum, int temp)
    {
        if(root == nullptr)
        {
            
            return false;
        } 

        if( !root->left && !root->right && temp+root->val == targetSum) return true;

        return dfs(root->left,targetSum, temp + root->val) || dfs(root->right,targetSum, temp + root->val) ;

    }



    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return dfs(root,targetSum, 0);

    }
};