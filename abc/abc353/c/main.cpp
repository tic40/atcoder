#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  sort(a.begin(),a.end());

  // 二分探索
  auto solve1 = [&]() {
    ll ans = (ll)accumulate(a.begin(),a.end(),0LL) * (n-1);
    REP(i,n-1) {
      int idx = lower_bound(a.begin(),a.end(),1e8 - a[i]) - a.begin();
      idx = max(i+1,idx);
      ans -= (ll)1e8 * (n - idx);
    }
    cout << ans << endl;
  };

  // 尺取
  auto solve2 = [&]() {
    ll ans = (ll)accumulate(a.begin(),a.end(),0LL) * (n-1);
    int r = n-1;
    REP(i,n-1) {
      while(r >= 0 && a[i] + a[r] >= 1e8) r--;
      ans -= (ll)1e8 * (n - max(r,i)-1);
    }
    cout << ans << endl;
  };

  //solve1();
  solve2();
  return 0;
}