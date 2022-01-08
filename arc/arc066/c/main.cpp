#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n; cin >> n;
  map<int, int> m;
  REP(i,n) {
    int a; cin >> a;
    m[a]++;
  }

  int ok = 1;
  REP(i,n/2) {
    int now = abs(n-(2*i+1));
    if (m[now] != 2) ok = 0;
  }

  if (n%2) ok *= m[0] == 1;
  else ok *= m[1] == 2;

  if (!ok) { cout << 0 << endl; return 0; }

  ll ans = 1;
  for(auto v: m) {
    ans *= v.second;
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}