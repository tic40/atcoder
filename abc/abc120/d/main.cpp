#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m),b(m);
  REP(i,m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());

  vector<ll> ans(m);
  ans[0] = (ll)n * (n-1) / 2;
  dsu uf(n);
  REP(i,m-1) {
    if (uf.same(a[i],b[i])) {
      ans[i+1] = ans[i];
    } else {
      ans[i+1] = ans[i] - uf.size(a[i]) * uf.size(b[i]);
      uf.merge(a[i],b[i]);
    }
  }

  reverse(ans.begin(),ans.end());
  for(ll v: ans) cout << v << endl;

  return 0;
}