#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n,m,x;
  cin >> n >> m >> x;
  vector<vector<int>> g(n);
  vector<bool> r(n); // あるると直接の友達関係 true:友達
  REP(i,m) {
    int a,b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
    if (a == x) r[b] = true;
    if (b == x) r[a] = true;
  }

  int ans = 0;
  REP(i,n) {
    if (i == x) continue;
    if (r[i]) continue;
    for(int v: g[i]) {
      if (r[v]) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}