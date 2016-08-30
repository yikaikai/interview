/*----------------------------
    ����Ԫ������ת��Ϊ���ľ���
  ----------------------------
  ����ת����Ķ�Ԫ�������У��������Ľڵ㶼�����������Ľڵ�
  �õݹ��ѭ�����ַ���������ľ���ת����
*/
#include<iostream>
#include<stack>
using namespace std;

struct BSTNode{
    int data;
    BSTNode *left;
    BSTNode *right;
};

/*---------------------------
    �ݹ鷽ʽʵ��
  ---------------------------
*/
BSTNode* mirrorRecursion(BSTNode *root)
{
    if(root == NULL)
        return NULL;

    Node *lptr = mirrorRecursion(root->left);
    Node *rptr = mirrorRecursion(root->right);

    root->left = rptr;
    root->right = lptr;

    return root;
}

/*---------------------------------
    ѭ����ʽʵ��
  ---------------------------------
*/
void swap(BSTNode **l,BSTNode **r)
{
    BSTNode *temp = *l;
    *l = *r;
    *r = temp;
}

BSTNode* mirrorNoRecursion(BSTNode *root)
{
    stack<BSTNode*> S;
    S.push(root);
    while(!S.empty())
    {
        BSTNode *top = S.top();
        S.pop();
        if(top != NULL)
        {
            swap(&(top->left),&(top->right));
            S.push(top->left);
            S.push(top->right);
        }
    }

    return root;
}
