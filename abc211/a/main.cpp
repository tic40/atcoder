#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  double a,b; cin >> a >> b;
  double ans = (a - b + (3*b)) / 3;
  printf("%.10f", ans);
  return 0;
}