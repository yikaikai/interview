/*һ����1001��������ɵ����飬��Щ�������������еģ����е���������1��1000������1000��֮�䡣
���⣬��һ�����ֳ�������֮�⣬�����������ֶ�ֻ����һ�Σ��ҳ�����ظ�������
*/

#include<iostream>

using namespace std;

const int MAX_SIZE = 1005;

//��һ�ַ�����ͨ������������������λ�ã�ʹ������i�������е�λ��i��,����ҵ�����i,������i���ڶ�Ӧ��λ���ϣ��Ҷ�Ӧ��λ�����Լ�����һ������i����i���ظ����Ǹ���
int repeatNumber(int nums[],int len)        //�����±��1��ʼ
{
    int pos = 1;
    while(pos <= len)
    {
        if(nums[pos] == pos)
            ++pos;
        else
        {
            if(nums[pos] == nums[nums[pos]])
                return nums[pos];
            int temp = nums[nums[pos]];
            nums[nums[pos]] = nums[pos];
            nums[pos] = temp;
        }
    }
}

//�ڶ��ַ������������,��ΪA XOR A XOR B = B
int findX(int nums[],int len) //�����±��0��ʼ
{
    int k = nums[0];
    for(int i = 1;i < len;++i)          //k=1^2^..^1000^1^2..^1000^num,����num���ظ����Ǹ���
        k ^= nums[i]^i;
    return k;
}

