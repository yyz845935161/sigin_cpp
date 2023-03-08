#include <iostream>
using namespace std;
#include <string>
#include <stdio.h>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        int sizeTree = 1;
        q.push(root);
        vector<int> v;
        // v.push_back(root->val);
        // ans.push_back(v);
        // v.clear();

        while (!q.empty())
        {

            while (sizeTree--)
            {
                TreeNode *temp = q.front();
                q.pop();
                v.push_back(temp->val);

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            sizeTree = q.size();
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    bool Find(TreeNode* root, TreeNode* p)
    {
        if(root == nullptr) return false;
        if(root == p)
            return true;

        return Find(root->left, p) || Find(root->right, p);
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(root == p || root == q) return root;

        bool pInRight,pInleft,qInRight,qInleft;
        pInRight = Find(root->right,p);
        pInleft = !pInRight;

        qInRight = Find(root->right,q);
        qInleft = !qInRight;

        if((qInleft && pInRight) || (qInRight && pInleft))
        {
            return root;
        }
        else if(qInleft && pInleft)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(pInRight && qInRight)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
        {
            return nullptr;
        }

    }
};


void myprint(const vector<int>& v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        /* code */
        cout<<v[i]<<"  ";

    }
    cout<<endl;
    
}





int  _QuickSort(vector<int>& v,int left,int right)
{
    int keyi = right;
    while (left < right)
    {
        while(left < right && v[left] <= v[keyi])
        {
            left++;
        }
        while (left < right && v[right] >= v[keyi])
        {
            /* code */
            right--;
        }
        swap(v[left],v[right]);
        /* code */
    }
    swap(v[keyi],v[left]);
    return left;
    
}

void QuickSort(vector<int>& v,int left,int right)
{
    if(left >= right) return;

    int mid = _QuickSort(v,left,right);
    QuickSort(v,left,mid-1);
    QuickSort(v,mid+1,right);

}


void test01()
{
    vector<int> v = {5,6,7,8,9,4,1,10,2};
    myprint(v);
    QuickSort(v,0,v.size()-1);
    myprint(v);

}



int main()
{
    test01();
}