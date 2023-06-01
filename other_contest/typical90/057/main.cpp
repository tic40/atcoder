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
  vector<int> s(m);
  REP(i,n) {
    int t; cin >> t;
    REP(j,t) {
      int x; cin >> x; x--;
      a[i][x] = 1;
    }
  }
  REP(i,m) cin >> s[i];

  int pos = 0; // pos: 上から何番目まで見たか
  REP(j,m) { // i: 左から何番目まで見たか
    int found = -1;
    for(int i = pos; i < n; i++) if (a[i][j]) { found = i; break; }
    if (found == -1) continue;

    swap(a[found],a[pos]);
    for(int i = pos+1; i < n; i++) {
      if (!a[i][j]) continue;
      for(int k = j; k < m; k++) a[i][k] ^= a[pos][k];
    }
    if (s[j]) { for(int k = j; k < m; k++) s[k] ^= a[pos][k]; }
    pos++;
  }

  if (accumulate(s.begin(),s.end(),0) != 0) {
    cout << 0 << endl;
  } else {
    mint ans = 1;
    REP(i,n-pos) ans *= 2;
    cout << ans.val() << endl;
  }
  return 0;
}