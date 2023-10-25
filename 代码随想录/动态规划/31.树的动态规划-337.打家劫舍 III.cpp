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
    vector<int> robTree(TreeNode* node)
    {
        if(node == nullptr)
        {
            return {0,0};
        }

        vector<int> leftdp =  robTree(node->left);
        vector<int> rightdp =  robTree(node->right);

        int val1 = node->val + leftdp[0] + rightdp[0];
        int val2 = max(leftdp[0], leftdp[1]) + max(rightdp[0], rightdp[1]) ;

        return {val2,  val1};

    }


    int rob(TreeNode* root) {
        vector<int> ans = robTree(root);
        return max( ans[0] ,ans[1] );
    }
};