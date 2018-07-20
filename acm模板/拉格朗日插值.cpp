#include<iostream>
#include<string>
#include<vector>
using namespace std;

double Lagrange(int N,vector<double>&X,vector<double>&Y,double x);

int main(){
  char a='n';
  do{
    cout<<"�������ֵ����n��ֵ��"<<endl;
    int N;
    cin>>N;
    vector<double>X(N,0);
    vector<double>Y(N,0);
    cout<<"�������ֵ���Ӧ��ֵ������ֵ(Xi,Yi)��"<<endl;
    for(int a=0;a<N;a++){
        cin>>X[a]>>Y[a];
    }
    cout<<"������Ҫ��ֵx��ֵ��"<<endl;
    double x;
    cin>>x;
    double result=Lagrange(N,X,Y,x);
    cout<<"���������ղ�ֵ���ó������ "<<result<<endl;
    cout<<"�Ƿ�Ҫ������(y/n)��";
    cin>>a;
  }while(a=='y');
  return 0;
}

double Lagrange(int N,vector<double>&X,vector<double>&Y,double x){
  double result=0;
  for(int i=0;i<N;i++){
    double temp=Y[i];
    for(int j=0;j<N;j++){
    if(i!=j){
        temp = temp*(x-X[j]);
        temp = temp/(X[i]-X[j]);
   }
  }
  result += temp;
}
 return result;
};
