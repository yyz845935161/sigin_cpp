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
    vector<string> result;
    vector<int> temp;
    void dfsPath(TreeNode* root)
    {
        if(root == nullptr) return;
        temp.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            string ans;
            for(auto e:temp)
            {
                ans+=to_string(e);
                ans+="->";
            }
            ans.pop_back();
            ans.pop_back();
            result.push_back(ans);
        }

        
        dfsPath(root->left);
        dfsPath(root->right);
        temp.pop_back();
        
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfsPath(root);
        return result;
    }
};