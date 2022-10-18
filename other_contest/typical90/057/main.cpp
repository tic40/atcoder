#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n,m; cin >> n >> m;
  vector a(n, vector<int>(m));
  REP(i,n) {
    int t; cin >> t;
    REP(j,t) {
      int x; cin >> x;
      x--;
      a[i][x] = 1;
    }
  }
  vector<int> s(m);
  REP(i,m) cin >> s[i];

  int pos = 0;
  REP(j,m) {
    bool found = false;
    for(int i = pos; i < n; i++) {
      if (a[i][j]) {
        found = true;
        swap(a[i],a[pos]);
        break;
      }
    }

    if (!found) continue;

    for(int i = pos+1; i < n; i++) {
      if (!a[i][j]) continue;
      for(int k = j; k < m; k++) a[i][k] ^= a[pos][k];
    }
    if (s[j]) {
      for(int k = j; k < m; k++) s[k] ^= a[pos][k];
    }
    pos++;
  }

  if (accumulate(s.begin(),s.end(),0) > 0) {
    cout << 0 << endl;
  } else {
    mint ans = 1;
    for(int i = pos; i < n; i++) ans *= 2;
    cout << ans.val() << endl;
  }
  return 0;
}