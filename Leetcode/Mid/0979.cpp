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
    int sum=0;
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return sum;
    }


    int dfs(TreeNode* root)
    {
        if(root==nullptr) return 0;
        
        root->val += dfs(root->left);
        root->val += dfs(root->right);

        sum+= abs(root->val-1);
        return root->val-1;

    }
};