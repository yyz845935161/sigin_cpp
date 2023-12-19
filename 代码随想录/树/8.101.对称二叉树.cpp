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

    bool _isSymmetric(TreeNode* node1,TreeNode* node2){
        if(node1 == nullptr && node2 == nullptr)return true;
        if(node1 == nullptr || node2 == nullptr ) return false;

        if(node1->val == node2->val) 
        {
            return _isSymmetric(node1->left,node2->right) && _isSymmetric(node1->right,node2->left);
        }
        else return false;

    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        return _isSymmetric(root->left,root->right);
    }
};