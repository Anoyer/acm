#include <stdio.h>
//����list[a],list[b]
void Swap(int list[], int a, int b)
{
    int temp = 0;
    temp = list[a];
    list[a] = list[b];
    list[b] = temp;
    return;
}
//��list����[a,n]֮���������С��������
void Sort(int list[], int a, int n)
{
    int temp = 0;
    for (int i = 1; i < n-a; ++i)
        for (int j = a+1; j < n-1; ++j)
            if (list[j] > list[j+1])
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
    return;
}
//ȫ����
void Prim(int list[], int n)
{
    int num = 1, a = 0, b = 0;
    for (int i = n; i > 0; --i)     //�����ж������������ѭ�����ٴ�
        num *= i;
    while (num--)
    {
        if(num == 10*9*8*7*6*5*4*3*2 - 1000000)
        for (int i = 0; i < n; ++i) //��ӡ���
            printf("%d",list[i]);
        //printf("\n");

        for (int i = n-1; i > 0; --i) //���������ҳ���һ�����С���ұߵ�������Ϊlist[a]
            if (list[i-1] < list[i])
            {
                a = i-1;
                break;
            }
        for (int j = n-1; j > a; --j) //���������ҳ���һ������list[a]��������Ϊlist[b]
            if (list[j] > list[a])
            {
                b = j;
                break;
            }
        Swap(list, a, b);         //����list[a],list[b]
        Sort(list, a, n);         //��list[a]��������ݣ���С��������
    }
    return;
}
//������
int main()
{
    int list[] = {0,1,2,3,4,5,6,7,8,9};
    Prim(list,10);
    return 0;
}
