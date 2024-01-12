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
    int findMax(vector<int>& nums, int left, int right)
    {
        int temp = INT_MIN;
        int index = 0;
        for(int i = left; i <= right; i++)
        {
            if(nums[i] > temp)
            {
                temp = nums[i];
                index = i;
            }
        }
        return index;
    }

    TreeNode* dfConstructMaximumBinaryTree(vector<int>& nums, int left, int right)
    {
        if(left > right) return nullptr;
        int index = findMax(nums, left, right);
        TreeNode* node = new TreeNode(nums[index]);
        node->left = dfConstructMaximumBinaryTree(nums, left, index-1);
        node->right = dfConstructMaximumBinaryTree(nums, index+1, right);
        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {


        return dfConstructMaximumBinaryTree(nums, 0,nums.size()-1);

    }
};