//����һ��������������������е�����k���ڵ㡣����ĵ�����0���ڵ�Ϊ�����βָ��

#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};
/*---------------------
    ��һ�ַ������ݹ�
  ---------------------
*/
Node* helper(Node *p,int k,int &pos)
{
    if(p == NULL)
    {
        pos = -1;
        return NULL;
    }
    int dep;
    Node *ptr = helper(p->next,k,dep);
    if(ptr == NULL)
    {
        pos = dep + 1;
        if(pos == k)
            return p;
        return NULL;
    }

    return ptr;
}

Node* findLastKth(Node *head, int k)
{
    int pos;
    return helper(head,k,pos);
}
/*-----------------------
    �ڶ��ַ�������¼����ָ�룬��������һ��ָ���ͷָ�뿪ʼ����ƶ�k����Ȼ������ָ��ͬʱ����ƶ���
    ����һ��ָ�뵽��βָ��ʱ���ڶ���ָ��պ��ڵ�����k���ڵ㴦
*/

Node* lastKth(Node *head,int k)
{
    Node *p1 = head,*p2 = head;
    for(;k>0;--k)
    {
        if(p1->next != NULL)
            p1 = p1->next;
        else
            return NULL;
    }

    while(p1->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}

int main()
{
    Node *head = new Node;
    head->data = 0;
    head->next = NULL;
    Node *cur = head;
    for(int i=1;i<10;++i)
    {
        Node *ptr = new Node;
        ptr->data = i;
        ptr->next = NULL;
        cur->next = ptr;
        cur = ptr;
    }

    Node *result = findLastKth(head,3);
    if(result != NULL)
        cout<<result->data<<endl;
    else
        cout<<"not find"<<endl;
    return 0;
}
