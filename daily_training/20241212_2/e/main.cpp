#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<double> a(n),b(n);
  REP(i,n) cin >> a[i] >> b[i];

  double remain_time = 0.0;
  REP(i,n) remain_time += a[i]/b[i];
  remain_time /= 2.0;

  double dist = 0.0;
  REP(i,n) {
    if (remain_time < 0) break;
    dist += b[i] * min(remain_time, a[i]/b[i]);
    remain_time -= a[i]/b[i];
  }
  printf("%.10f\n",dist);
  return 0;
}