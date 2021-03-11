#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
int s[15][15];

void solve() {
  int ans = 0;
  for (int bit = 0; bit < (1<<n); bit++) {
    vector<int> x(n);
    REP(i,n) if ((bit >> i) & 1) x[i] = 1;

    int ok = true;
    REP(i,n) REP(j,n) {
      if (!x[i] || s[i][j] == -1) continue;
      if (s[i][j] != x[j]) ok = false; // 証言が矛盾
    }

    if (ok) {
      int cnt = 0;
      for(auto v: x) if (v) cnt++;
      ans = max(ans, cnt);
    }
  }

  cout << ans << endl;
  return;
}

int main() {
  REP(i,15) REP(j,15) s[i][j] = -1;

  cin >> n;
  REP(i,n) {
    int a; cin >> a;
    REP(j,a) {
      int x,y; cin >> x >> y;
      x--;
      s[i][x] = y;
    }
  }

  solve();
  return 0;
}