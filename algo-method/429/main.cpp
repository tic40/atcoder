#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int l,r;
vector<ll> m;

void dfs(ll cur){
  if (r < cur) return;
  if (l <= cur) m.push_back(cur);

  for(int i = cur%10; i < 10; i++) {
    ll nv = cur*10+i;
    if (nv == 0) continue;
    dfs(nv);
  }
  return;
}

int main() {
  cin >> l >> r;
  dfs(0);

  ll ans = 0;
  for(int v: m) ans+=v;
  cout << ans << endl;
  return 0;
}