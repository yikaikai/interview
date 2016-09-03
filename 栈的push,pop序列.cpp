/////////////////////////////////////////////////
//���������������С�����һ�����б�ʾջ��push˳��
//�ж���һ��������û�п����Ƕ�Ӧ��pop˳��
/////////////////////////////////////////////////

#include<iostream>
#include<stack>

using namespace std;

bool isPopSeries(int push[],int pop[],int len)
{
    int poppos = 0;
    int pushpos = 0;
    stack<int> S;
    while(pushpos < len || !S.empty())
    {
        if(pushpos < len)
        {
            if(push[pushpos] == pop[poppos])
                ++poppos;
            else
            {
                if(!S.empty() && S.top() == pop[poppos])
                {
                    ++poppos;
                    S.pop();
                }
                S.push(push[pushpos]);
            }
            ++pushpos;
        }
        else
        {
            if(!S.empty() && S.top() != pop[poppos])
                return false;
            S.pop();
            ++poppos;
        }
    }
    return true;
}

int main()
{
    int push[] = {1,2,3,4,5};
    int pop[]  = {2,1,4,5,3};
    cout<<isPopSeries(push,pop,5)<<endl;
    return 0;
}
