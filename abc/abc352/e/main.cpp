#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>());
  vector<P> pa(m);
  vector a(m,vector<int>());
  REP(i,m) {
    int c,k; cin >> k >> c;
    pa[i] = {c,i};
    REP(j,k) {
      int x; cin >> x; x--;
      a[i].push_back(x);
    }
  }

  sort(pa.begin(),pa.end());
  dsu d(n);
  ll ans = 0;
  for(auto [cost,i]: pa) for(auto to: a[i]) {
    int from = a[i][0];
    if (d.same(from,to)) continue;
    d.merge(from,to);
    ans += cost;
  }

  cout << (d.size(0) == n ? ans : -1) << endl;
  return 0;
}