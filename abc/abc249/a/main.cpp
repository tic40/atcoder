#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int a,b,c,d,e,f,x;
  cin >>a>>b>>c>>d>>e>>f>>x;
  int la = 0,lb = 0;

  int t1 = x / (a+c);
  la += t1 * (a*b);
  int rx = x - t1*(a+c);
  la += min(a,rx) * b;

  int t2 = x / (d+f);
  lb += t2 * (d*e);
  rx = x - t2*(d+f);
  lb += min(d,rx) * e;

  if (la > lb) cout << "Takahashi";
  else if (la == lb) cout << "Draw";
  else cout << "Aoki";
  cout << endl;

  return 0;
}
