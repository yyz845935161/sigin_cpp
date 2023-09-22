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

    void FindPath(TreeNode* root,TreeNode* x,stack<TreeNode *> &path)
    {
        if(root==nullptr)
        {
            return ;
        }
        path.push(root);

        if(root == x) return ;;

        if(root->val > x->val)
        {
            FindPath(root->left,x,path);
        }
        else
        {
            FindPath(root->right,x,path);
        }



    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pPath,qPath;
        FindPath(root, p, pPath);
        FindPath(root, q, qPath);

        while(pPath.size()!=qPath.size())
        {
            if(pPath.size()>qPath.size())
            {
                pPath.pop();
            }
            else
            {
                qPath.pop();
            }
        }

        while(pPath.top()!=qPath.top())
        {
            pPath.pop();
            qPath.pop();
        }
        return pPath.top();
    }
};