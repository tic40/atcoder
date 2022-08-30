#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;

  double ans = 3.5;
  for(int i = 1; i < n; i++) {
    double now = 0;
    for(int j = 1; j <= 6; j++) now += max(double(j),ans);
    ans = now / 6.0;
  }

  printf("%0.10f\n", ans);
  return 0;
}