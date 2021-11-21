#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 998244353;

int main() {
  ll n,k,m;
  cin >> n >> k >> m;

  if (m%MOD == 0) {
    cout << 0 << endl;
    return 0;
  }

  modint::set_mod(MOD-1);
  ll v = modint(k).pow(n).val();
  modint::set_mod(MOD);
  cout << modint(m).pow(v).val() << endl;

  return 0;
}