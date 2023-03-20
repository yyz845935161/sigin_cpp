#include <iostream>
using namespace std;
#include <vector>
#include <map>
enum Colour
{
    RED,
    BLACK
};

template <class K, class V>
struct RBTreeNode
{
    RBTreeNode<K, V> *_left;
    RBTreeNode<K, V> *_right;
    RBTreeNode<K, V> *_parent;
    pair<K, V> _kv;
    Colour _col;
    RBTreeNode(const pair<K,V>& kv)
    :_left(nullptr)
    ,_right(nullptr)
    ,_parent(nullptr)
    ,_kv(kv),
    _col(BLACK)
    {}

};

template <class K, class V>
class RBTree
{
    typedef RBTreeNode<K, V> Node;

public:
    RBTree()
        : _root(nullptr)
    {
    }

    bool Insert(const pair<K, V> &kv)
    {
        if (_root == nullptr)
        {
            _root = new Node(kv);
            return true;
        }
        Node *parent = nullptr;
        Node *cur = _root;
        while (cur)
        {
            if (cur->_kv.first < kv.first)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_kv.first > kv.first)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
                return false;
        }

        cur = new Node(kv);
        cur->_col = RED;
        if (parent->_kv.first < kv.first)
        {
            parent->_right = cur;
            cur->_parent = parent;
        }
        else
        {
            parent->_left = cur;
            cur->_parent = parent;
        }

        //控制平衡   //若要调整平衡，cur一定是红，paretn一定是红（为黑不用调整），gradeparent一定是黑
        while (parent && parent->_col == RED)
        {
            Node* greaterfather = parent->_parent;
            if(parent == greaterfather ->_left)
            {
                Node* uncle = greaterfather->_right;
                //1叔叔存在 且为红
                if(uncle && uncle->_col == RED)
                {
                    //变色+继续调整
                    parent->_col = uncle->_col = BLACK;
                    greaterfather->_col = RED;
                    cur = greaterfather;
                    parent = cur->_parent;
                } 
                else  //2叔叔不存在/存在为黑
                {   
                    if(cur==parent->_left) //纯粹的左边 是由情况一变过来的
                    {
                        RotateR(greaterfather);
                        parent ->_col = BLACK;
                        greaterfather->_col = RED;
                    }
                    else 
                    {//双旋
                        RotateL(parent);
                        RotateR(greaterfather);
                        cur->_col=BLACK;
                        greaterfather->_col=RED;
                    }
                    break; //旋转完一定满足黑红树的性质
                }
            }
            //插入的在右边
            else  //parent == greaterfather ->_right  
            {
                Node* uncle = greaterfather->_left;
                //1叔叔存在 且为红
                if(uncle && uncle->_col == RED)
                {
                    //变色+继续调整
                    parent->_col = uncle->_col = BLACK;
                    greaterfather->_col = RED;
                    cur = greaterfather;
                    parent = cur->_parent;
                }
                else  //2叔叔不存在/存在为黑
                {   
                    if(cur==parent->_right) //纯粹的左边 是由情况一变过来的
                    {
                        RotateL(greaterfather);
                        parent ->_col = BLACK;
                        greaterfather->_col = RED;
                    }

                    else
                    {
                        RotateR(parent);
                        RotateL(greaterfather);
                        cur->_col=BLACK;
                        greaterfather->_col=RED;
                    }
                    break; //旋转完一定满足黑红树的性质
                }
            }
            
        }

        _root->_col = BLACK; 
        
    }


    
    void InoderTree()
    {
        _InoderTree(_root);
    }

    bool IsBalacne()
    {
        if(_root && _root->_col == RED) 
        {
            cout<<"根节点不是黑色"<<endl;
            return false;
        
        }

        //最左路劲的黑色节点为基准值
        int banchmark = 0;
        Node * left = _root;
        while(left)
        {
            if(left->_col == BLACK)
            banchmark++;
            left = left->_left;
        }
        int blackNum=0;

        return _IsBalacne(_root,banchmark,blackNum);
        
    }



    bool _IsBalacne(Node *root,int banchmark,int blackNum)
    {
        
        if(root ==nullptr) 
        {
        if(banchmark!=blackNum)
        {
            cout<<"黑色节点数量不相等"<<endl;
            return false;
        }

        return true;


        }
        if(root->_col == RED && root->_parent->_col==RED) 
        {
            cout<<"出现连续红色"<<endl;
            return false;
        }

        if(root->_col == BLACK) ++blackNum;

        return _IsBalacne(root->_left,banchmark,blackNum)&&_IsBalacne(root->_right,banchmark,blackNum);
    }


private:
    Node *_root;
    void RotateR(Node *parent)
    {
        Node *subL = parent->_left;
        Node *subLR = subL->_right;
        parent->_left = subLR;
        if (subLR)
            subLR->_parent = parent;

        Node *parentParent = parent->_parent;
        subL->_right = parent;
        parent->_parent = subL;

        if (parent == _root)
        {
            _root = subL;
            _root->_parent = nullptr;
        }
        else
        {
            if (parentParent->_left == parent)
                parentParent->_left = subL;
            else
                parentParent->_right = subL;
            subL->_parent = parentParent;
        }
 
    }

    void RotateL(Node *parent)
    {
        Node *subR = parent->_right;
        Node *subRL = subR->_left;
        Node *parentParent = parent->_parent;

        subR->_left = parent;
        parent->_parent = subR;

        parent->_right = subRL;
        if (subRL) // 如果有又子树有左子树
            subRL->_parent = parent;

        if (parent == _root)
        {
            _root = subR;
            _root->_parent = nullptr;
        }

        else
        {
            if (parentParent->_left == parent)
                parentParent->_left = subR;
            else
                parentParent->_right = subR;
            subR->_parent = parentParent;
        }

    }

    void _InoderTree(Node *root)
    {
        if (root == nullptr)
            return;

        _InoderTree(root->_left);
        cout << root->_kv.first << " ";
        _InoderTree(root->_right);
    }
    // IsBalacne(Node *root)
};

void testBRTree()
{
    RBTree<int, int> t;
    // int a[] = {7,6,5, 4, 3, 2, 1, 0};
    int a[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};//有问题
    // int a[] = {16, 3, 7,11,9};
    // int a[] = {0,1,2,3,4,5,6,7};
    
    // int a[] = {4,2,6,1,3,5,15,7,16,14};
    for (auto e : a)
    {
        t.Insert(make_pair(e, e));
        /* code */
    } 
    t.InoderTree();
    cout <<endl << t.IsBalacne();
}


int main()
{

    testBRTree();
    return 0;
}