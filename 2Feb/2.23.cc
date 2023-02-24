
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
    BTDataType _data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BTNode;

BTNode *BuyNode(BTDataType x)
{

    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    node->_data = x;
    node->left = node->right = NULL;
    return node;
}

BTNode *CreatBinaryTree()
{
    BTNode *nodeA = BuyNode('A');
    BTNode *nodeB = BuyNode('B');
    BTNode *nodeC = BuyNode('C');
    BTNode *nodeD = BuyNode('D');
    BTNode *nodeE = BuyNode('E');
    BTNode *nodeF = BuyNode('F');

    nodeA->left = nodeB;
    nodeA->right = nodeC;
    nodeB->left = nodeD;
    nodeC->left = nodeE;
    nodeC->right = nodeF;
    return nodeA;
}


void PreOrder(BTNode* root)
{
    if(root == NULL){
        printf("NULL ");
        return;}

    printf("%c ", root->_data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void OnOrder(BTNode* root)
{
    if(root == NULL){
        printf("NULL ");
        return;}

    OnOrder(root->left);
    printf("%c ", root->_data);
    OnOrder(root->right);
}

void PostOrder(BTNode* root)
{
    if(root == NULL){
        printf("NULL ");
        return;}

    
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c ", root->_data);
}


/*
void BinaryTreeSize(BTNode* root,int* count)
{
    if(root == NULL){
        return;}
    (*count)++;
    printf("%c ", root->_data);
    BinaryTreeSize(root->left,count);
    BinaryTreeSize(root->right,count);
}
*/


//二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
    return root == NULL?0:BinaryTreeSize(root->left)+BinaryTreeSize(root->right)+1;
}


//二叉树叶子节点个数
int BinarTreeLeafSize(BTNode* root)
{
    if(root == NULL) return 0;


    return (root->left==NULL && root ->right==NULL)?1:BinarTreeLeafSize(root->left)+BinarTreeLeafSize(root->right);
}


//二叉树第k层的节点
int BinarTreelevelKSize(BTNode* root,int k)
{
    if(root == NULL || k <1) return 0;


    return (1 == k)?1:BinarTreelevelKSize(root->left,k-1)+BinarTreelevelKSize(root->right,k-1);
}


int max(const int a,const int b)
{
    return a>b?a:b;
}


//二叉树深度/高度
int BinarTreeDepth(BTNode* root)
{
    if(root == NULL) return 0;


    return max(BinarTreeDepth(root->left),BinarTreeDepth(root->right))+1;
}


BTNode* BinarTreeFind(BTNode* root,BTDataType x)
{
    if(root==NULL) return NULL;
    if(root->_data == x)
    {
        return root;
    }

    BTNode* ans_left = BinarTreeFind(root->left,x);
    if(ans_left) return ans_left;
    
    BTNode* ans_right =  BinarTreeFind(root->right,x);
    if(ans_right) return ans_right;

    
    return NULL;

}



void test01()
{
    BTNode* root = CreatBinaryTree();
    OnOrder(root);
    // int count=0;
    // BinaryTreeSize(root,&count);
    int count=BinaryTreeSize(root);
    printf("%d \n",count);

    int ye_count = BinarTreeLeafSize(root);
    printf("%d\n",ye_count);

    int k_count = BinarTreelevelKSize(root,3);
    printf("第k层有 %d\n",k_count);


    int deep_count = BinarTreeDepth(root);
    printf("深度 %d\n",deep_count);


    BTNode* char_tree = BinarTreeFind(root,'B');
    if ( char_tree )
    {
        printf("找到了 %c\n",char_tree->_data);
    }
    else
    {
        printf("找不到了\n");
    }
    
    

}

int main()
{
    test01();
}