#include <vector>
#include <iostream>

#include <map>
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
    void DeepFind(TreeNode* root,string temp,vector<string>& v)
    {
        if(root == nullptr)
        {

            return;
        }
        temp=  temp + to_string(root->val) + "->";
        if(root->left==nullptr && root->right==nullptr )
        {
            temp.erase(temp.size()-2,temp.size());
            v.push_back(temp);
            return;
        }


        
        DeepFind(root->left,temp,v);
        DeepFind(root->right,temp,v);

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s;
        DeepFind(root,s,ans);
        return ans;
    }
};