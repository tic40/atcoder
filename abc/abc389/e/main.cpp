#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; ll m; cin >> n >> m;
  vector<int> p(n);
  REP(i,n) cin >> p[i];

  ll tot, num; // tot := 合計金額, num := 購入個数
  // judge: c 円未満の商品をすべて買ったとき、m 円以下に収められるか
  auto judge = [&](ll c) {
    if (c <= 0) return false;

    tot = num = 0;
    REP(i,n) {
      // k := 商品 p[i] を何個買うことができるか
      // (2k-1) * p < c
      // (2k-1) * p <= c-1 // c-1 して以下に変換
      // 2k-1 <= (c-1)/p
      // 2k <= (c-1)/p + 1
      // k <= ((c-1)/p + 1) / 2
      ll k = ((c-1) / p[i] + 1) / 2;
      if (k == 0) continue;
      // オーバーフロー対策
      // k*k*p[i] > m
      // 1 > m/k/k/p[i]
      if (m/k/k/p[i] < 1) return false;
      tot += k*k*p[i];
      num += k;
      if (tot > m) return false;
    }
    return true;
  };

  ll ok = 1, ng = m+1;
  while(ng-ok>1) {
    ll mid = (ok+ng)/2;
    if (judge(mid)) ok = mid;
    else ng = mid;
  }

  judge(ok);
  // 二分探索後に残金でいくつか商品を買えるケースがある
  // 二分探索の答えが ok 円(c未満で買えるだけ買う)のとき、ok 円(c円)の品物は必ず存在する
  ll ans = num + (m-tot)/ok;
  cout << ans << endl;
  return 0;
}