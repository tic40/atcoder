#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;

  double ans = 0;
  REP(i,n) ans += 1.0 * n / (n - i);

  printf("%.10f\n",ans);
  return 0;
}