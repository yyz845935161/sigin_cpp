#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <vector>
using namespace std;
#include<string>



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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p== nullptr && q==nullptr) return true;
        if(p == nullptr || q== nullptr) return false;
        if(p->val != q->val) return false;

        return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
    }
};

class Solution3 {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p== nullptr && q==nullptr) return true;
        if(p == nullptr || q== nullptr) return false;
        if(p->val != q->val) return false;

        return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;
        if(isSameTree(root, subRoot))
        {
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);


    }
};


class Solution2 {
public:

    bool isSymmetric2(TreeNode* p,TreeNode* q)
    {
        if(p== nullptr && q==nullptr) return true;
        if(p == nullptr || q== nullptr) return false;
        if(p->val != q->val) return false;
        return isSymmetric2(p->left, q->right)&&isSymmetric2(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return isSymmetric2(root->left,root->right);
    }
};



#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createTree(const string& pre_str,int& cur)
{

    if(pre_str[cur] == '#') return nullptr;
    TreeNode* root = new TreeNode();
    root->val = pre_str[cur];
    root->left = createTree(pre_str,++cur);
    root->right = createTree(pre_str,++cur);
    return root;
}


void InOrder(TreeNode* root)
{
    if(root ==nullptr)return;
    InOrder(root->left);
    cout<<root->val<<" ";
    InOrder(root->right);

}

int main() {
    string pre_str;
    cin >> pre_str;
    int cur = 0;
    TreeNode* root=  createTree(pre_str,cur);
    InOrder(root);



}
// 64 位输出请用 printf("%lld")