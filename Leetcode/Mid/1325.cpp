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
    int _t;
    void deepRemove(TreeNode* root)
    {
        if(root == nullptr) return;

        deepRemove(root->left);
        deepRemove(root->right);

        if(root->left != nullptr && root->left->val==_t)
        {
            if(root->left->left==nullptr && root->left->right==nullptr)
            {
                root->left = nullptr;
            }
        }
        if(root->right != nullptr && root->right->val==_t)
        {
            if(root->right->left==nullptr && root->right->right==nullptr)
            {
                root->right = nullptr;
            }
        }

    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        _t = target;
        TreeNode* head = new TreeNode();
        head->left=root;
        deepRemove(head);
        return head->left;
        
    }
};