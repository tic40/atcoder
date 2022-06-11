#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll x,a,d,n;

// 場合分け解
ll solve1() {
  if (d < 0) {
    a = a + d * (n-1);
    d = -d;
  }

  ll l = 0, r = n-1;
  while(abs(r-l) > 1) {
    ll mid = (r+l)/2;
    if (a + d * (mid) < x) l = mid;
    else r = mid;
  }

  ll ans = abs(x - (a + d * l));
  if (l < n-1) ans = min(ans, abs(x - (a + d * (l+1) )));

  return ans;
}

// 二分探索解
ll solve2() {
  if (d < 0) {
    a = a + d * (n-1);
    d = -d;
  }

  ll l = 0, r = n-1;
  while(abs(r-l) > 1) {
    ll mid = (r+l)/2;
    if (a + d * (mid) < x) l = mid;
    else r = mid;
  }

  ll ans = abs(x - (a + d * l));
  if (l < n-1) ans = min(ans, abs(x - (a + d * (l+1) )));

  cout << ans << endl;
  return 0;
}

int main() {
  cin >> x >> a >> d >> n;
  cout << solve1() << endl;
  // cout << solve2() << endl;
  return 0;
}