#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = 1e9;
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n,m; cin >> n >> m;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  // 前後からdpする
  vector<int> d1(n,INF), dn(n,INF);
  d1[0] = 0; dn[n-1] = 0;
  REP(i,n) REP(j,m) {
    if (s[i][j] == '1') chmin(d1[i+j+1], d1[i]+1);
  }
  for(int i = n-1; i >= 0; i--) REP(j,m) {
    if (s[i][j] == '1') chmin(dn[i], dn[i+j+1]+1);
  }

  for(int v = 1; v <= n-2; v++) {
    int ans = INF;
    for (int l = v-m; l < v; l++) {
      if (l < 0) continue;
      for (int r = v+1; r <= v+m; r++) {
        if (r >= n || r-l > m) break;
        if (s[l][r-l-1] == '1') chmin(ans, d1[l]+dn[r]+1);
      }
    }

    cout << (ans == INF ? -1 : ans) << " ";
  }

  return 0;
}