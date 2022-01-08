#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const ll LINF = 1e18;

ll x;
int n;
vector<ll> candidates;

int getDigit(ll num) {
  int digit = 0;
  while(num!=0) { num/=10; digit++; }
  return digit;
}

void dfs(ll cur, int d, int cnt=1) {
  if (cnt == n) {
    if (x <= cur) candidates.push_back(cur);
    return;
  }

  int nx = cur%10 + d;
  if (nx < 0 || 9 < nx) return;
  dfs(cur*10+nx, d, cnt+1);
  return;
}

int main() {
  cin >> x;
  n = getDigit(x);

  for(int i = 1; i <= 9; i++) {
    REP(d,10) {
      dfs(i,d);
      dfs(i,-d);
    }
  }

  ll ans;
  ll minDiff = LINF;
  for(auto v: candidates) {
    ll diff = v-x;
    if (diff < minDiff) {
      minDiff = diff;
      ans = v;
    }
  }

  cout << ans << endl;
  return 0;
}