
struct Tree{
public:
    int val;
    Tree* childe;
    Tree* brother;
    Tree* parent;

    Tree()
    :val(0),
    childe(nullptr),
    brother(nullptr),
    parent(nullptr)
    {}

    Tree(int val,Tree* childe,Tree* brother,Tree* parent)
    :val(val),
    childe(childe),
    brother(brother),
    parent(parent)
    {}

};


class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {


        for(int i=0;i<n;i++)
        {

        }

    }
    
    int getKthAncestor(int node, int k) {

    }
    Tree* root;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */