
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

void ProOrder(BTNode* root)
{
    if(root == NULL){
        printf("NULL ");
        return;}

    printf("%c ", root->_data);
    PreOrder(root->left);
    PreOrder(root->right);
}





void test01()
{
    BTNode* root = CreatBinaryTree();
    OnOrder(root);
}

int main()
{
    test01();
}