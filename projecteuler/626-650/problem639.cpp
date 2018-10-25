#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2000;
const int N = 2110000;
const int mod = 1e9+7;

ll b[maxn],c[maxn][maxn],Inv[maxn];
ll sqr,n; /// sqrΪsqrt(n)
ll w[N],id1[N],id2[N];

int tot; ///��¼����Ҫɸ��n,sqrt(n)���������ĸ���
int isp[N],p[N];
ll zh[N][52]; ///zh[i][k]��¼(p[1])^k + (p[2])^k + ... + (p[i])^k
ll g[N][52];


ll poww(ll a,int b)
{
    ll ans = 1,base = a%mod;
    while(b)
    {
        if(b&1)
        {
            ans*=base;
            ans%=mod;
        }
        base*=base;
        base%=mod;
        b>>=1;
    }
    return ans;
}


ll sigma_f(ll n,int k) ///�õ���i^k, i:1~n
{
    if(k==0) return n;
    n++;
    n%=mod;
    ll tmp = n;
    ll ans=0;
    for (int i=1;i<=k+1;i++)
    {
        ans += 1LL*c[k+1][i]*b[k+1-i]%mod*n%mod;
        ans %= mod;
        n *= tmp%mod;
        n %= mod;
    }
    ans *= Inv[k+1];
    ans %= mod;
    ans += mod;
    ans %= mod;
    return ans;
}



void get_p(int n,int w)
{
    tot = 0;
    memset(isp,1,sizeof(isp));
    isp[0] = 0;
    isp[1] = 0;
    for(int i=2;i<=n;i++)
    {
        if(isp[i])
        {
            p[++tot] = i;
            ll wait = 1;
            for(int j=0;j<=w;j++)
            {
                zh[tot][j] = zh[tot-1][j] + wait;
                zh[tot][j] %= mod;
                wait *= i;
                wait %= mod;
            }
        }

        for(int j=1;p[j]*i<=n&&j<=i;j++)
        {
            isp[i*p[j]] = 0;
            if(i%p[j]==0) break;
        }
    }
}


void get_g(ll n,int t)   ///��ÿ��x=n/i,�����[i������](i^t) (i from 1 to x)��ÿ����Ӧ��ֵ�洢��g[x][t]��
{
    int m = 0;
    ll i=1,r;
    while(i<=n)
    {
        ll len = n/i;
        r = n/len;
        if(len<=sqr) id1[len] = ++m;
        else id2[r] = ++m;
        for(int ww=0;ww<=t;ww++)
        {
            g[m][ww] = sigma_f(len,ww)-1;
            g[m][ww] %= mod;
            g[m][ww] += mod;
            g[m][ww] %= mod;
        }
        w[m] = len; ///w[i]��¼������n/k�ĵ�i���ȡֵ�Ƕ���
        i = r+1;
    }
    cout << 111111 << endl;

    for(int i=1;i<=tot;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(1LL*p[i]*p[i]>w[j]) break;
            else
            {
                int op;
                if(w[j]/p[i]<=sqr) op = id1[w[j]/p[i]];
                else op = id2[n/(w[j]/p[i])];
                for(int ww=0;ww<=t;ww++)
                {
                    g[j][ww] = g[j][ww] - poww(p[i],ww)*((g[op][ww]-zh[i-1][ww])%mod);
                    g[j][ww] %= mod;
                    g[j][ww] += mod;
                    g[j][ww] %= mod;
                }
            }
        }
    }
}

inline ll get_value(int wz,int k,int times)
{/*
    ll w = (g[wz][2] + 2*g[wz][1] - g[wz][0]) - (zh[k-1][2] + 2*zh[k-1][1] - zh[k-1][0]);
    w %= mod;
    w += mod;
    w %= mod;
    //ll w = (g[wz][1]-g[wz][0])-(zh[k-1][1]-zh[k-1][0]);
    return w; ///�Լ���дf(x)�ı��ʽ��������ʱ��
    ///����f(x) = x^2 + 2*x - 1����д(g[wz][2] + 2*g[wz][1] - g[wz][0]) - (zh[k-1][2] + 2*zh[k-1][1] - zh[k-1][0])*/
    ll w = g[wz][times] - zh[k-1][times];w %= mod;
    w += mod;
    w %= mod;
    return w;
}

ll f(ll p,ll k,int times) ///����f(p^k)����ֵ
{
    return poww(p,times);
}




ll get_s(ll x,int k,int times)
{
    if(x<=1||p[k]>x) return 0;
    int wz;
    if(x<=sqr) wz = id1[x];
    else wz = id2[n/x];
    ll ans = get_value(wz,k,times);
    //if(k==1) ans += 2;
    for(int i=k;i<=tot&&1LL*p[i]*p[i]<=x;++i)
    {
        for(ll l=p[i],e=1;l*p[i]<=x;l=l*p[i],++e)
        {
            ans = ans + (get_s(x/l,i+1,times)*f(p[i],e,times)%mod)%mod+f(p[i],e+1,times);
            ans %= mod;
        }
    }
    ans += mod;
    ans %= mod;
    return ans;

}




void init()
{
    c[0][0]=1;
    for (int i=1;i<maxn;i++)
    {
        for (int j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j]) % mod;
        c[i][0]=1;
    }
    Inv[1]=1;
    for (int i=2;i<maxn;i++) Inv[i]=1LL*Inv[mod % i] * (mod-mod/i) % mod;
    b[0]=1;
    for (int i=1;i<maxn;i++)
    {
        b[i]=0;
        for (int k=0;k<i;k++) b[i]=(b[i]+1LL*c[i+1][k]*b[k] % mod) % mod;
        b[i]=(1LL*b[i]*(-Inv[i+1]) % mod+mod)%mod;
    }
}

void solve(ll n)
{
    init();
    sqr = sqrt(n);
    cout << "gogogo!" << endl;
    get_p(sqr,50);
    cout << "step 1 is done!" << endl;
    get_g(n,50);
    cout << "step 2 is done!" << endl;
    ll ans = 0;
    for(int i=1;i<=50;i++)
    {
        ans += get_s(n,1,i)+1;
        ans %= mod;
        cout << i << " is done!" << endl;
    }
    cout << ans << endl;
}

int main()
{
    freopen("rua2.out","w",stdout);
    while(cin >> n)
    {solve(n);}
}

