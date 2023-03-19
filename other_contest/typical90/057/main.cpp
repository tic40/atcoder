#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

int main() {
  int n,m; cin >> n >> m;
  vector a(n,vector<int>(m));
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
  REP(i,m) {
    bool found = false;
    for(int j = pos; j < n; j++) {
      if (!a[j][i]) continue;
      swap(a[j],a[pos]);
      found = true;
      break;
    }

    if (!found) continue;

    for(int j = pos+1; j < n; j++) {
      if (!a[j][i]) continue;
      REP(k,m) a[j][k] ^= a[pos][k];
    }

    if (s[i]) REP(j,m) s[j] ^= a[pos][j];
    pos++;
  }

  if (accumulate(s.begin(),s.end(),0) > 0) {
    cout << 0 << endl; return 0;
  }

  mint ans = 1;
  REP(i,n-pos) ans *= 2;
  cout << ans.val() << endl;
  return 0;
}