#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // as[k] := k 桁 の a の集合. 桁ごとに集合を持っておく
  vector<vector<int>> as(11);
  REP(i,n) as[to_string(a[i]).size()].push_back(a[i]);
  
  ll ans = 0, ten = 1;
  REP(b,11) {
    /*
      f(a[i],a[j]) = 10^k * a[i] + a[j]
      f(a[i],a[j]) % m = 0 となる組 (i,j) の個数を数える
      ⇔ (10^k * a[i] + a[j]) % m = 0
      ⇔ a[j] % m = (- 10^k * a[i]) % m
      ⇔ a[j] % m = (- 10^k * a[i] % m + m) % m
    */
    unordered_map<int,int> cnt;
    for(int na: as[b]) cnt[na%m]++;
    REP(i,n) {
      ll r = (-ten * a[i] % m + m) % m;
      ans += cnt[r];
    }
    ten *= 10; ten %= m;
  }
  cout << ans << endl;
  return 0;
}