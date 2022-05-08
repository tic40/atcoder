#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const int MOD = 998244353;

int n,m;
vector<vector<int>> a(300, vector<int>(300));
vector<int> s(300);

void solve() {
  int pos = 0;
  REP(i,m) {
    bool found = false;
    for(int j = pos; j < n; j++) {
      if (a[j][i]) {
        swap(a[j],a[pos]);
        found = true;
        break;
      }
    }
    if (found) {
      REP(j,n) {
        if (j != pos && a[j][i]) {
          for(int k = i; k < m; k++) a[j][k] ^= a[pos][k];
        }
      }
      if (s[i]) {
        for(int j = i; j < m; j++) s[j] ^= a[pos][j];
      }
      pos++;
    }
  }

  bool ok = true;
  REP(i,m) if (s[i]) ok = false;

  if (!ok) cout << 0 << endl;
  else {
    ll ans = 1;
    for(int i = pos; i < n; i++) {
      ans *= 2;
      ans %= MOD;
    }
    cout << ans << endl;
  }

  return;
}

int main() {
  cin >> n >> m;
  REP(i,n) {
    int t; cin >> t;
    REP(j,t) {
      int x; cin >> x;
      x--;
      a[i][x] = 1;
    }
  }
  REP(i,m) cin >> s[i];

  solve();
  return 0;
}