/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */







//考虑是那一层
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {


        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == nullptr)
        return ans;

        q.push(root);
        int i=1;
        while(!q.empty())
        {
            vector<int> v;
            for(int i=q.size();i>0;i--)
            {
                TreeNode* temp = q.front();
                q.pop();

                v.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);

            }
            ans.push_back(v);
        }
        return ans;

    }
};


//不用考虑哪一层
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {


        queue<TreeNode*> q;
        vector<int> v;
        if(root == nullptr)
        return v;
        

        q.push(root);

        while(!q.empty())
        {
            

        TreeNode* temp = q.front();
        q.pop();

        v.push_back(temp->val);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);

            
        }
        return v;

    }
};