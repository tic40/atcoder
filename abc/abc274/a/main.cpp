#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  double a,b; cin >> a >> b;
  double ans = b/a;
  ans = ans * 1000;
  ans = round(ans);
  ans /= 1000;
  printf("%.3f\n",ans);
  return 0;
}