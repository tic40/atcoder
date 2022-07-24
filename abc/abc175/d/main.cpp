#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const ll LINF = numeric_limits<ll>::max();

int main() {
  int n,k; cin >> n >> k;
  vector<int> p(n),c(n);
  REP(i,n) cin >> p[i], p[i]--;
  REP(i,n) cin >> c[i];

  ll ans = -LINF;
  REP(i,n) {
    // サイクルの合計と移動数を前計算しておく
    ll cycle_sum = 0;
    int cycle_cnt = 0, now = i;
    while(1) {
      cycle_cnt++;
      cycle_sum += c[now];
      now = p[now];
      if (now == i) break;
    }

    // シミュレートする
    ll path = 0;
    int cnt = 0;
    while(1) {
      cnt++;
      path += c[p[now]];
      if (cnt > k) break;

      int num = (k - cnt) / cycle_cnt;
      ll score = path + max(0LL, cycle_sum) * num;
      ans = max(ans,score);
      now = p[now];
      if (now == i) break;
    }
  }

  cout << ans << endl;
  return 0;
}