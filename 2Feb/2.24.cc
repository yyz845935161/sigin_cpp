#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <vector>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr)
        {
            return true;
        }

        if(root->left && root->left->val != root->val)
        {
            return false;
        }
        if(root->right && root->right->val != root->val)
        {
            return false;
        }
        return isUnivalTree(root->left) && isUnivalTree(root->right);

    }
};


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
    vector<int> ans;
    void PreOrder(TreeNode* root)
    {
        if(root == nullptr) return;
        ans.push_back(root->val);
    PreOrder(root->left);
    PreOrder(root->right);
    }
    

    vector<int> preorderTraversal(TreeNode* root) {
    PreOrder(root);
    return ans;

    }
};