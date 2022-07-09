#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,m,x,t,d;
  cin >> n >> m >> x >> t >> d;

  int a = t - min(x,n)*d;
  cout << a + min(m,x) * d << endl;

  return 0;
}