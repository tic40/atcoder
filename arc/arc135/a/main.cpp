#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
using mint = modint998244353;

map<ll,mint> mp;
mint dfs(ll x) {
  if (x <= 4) return (mint)x;
  if (mp.count(x)) return mp[x];

  return mp[x] = dfs(x/2) * dfs( (x+1)/2 );
}

int main() {
  ll x; cin >> x;
  cout << dfs(x).val() << endl;
  return 0;
}