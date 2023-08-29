/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool dfs(TreeNode* n1,TreeNode* n2)
    {
        if(n1 == nullptr && n2 == nullptr) return true;
        if(n1 == nullptr || n2 == nullptr) return false;

        if(n1->val == n2->val)
        {
            return dfs(n1->left,n2->right) && dfs(n1->right,n2->left);
        }

        return false;

    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return dfs(root->left,root->right);
    }
};