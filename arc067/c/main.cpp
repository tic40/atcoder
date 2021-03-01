#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

vector<pair<int, int>> prime_factorize(int n) {
  vector<pair<int,int>> res;
  for (int a = 2; a * a <= n; a++) {
    if (n % a != 0) continue;
    int ex = 0;
    while (n % a == 0) { ++ex; n /= a; }
    res.push_back({a, ex});
  }
  if (n != 1) res.push_back({n, 1});
  return res;
}

int main() {
  int n; cin >> n;
  map<int, int> m;
  for(int i = 1; i <= n; i++) {
    for (auto v: prime_factorize(i)) {
      m[v.first]+=v.second;
    }
  }

  ll ans = 1;
  for(auto v: m) {
    ans *= v.second+1;
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}