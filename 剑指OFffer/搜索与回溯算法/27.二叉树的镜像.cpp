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
    void dfs(TreeNode* node)
    {
        if(node == nullptr)
        {
            return;
        }

        swap<TreeNode*>(node->left,node->right);
        dfs(node->left);
        dfs(node->right);

    }

    TreeNode* mirrorTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};