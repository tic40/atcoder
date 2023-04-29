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
  auto f = [&](auto f, ll now) -> mint {
    if (now == n) return 1;
    if (now > n) return 0;
    if (mem.count(now)) return mem[now];
    mint res;
    for(ll i = 2; i <= 6; i++) res += f(f, now * i);
    res *= p;
    return mem[now] = res;
  };

  cout << f(f,1).val() << endl;
  return 0;
}