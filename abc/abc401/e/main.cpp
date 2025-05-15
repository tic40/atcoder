#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector to(n,vector<int>());
  REP(i,m) {
    int a,b; cin >> a >> b; a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  dsu uf(n);
  vector<bool> red(n);
  int cnt = 0;
  REP(v,n) {
    for(auto u: to[v]) {
      if (u < v) uf.merge(u,v);
      if (u > v) {
        if (red[u]) continue;
        red[u] = true;
        cnt++;
      }
    }
    if (red[v]) cnt--;

    int ans = -1;
    if (uf.size(v) == v+1) ans = cnt;
    cout << ans << endl;
  }
  return 0;
}