#include<stdio.h>
#include<math.h>

int main()
{
    void hanoi(int n,char one,char two,char three);
    int m;
    printf("input the number of diskes:");
    scanf("%d",&m);
    printf("The step to move %d diskes:\n",m);
    hanoi(m,'A','B','C');
}

void hanoi(int n,char one,char two,char three)
{
    void move(char x,char y);
    if(n==1)
        move(one,three);
        //��nΪ1���������һ������one�������һ�����Ƶ�three����
    else
    {
        /*
        Ҫ��ɽ�n����ŵ����one���Ƶ�three����
        ���ǵ��뷨���Ƚ�n-1����ŵ�����Ƶ�two����
        �ٽ���n����ŵ���Ƶ�three����
        �ٽ�n-1�����Ѿ��Ƶ�two���ģ���ŵ���Ƶ�three����
        */
        hanoi(n-1,one,three,two);  //��n-1����ŵ�����Ƶ�two��
        move(one,three);           //����n����ŵ���Ƶ�three��
        hanoi(n-1,two,one,three);  //��n-1�����Ѿ��Ƶ�two���ģ���ŵ���Ƶ�three��

    }
}

void move(char x,char y)
{
    printf("%c->%c\n",x,y);
}
