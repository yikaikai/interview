////////////////////////////////////////////////////////
//����һ������n�����1��n��n��������ʮ������1���ֵĴ���
////////////////////////////////////////////////////////

//������
//��n = ABCDE
//��E = 0ʱ����λ����1������������ABCD(0~ABCD-1),��E>=1ʱ����λ����1����������ABCD+1��0~ABCD����
//��D = 0ʱ��ʮλ����1������������ABC*10,��D = 1ʱ��ʮλ����1����������ABC*10+E+1,��D>1ʱ��ʮλ����1����������(ABC+1)*10
//������������
#include<iostream>

using namespace std;
int timesof1(int n)
{
    int prefix[10];
    int suffix[10];
    int digit[10];
    int i = 0;
    int base = 1;
    while(base < n)
    {
        suffix[i] = n % base;
        digit[i] = (n%(base*10))/base;
        prefix[i] = n/(base*10);
        ++i;
        base*=10;
    }

    base = 1;
    int count = 0;
    for(int j=0;j<i;++j,base*=10)
    {
        if(digit[j]<1)  count += prefix[j]*base;
        else if(digit[j] == 1)  count += prefix[j]*base + suffix[j] + 1;
        else    count += prefix[j]*base + base;
    }
    return count;
}

int main()
{
    cout<<timesof1(12)<<endl;
    return 0;
}
