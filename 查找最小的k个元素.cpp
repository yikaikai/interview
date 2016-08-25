/*�ҳ���������С��k��Ԫ��
**�����м��ַ�����
**1���ȴ�С�������򣬸���ǰk��Ԫ�أ�ʱ�临�Ӷ�ΪO(nlogn)
**2����������֪��ǰk�����ҳ������¼����Ӷ�ΪO(kn)
**3��ά��һ��k�����Ĵ󶥶ѣ����浱ǰ����������С��k��Ԫ�أ�ʱ�临�Ӷ�ΪO(n+klogn)

**�����Ҳ���ά���󶥶ѵķ���
*/
#include<iostream>

using namespace std;

const int MAX_SIZE = 100;

//����N����Ϊ�󶥶�
void HeapAdjust(int N[],int start,int end)
{
    int rc = N[start];

    for(int j = 2*start;j <= end;j*=2)      //��ֵ�ϴ�ĺ�������ɸѡ
    {
        if(j < end && N[j] < N[j+1])    ++j;       //jΪֵ�ϴ�ĺ����±�
        if(!(rc < N[j]))    break;              //rcӦ����λ��start��
        N[start] = N[j];
        start = j;
    }
    N[start] = rc;                       //����
}

int main()
{
    int len = 0;
    cout<<"Enter the number of integers:"<<endl;
    cin>>len;

    int nums[MAX_SIZE + 1];
    cout<<"Enter the integers:"<<endl;
    for(int i = 1;i <= len;++i)
        cin>>nums[i];

    int k;
    cout<<"Enter the k:"<<endl;
    cin>>k;
    if(len <= k)
    {
        for(int i = 1;i <= len;++i)
            cout<<nums[i]<<" ";
        cout<<endl;
    }
    else
    {
        for(int i = k/2;i > 0;--i)
            HeapAdjust(nums,i,k);
        for(int i = k+1;i<=len;++i)
        {
            if(nums[i] < nums[1])
            {
                nums[1] = nums[i];
                HeapAdjust(nums,1,k);
            }
        }

        for(int i = 1;i <= k;++i)
            cout<<nums[i]<<" ";
        cout<<endl;
    }

    return 0;
}


