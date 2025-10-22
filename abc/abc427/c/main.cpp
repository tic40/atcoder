#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  vector<P> pa;
  REP(i,m) {
    int u,v; cin >> u >> v; u--; v--;
    pa.emplace_back(u,v);
  }

  int ans = 1e9;
  REP(bit,1<<n) {
    vector<int> col(n);
    REP(i,n) col[i] = bit >> i & 1;
    int now = 0;
    for(auto [u,v]: pa) now += col[u] == col[v];
    ans = min(ans,now);
  }

  cout << ans << endl;
  return 0;
}