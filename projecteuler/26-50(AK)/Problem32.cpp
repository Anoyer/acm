#include<bits/stdc++.h>
using namespace std;

int mul1;
int mul2;
int res;
int ans[20];
int tot = 0;
//memset(ans,0,sizeof(ans));
bool istrue = 1;
int anss = 0;

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
        /*
        for (int i = 0; i < n; ++i) //��ӡ���
            printf("%d ",list[i]);
        printf("\n");
        */
        mul1 = list[8]*10+list[7];
        mul2 = list[6]*100+list[5]*10+list[4];
        res = list[0]*1000+list[1]*100+list[2]*10+list[3];
        if(mul1*mul2==res) {
                for(int i = 0;i<=tot;i++)
                {
                    if(res == ans[i]) istrue = 0;
                }
                if(istrue)
                {ans[tot] = res; tot++;}
                istrue = 1;
        }
        mul1 = list[8];
        mul2 = list[7]*1000+list[6]*100+list[5]*10+list[4];
        res = list[0]*1000+list[1]*100+list[2]*10+list[3];
        if(mul1*mul2==res)
        {
            for(int i = 0;i<=tot;i++)
            {
                if(res == ans[i]) istrue = 0;
            }
            if(istrue)
            {
                ans[tot] = res; tot++;
            }
            istrue = 1;
        }

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
    int list[] = {1,2,3,4,5,6,7,8,9};
    Prim(list,9);
    for(int i=0;i<=tot;i++)
        anss += ans[i];
    cout << anss << endl;
    return 0;
}
