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
    int result=INT_MAX; 
    TreeNode* pre = nullptr;
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr) return INT_MAX;
        
        if(root->left) getMinimumDifference(root->left);
        if(pre)
        {
            result = min(abs(pre->val-root->val),result);
        }
        pre = root;
        if(root->right) getMinimumDifference(root->right);  
        
        return result;
    }
};