/* ͨ���ַ���ƥ��
ģʽ������'*'��'?' ͨ���ַ���
����'*'ƥ�����ⳤ�ȵ��ַ���
'?'ƥ������һ���ַ�
*/
#include<iostream>

const int MAX_SIZE = 100;
using namespace std;


bool match(char * str, char * ptn)
{
    if(*ptn == '\0') return true;
    if(*ptn == '*')           //ƥ��'*'
    {
        do
        {
            if(match(str++,ptn + 1))
                return true;
        }while(*str != '\0');
    }
    if(*str == '\0') return false;
    if(*str == *ptn || *ptn == '?')
        return match(str+1,ptn+1);
    return false;
}

int main()
{
    char str[MAX_SIZE];
    char ptn[MAX_SIZE];

    cin>>str;
    cin>>ptn;

    bool ismatch = match(str,ptn);
    if(ismatch)
        cout<<"match"<<endl;
    else
        cout<<"not match"<<endl;
    return 0;
}
