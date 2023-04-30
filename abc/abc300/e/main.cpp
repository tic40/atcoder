#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353;

int main() {
  ll n; cin >> n;
  mint p = mint(1)/5;

  map<ll,mint> mem;
  auto dfs = [&](auto self, ll now) -> mint {
    if (now >= n) return now == n ? 1 : 0;
    if (mem.count(now)) return mem[now];
    mint res;
    for(int i = 2; i <= 6; i++) res += self(self,now*i);
    res *= p;
    return mem[now] = res;
  };

  cout << dfs(dfs,1).val() << endl;
  return 0;
}