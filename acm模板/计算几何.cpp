#include<bits/stdc++.h>
using namespace std;

struct spot ///�洢�㣬Ҳ��ָ������
{
    double x;
    double y;
    double z;
};

spot cross(const spot &a,const spot &b) ///��������a������b�Ĳ��(��˳��)
{
    spot w;
    w.x = a.y*b.z-b.y*a.z;
    w.y = a.z*b.x-a.x*b.z;
    w.z = a.x*b.y-a.y*b.x;
    return w;
}

double dot(const spot &a,const spot &b) ///��������a������b�ĵ�˻�
{
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

double norm(const spot &a) ///��������a��ģ��
{
    return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}



bool intersect(spot a,spot b,spod c,spod d) ///�ж�ab�߶κ�cd�߶��Ƿ����ཻ������ཻ����1
{
    spot ab;
    spot cd;
    ///waiting...
}

int main()
{
    spot a,b;
    cin >> a.x >> a.y >> a.z;
    cin >> b.x >> b.y >> b.z;
    spot w = cross(a,b);
    //cout << w.x  << " " << w.y << " " << w.z;
    cout << dot(a,b);
    return 0;
}

