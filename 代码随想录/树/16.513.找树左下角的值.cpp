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
    map<int,int> m;

    void dfsFindLeftDepp(TreeNode* root,int height)
    {
        if(root == nullptr) return;
        m[height] = root->val;
        dfsFindLeftDepp(root->right,height+1);
        dfsFindLeftDepp(root->left,height+1);
    }
    int findBottomLeftValue(TreeNode* root) {

        dfsFindLeftDepp(root,0);
        return (*(--m.end())).second;

    }
};