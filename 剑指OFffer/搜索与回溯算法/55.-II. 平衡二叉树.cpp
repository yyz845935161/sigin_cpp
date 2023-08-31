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

    int TreeDeep(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        return max(TreeDeep(root->left), TreeDeep(root->right)) +1;
    }


    bool isBalanced(TreeNode* root) 
    {
        if(root == nullptr) return true;
        // cout<<TreeDeep(root);
        if(abs(TreeDeep(root->left)-TreeDeep(root->right))>1)
        {
            return false;
        }
        else
            return isBalanced(root->left)&& isBalanced(root->right);;

    }
};