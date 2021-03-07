#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int h,w,k;
vector<string> s;

void solve() {
  int ans[h][w];
  int now = 1;
  REP(i,h) REP(j,w) {
    if (s[i][j] == '.') ans[i][j] = 0;
    else { ans[i][j] = now; now++; }
  }

  REP(i,h) REP(j,w) {
    now = ans[i][j];
    if (now == 0) continue;

    REP(l,w) {
      if (l <= j) {
        if (ans[i][l] == 0) ans[i][l] = now;
      } else {
        if (ans[i][l] == 0) ans[i][l] = now;
        else break;
      }
    }
  }

  REP(i,h-1) REP(j,w) {
    if (ans[i+1][j] == 0) ans[i+1][j] = ans[i][j];
  }
  for (int i = h-1; 0 < i; i--) REP(j,w) {
    if (ans[i-1][j] == 0) ans[i-1][j] = ans[i][j];
  }

  REP(i,h) {
    REP(j,w) cout << ans[i][j] << " ";
    cout << endl;
  }
  return;
}

int main() {
  cin >> h >> w >> k;
  s.resize(h);
  REP(i,h) cin >> s[i];

  solve();
  return 0;
}