#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n; cin >> n;
  vector a(n,vector<int>(n));
  REP(i,n) {
    string s; cin >> s;
    REP(j,n) a[i][j] = s[j]-'0';
  }

  ll ans = 0;
  REP(i,n) REP(j,n) {
    for(int di = -1; di <= 1; di++) for(int dj = -1; dj <= 1; dj++) {
      if (di == 0 && dj == 0) continue;
      ll tot = 0;
      int ci = i, cj = j;
      REP(k,n) {
        tot = tot * 10 + a[ci][cj];
        ci += di;
        cj += dj;
        ci = (ci + n) % n;
        cj = (cj + n) % n;
      }
      ans = max(ans,tot);
    }
  }

  cout << ans << endl;
  return 0;
}