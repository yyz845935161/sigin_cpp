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
    int result;
    int count;
    void dfs(TreeNode* root)
    {
        if(root== nullptr )return ;
        if(result == root->val)
        {
            count++;
        }
        else
        {
            count--;
            if(count < 0)
            {
                result = root->val;
                count = 1;
            }
        }
        dfs(root->left);
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        result = root->val;
        count = 1;
        dfs(root->left);
        dfs(root->right);
        return {result};

    }
};