#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,c; ll m;
  cin >> n >> m >> c;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  map<ll,int> cnt;
  REP(i,n) cnt[a[i]]++;

  // d[k] := 座標kにいる人数
  // 2周分確保する
  vector<pair<ll,int>> d;
  for(auto p: cnt) d.emplace_back(p);
  for(auto p: cnt) d.emplace_back(p.first+m,p.second);
  int dn = cnt.size();

  // 1個前の座標
  ll px = d[dn-1].first - m;
  int r = 0, now = 0; // 何人と会ったか
  ll ans = 0;
  // 尺取法
  REP(l,dn) {
    while(now < c) {
      now += d[r].second;
      r++;
    }
    auto [x,num] = d[l];
    ans += (x-px)*now;
    px = x;
    now -= num;
  }

  cout << ans << endl;
  return 0;
}