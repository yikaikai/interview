/*--------------------
    ��1+2+3+...+n
  --------------------
    ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ����Լ������ж���䣨A?B:C����
*/

#include<iostream>

using namespace std;

template<int N>
struct CalCls
{
    enum {sum = CalCls<N-1>::sum + N};
};

template<>
struct CalCls<0>
{
    enum {sum = 0};
};


int main()
{
    const int n=10;
    cout<<CalCls<n>::sum<<endl;
    return 0;
}

