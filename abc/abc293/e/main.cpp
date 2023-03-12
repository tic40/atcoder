#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
using mint = modint;

int main() {
  int a,m; ll x;
  cin >> a >> x >> m;
  mint::set_mod(m);

  auto f = [&](auto f, ll x) -> pair<mint,mint> {
    if (x == 0) return { 0, 1 };
    auto [s,p] = f(f,x/2);
    s += s*p;
    p *= p;
    if (x % 2 == 1) { s = s*a+1; p *= a; }
    return { s, p };
  };

  mint ans = f(f,x).first;
  cout << ans.val() << endl;
}