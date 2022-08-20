#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int d,g; cin >> d >> g;
  vector<int> p(d),c(d);
  REP(i,d) cin >> p[i] >> c[i];

  int ans = 1e9;
  REP(bit, 1<<d) {
    int sum = 0, cnt = 0, li = -1;
    REP(i,d) {
      if (bit >> i & 1) {
        sum += 100 * (i+1) * p[i] + c[i];
        cnt += p[i];
      } else {
        li = i;
      }
    }

    if (sum >= g) {
      ans = min(ans, cnt);
    } else {
      int t = 100 * (li+1);
      int k = ( (g-sum) + t - 1) / t;
      if (k <= p[li]) ans = min(ans, cnt + k);
    }
  }

  cout << ans << endl;
  return 0;
}