#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // sort 解
  auto solve1 = [&]() {
    auto b = a;
    sort(b.begin(),b.end());
    vector<ll> s(n+1);
    REP(i,n) s[i+1] = s[i]+b[i];

    REP(i,n) {
      int idx = upper_bound(b.begin(),b.end(),a[i]) - b.begin();
      ll ans = s[n] - s[idx];
      cout << ans << " ";
    }
  };

  // 解説放送解
  auto solve2 = [&]() {
    const int M = 1000005;
    vector is(M,vector<int>());
    REP(i,n) is[a[i]].push_back(i);

    vector<ll> ans(n);
    ll now = 0;
    for(int x = M-1; x >= 1; x--) {
      for(int i: is[x]) ans[i] = now;
      now += (ll)x * is[x].size();
    }

    for(auto v: ans) cout << v << " ";
  };

  solve2();
  return 0;
}