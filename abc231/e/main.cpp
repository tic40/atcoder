#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

ll ceil(ll x,ll y){ return x/y+!!(x%y); }

ll n,x;
vector<ll> a;
map<ll, int> memo;

ll dfs(ll now, ll idx) {
  if (x <= 0) return 0;
  if (memo[now]) return memo[now];
  if (idx == n-1) return now / a[idx];
  ll cur = a[idx];
  ll nx = a[idx+1];

  // 支払い金額を次の通貨で割ったあまり / 今の通貨で割った商
  ll r = now % nx / cur;
  ll ans = dfs( now / nx * nx, idx+1 ) + r;
  if (r) {
    ans = min(ans, dfs(ceil(now,nx) * nx, idx+1) + (nx/cur - r));
  }
  memo[now] = ans;
  return memo[now];
}

int main() {
  cin >> n >> x;
  a.resize(n);
  REP(i,n) cin >> a[i];

  cout << dfs(x, 0) << endl;
  return 0;
}