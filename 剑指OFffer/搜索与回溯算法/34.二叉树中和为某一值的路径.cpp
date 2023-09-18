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
    vector<vector<int>> ans;

    void dfs(TreeNode* root, const int& target,int temp_val,vector<int>& temp_v)
    {
        if(root == nullptr)
        {
            return;
        }
        temp_v.push_back(root->val);
        temp_val+=root->val;
        if(target == temp_val && root->left == nullptr && root->right == nullptr) ans.push_back(temp_v);

        dfs(root->left, target,temp_val, temp_v);
        dfs(root->right, target,temp_val, temp_v);

        temp_val-= root->val;
        temp_v.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> temp_v;
        dfs(root, target,0, temp_v);
        return ans;
    }
};