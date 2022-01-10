#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const ll LINF = 1e18;

ll x;
int n;
ll ans = LINF;

int digit(ll n) {
  int res = 0;
  while(n) { n/=10; res++; }
  return res;
}

void dfs(ll cur, int d) {
  if (x <= cur) {
    ans = min(ans, cur);
    return;
  }

  int nx = cur%10+d;
  if (0 <= nx && nx <= 9) dfs(cur*10+nx, d);

  return;
}

int main() {
  cin >> x;
  n = digit(x);

  for(int i = 1; i <= 9; i++) REP(d,10) {
    dfs(i,d);
    dfs(i,-d);
  }
  cout << ans << endl;
  return 0;
}