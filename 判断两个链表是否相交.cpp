/*---------------------------------
    �ж����������Ƿ��ཻ
-----------------------------------
***�����������������ͷָ�룬����h1,h2���ж������������Ƿ��ཻ
*/

#include<iostream>

using namespace std;
struct Node{
    int data;
    Node *next;
};

/*--------------------------
    ���һ�����������������
  --------------------------
*/
bool isJoinedSimple(Node *h1,Node *h2)
{
    if(h1 == NULL || h1 == NULL)
        return false;
    Node *temp1 = h1;
    for(;temp1->next != NULL; temp1 = temp1->next);

    Node *temp2 = h2;
    for(;temp2->next != NULL; temp2 = temp2->next);

    return temp1 == temp2;
}

//test


/*----------------------
    ���������������л�
  ----------------------
*/

//�ж������Ƿ��л�
Node* testCycle(Node *hPtr)
{
    Node *h1 = hPtr;
    Node *h2 = hPtr;

    while(h2 !=NULL && h2->next != NULL)   //h2ÿ����������h1ÿ����һ������û����h2���ȵ���β�����л���h2��ת����׷��h1
    {
        h1 = h1->next;
        h2 = h2->next->next;

        if(h1 == h2)
            return h1;
    }
    return NULL;
}

bool isJoined(Node *h1,Node *h2)
{
    Node *cylic1 = testCycle(h1);
    Node *cylic2 = testCycle(h2);

    if(cylic1 == NULL && cylic2 == NULL)   //������û��
        return isJoinedSimple(h1,h2);
    if(cylic1 != NULL && cylic2 != NULL)    //�������л�
    {
        Node *p = cylic1;
        while(1)
        {
            if(p == cylic2 || p->next == cylic2)    return true;
            p = p->next->next;
            cylic1 = cylic1->next;
            if(p == cylic1)    return false;
        }
    }
    else       //һ���л�һ��û�����ز��ཻ
        return false;
}

