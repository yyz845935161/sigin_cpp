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

    bool _isSubStructure(TreeNode* A, TreeNode* B)
    {
        if(A == nullptr && B == nullptr)
        {
            return true;
        }
        if( B==nullptr)
        {
            return true;
        }

        if( A==nullptr)
        {
            return false;
        }

        if(A->val == B->val)
        {
            return _isSubStructure(A->left, B->left) && _isSubStructure(A->right, B->right);
        }
        else
        {
            return false;
        }

    }

    bool isSubStructure2(TreeNode* A, TreeNode* B)
    {
        if(A == nullptr)
        {
            return false;
        }
        
        return isSubStructure2(A->left, B) || isSubStructure2(A->right, B) || _isSubStructure(A, B);

    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B==nullptr) return false;

        return isSubStructure2(A, B);

    }
};