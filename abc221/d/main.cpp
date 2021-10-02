#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;

int n;
vector<ll> a,b;

// 座標圧縮 + imos法
void solve() {
  map<ll,ll> mp,tbl;

  REP(i,n) {
    mp[ a[i] ]++;
    mp[ a[i]+b[i] ]--;
  }

  ll prev = -1;
  for(auto v: mp) {
    if (prev == -1) tbl[v.first] = v.second;
    else tbl[v.first] = v.second + prev;
    prev = tbl[v.first];
  }

  vector<int> ans(n+1);
  ll prev_idx = -1, prev_value = 0;
  for(auto v: tbl) {
    if (prev_idx != -1) {
      ans[prev_value] += v.first - prev_idx;
    }
    prev_idx = v.first;
    prev_value = v.second;
  }

  // ちょうどi人がログインしていた日数を答える
  REP(i,n) cout << ans[i+1] << " ";
  cout << endl;

  return;
}

int main() {
  cin >> n;
  a.resize(n); b.resize(n);
  REP(i,n) cin >> a[i] >> b[i];

  solve();
  return 0;
}