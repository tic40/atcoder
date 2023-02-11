#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m);
  REP(i,m) cin >> a[i];

  dsu uf(n);
  REP(i,m) uf.merge(a[i]-1,a[i]);

  auto g = uf.groups();
  for(auto v: g) {
    sort(v.rbegin(),v.rend());
    for(int x: v) cout << x+1 << " ";
  }
  return 0;
}