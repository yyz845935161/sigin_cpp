/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
void dfs(Node* root, vector<Node*>& v)
{
    if(root == nullptr)
    return;

    dfs(root->left,v);
    v.push_back(root);
    dfs(root->right,v);

}


class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        vector<Node*> v;
        Node* head = new Node();
		dfs(root, v);
		if(!v.empty())
        	head->right = v[0];
		else
		{
			head->right = nullptr;
		}

		for(int i=1;i<v.size();i++)
		{
			v[i-1]->right = v[i];
			v[i]->left = v[i-1];
		}
		if(!v.empty())
		{
			v[v.size()-1]->right = head->right;
			head->right->left = v[v.size()-1];
			// v[v.size()-1]->right = nullptr;
			// head->right->left = nullptr;
		}
		return head->right;

        
    }
};