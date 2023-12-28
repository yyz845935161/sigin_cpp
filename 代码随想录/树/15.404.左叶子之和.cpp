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
    int result ;
    void dfeSumLeft(TreeNode* root, char tag)
    {
        if(root == nullptr) return;
        if(tag == 'l' && root->left == nullptr && root->right == nullptr)result+= root->val;
        dfeSumLeft(root->left,'l');
        dfeSumLeft(root->right,'r');
    }


    int sumOfLeftLeaves(TreeNode* root) {
        dfeSumLeft(root, 'r');
        return   result ;
    }
};