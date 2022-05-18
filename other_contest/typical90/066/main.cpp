#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<int> l(n),r(n);
  REP(i,n) cin >> l[i] >> r[i];

  double ans = 0;
  REP(i,n) {
    for(int j = i+1; j < n; j++) {
      int cnt = 0, all = 0;
      for(int k = l[i]; k <= r[i]; k++) {
        for(int m = l[j]; m <= r[j]; m++) {
          all++;
          if (m < k) cnt++;
        }
      }
      ans += (double)cnt / all;
    }
  }

  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}