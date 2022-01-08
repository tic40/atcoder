#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int n;
ll x;
vector<vector<ll>> a;
int ans;

void dfs(int p, ll cur) {
  if (x < cur) return;
  if (p == n) {
    if (cur == x) ans++;
    return;
  }

  for(ll v: a[p]) {
    if (x/v < cur) continue;
    dfs(p+1, cur*v);
  }
  return;
}

int main() {
  cin >> n >> x;
  a.resize(n);
  REP(i,n) {
    int l; cin >> l;
    REP(j,l) {
      ll x; cin >> x;
      a[i].push_back(x);
    }
  }

  dfs(0,1);
  cout << ans << endl;
  return 0;
}