#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; ll x; cin >> n >> x;
  vector g(n,vector<int>());
  REP(i,n) {
    int l; cin >> l;
    REP(j,l) {
      int a; cin >> a;
      g[i].push_back(a);
    }
  }

  auto dfs = [&](auto self, int i, ll tot) -> int {
    if (tot > x) return 0;
    if (i == n) return tot == x ? 1 : 0;
    int res = 0;
    for(auto v: g[i]) res += self(self,i+1,tot*v);
    return res;
  };

  cout << dfs(dfs,0,1) << endl;
  return 0;
}