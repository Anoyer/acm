#include<bits/stdc++.h>
using namespace std;
#define MAXIMUM 13


//��С��listsize������ȫ������С˳�����prime[]�����prime[1]=2��
//ͬʱ���Ե���isprime[]����O(1)��ѯĳ�����ǲ�������������isprime(8)=0��˵��8����������
//���Ӷ�O(n)
int prime[1000000];
bool isprime[1000000];

void get_prime(int listsize)
{
    int primesize=0;
    memset(isprime,1,sizeof(isprime));
    isprime[1] = false;
    for(int i=2;i<=listsize;i++)
    {
        if(isprime[i]) prime[++primesize]=i;
        for(int j=1;i*prime[j]<=listsize&&j<=primesize;j++)
        {
            isprime[i*prime[j]] = false;
            if(i%prime[j]==0) break;
        }
    }
}

//����a�������ֽ⣬���������Ӵ�С������ڽṹ��p[].value�У���������p[].time��
struct p
{
    int value;
    int time;
}p[MAXIMUM];

void prime_factorization(int a)
{
    memset(p,0,sizeof(p));
    int psize=0;
    int n = a;
    for(int t = 1;t<=n;t++)
    {
        if(a%prime[t]==0) p[++psize].value = prime[t];
        while(a%prime[t]==0)
        {
            p[psize].time += 1;
            a = a / prime[t];
        }
        if(isprime[a])
        {
            p[++psize].value = a;
            p[psize].time += 1;
            break;
        }
        if(a==1) break;
    }
}

int power(int a,int b)
{
    int res=1;
    for(int i=1;i<=b;i++)
    {
        res *= a;
    }
    return res;
}

int d(int i)
{
    prime_factorization(i);
    int j = 1,dd=1;
    while(p[j].value!=0)
    {
        dd *= (power(p[j].value,p[j].time+1)-1)/(p[j].value-1);
        j++;
    }
    dd -= i;
    //cout << ans << endl;
    return dd;
}

int main()
{
    get_prime(10100);
    bool istrue[101000];
    int ans = 0;
    //cout << d(220) << endl;
    memset(istrue,true,sizeof(istrue));
    for(int i = 1;i<=10000;i++)
    {
        if(istrue[i]&&d(i)<=10000)
        {
            if(d(i)!=i&&i==d(d(i))) ans += d(i)+i;
            //cout << ans << endl;
            istrue[i]=0;
            istrue[d(i)]=0;
        }
    }
    //cout << d(0) << endl;
    cout << ans-1 << endl; //1�����׺���������d(1)=0,d(0)=1
}
