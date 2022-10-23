#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> l(n),r(n);
  REP(i,n) cin >> l[i] >> r[i];

  double ans = 0;
  REP(i,n) for(int j = i+1; j < n; j++) {
    for(int k = l[i]; k <= r[i]; k++) {
      int cnt = 0;
      for(int m = l[j]; m <= r[j]; m++) if (m < k) cnt++;
      int all = (r[i]-l[i]+1) * (r[j]-l[j]+1);
      ans += (double)cnt/all;
    }
  }

  printf("%.10f\n",ans);
  return 0;
}