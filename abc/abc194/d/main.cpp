#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n; cin >> n;
  double ans = 0;
  for(int i = 1; i < n; i++) ans += (double)n/(n-i);
  printf("%0.10f\n", ans);
  return 0;
}