/*
    ����һ�Ŷ�Ԫ�����������°����ӡ����ÿ���ڵ㣬ͬһ�㰴�մ������ҵ�˳���ӡ
*/

#include<iostream>
#include<queue>

using namespace std;

struct BTNode{
    int data;
    BTNode *left;
    BTNode *right;
};

void printBylayer(BTNode *root)
{
    queue<BTNode*> q;
    if(root != NULL)
    {
        q.push(root);
        while(!q.empty())
        {
            BTNode *temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left != NULL)  q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
    }
}
