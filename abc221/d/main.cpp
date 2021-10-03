#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int n;
vector<int> a(200005),b(200005);

// 座標圧縮 + imos法
void solve() {
  map<int,ll> mp; // [何日目, 人数]

  REP(i,n) {
    mp[ a[i] ]++; // ログインを+1
    mp[ a[i]+b[i] ]--; // ログアウトを-1
  }

  int prev_day = 0;
  for(auto [day, count]: mp) {
    mp[day] = count + mp[prev_day];
    prev_day = day;
  }

  vector<int> ans(n+1);
  prev_day = 0;
  // ちょうどi人がログインしていた日数を集計する
  for(auto [day, _]: mp) {
    ans[mp[prev_day]] += day - prev_day;
    prev_day = day;
  }

  REP(i,n) cout << ans[i+1] << " ";
  cout << endl;
  return;
}

int main() {
  cin >> n;
  REP(i,n) cin >> a[i] >> b[i];

  solve();
  return 0;
}