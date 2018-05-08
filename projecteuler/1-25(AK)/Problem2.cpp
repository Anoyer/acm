#include<bits/stdc++.h>
using namespace std;

// Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
//
// 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
//
// By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

int main()
{
  int fi[100];
  int t=1;
  fi[0]=1;
  fi[1]=2;
  int ans=0;
  while(fi[t]<=4e6)
  {
    if(fi[t]%2==0)
    ans+=fi[t];
    t++;
    fi[t]=fi[t-1]+fi[t-2];
  }
  cout << ans << endl;
}
