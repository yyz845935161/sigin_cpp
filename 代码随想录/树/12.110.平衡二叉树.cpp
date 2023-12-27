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
    int getTreeHeigh(TreeNode* root)
    {
        if(root == nullptr) return 0;
        return max(getTreeHeigh(root->left),getTreeHeigh(root->right))+1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        if(abs(getTreeHeigh(root->left)-getTreeHeigh(root->right))>1) return false;

        return isBalanced(root->left)&&isBalanced(root->right);

    }
};