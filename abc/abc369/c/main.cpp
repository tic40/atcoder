#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<int > a(n);
  REP(i,n) cin >> a[i];

  // 尺取1
  auto solve1 = [&]() {
    ll ans = n;
    int l = 0;
    while (l < n - 1) {
      int r = l + 1;
      int d = a[r] - a[l];
      while(r < n-1) {
        if (a[r+1] - a[r] != d) break;
        r++;
      }
      // len := l から等差数列になっている最大の長さ
      int len = r - l + 1;
      // len から2つの位置を決めたときの組み合わせ数 lenC2
      if (len > 1) ans += (ll)len * (len - 1) / 2;
      l = r;
    }
    cout << ans << endl;
  };

  // 尺取2
  auto solve2 = [&]() {
    ll ans = 0;
    int r = 0;
    REP(l,n) {
      while(r < n) {
        if (r > l+1 && a[r] - a[r-1] != a[r-1] - a[r-2]) break;
        r++;
      }
      ans += r-l;
    }
    cout << ans << endl;
  };

  // ランレングス圧縮
  auto solve3 = [&]() {
    vector<P> s;
    REP(i,n-1) {
      int d = a[i+1] - a[i];
      if (s.size() && s.back().first == d) s.back().second++;
      else s.emplace_back(d,1);
    }
    ll ans = n;
    for(auto [_,v]: s) ans += (ll)v * (v+1) / 2;
    cout << ans << endl;
  };

  // solve1();
  // solve2();
  solve3();
  return 0;
}
