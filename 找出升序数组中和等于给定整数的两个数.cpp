/*����һ���Ѿ�������������������һ������
  �������в�����������ʹ�����ǵĺ�������������Ǹ�����
  Ҫ��ʱ�临�Ӷ���O(n)
  ����ж�����ֵĺ͵�����������֣��������һ�Լ���
*/

#include<iostream>
using namespace std;

bool find2Number(int a[],int len,int dest)
{
    int s = 0;
    int e = len - 1;
    while(s != e)
    {
        if(a[s] + a[e] == dest)
        {
            cout<<a[s]<<"+"<<a[e]<<"="<<dest<<endl;
            return true;
        }
        else if(a[s] + a[e] < dest)
            ++s;
        else
            --e;

    }
    return false;
}

int main()
{
    int nums[] = {1,5,8,9,10,25,36,45,52,64,78};
    bool flag = find2Number(nums,11,61);
    if(!flag)
        cout<<"not exist"<<endl;
    return 0;
}
