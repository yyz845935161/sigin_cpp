#include <iostream>
using namespace std;
#include <string>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // 查找路径
    bool FindPath(TreeNode *root, TreeNode *x, stack<TreeNode *> &path)
    {
        if (root == nullptr)
            return false;
        path.push(root);
        if (root == x)
            return true;
        if (FindPath(root->left, x, path))
        {
            return true;
        }
        if (FindPath(root->right, x, path))
        {
            return true;
        }
        path.pop();
        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        
            stack<TreeNode *> pPath, qPath;
            FindPath(root, p, pPath);
            FindPath(root, q, qPath);
            while (pPath.size() != qPath.size())
            {
                if (pPath.size() > qPath.size())
                {
                    pPath.pop();
                }
                else
                    qPath.pop();
            }
            while (pPath.top() != qPath.top())
            {
                pPath.pop();
                qPath.pop();
            }
            return pPath.top();
        }
    
};