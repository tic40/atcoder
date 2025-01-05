#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll l,r; cin >> l >> r;

  auto f = [&](ll x) {
    string s = to_string(x);
    // 桁DP
    // dp[i][j][k][l]
    //   i: i 桁目
    //   j: 0 でない最初の数字
    //   k: x より小さいことが確定しているか
    //   l: 先頭から 0 が続くかどうか
    vector dp(10,vector(2,vector<ll>(2)));
    // 先頭桁の処理(初期値)
    dp[0][1][0] = 1;
    for(int i = 1; i < (s[0]-'0'); i++) dp[i][1][1] = 1;
    dp[s[0]-'0'][0][1] = 1;

    for(int i = 1; i < (int)s.size(); i++) {
      vector old(10,vector(2,vector<ll>(2)));
      swap(dp,old);
      REP(j,10) REP(k,10) REP(strict,2) REP(nonzero,2) {
        if (nonzero && j <= k) continue;
        if (!strict && k > s[i]-'0') continue;
        int nj = (!nonzero && k != 0) ? k : j;
        int ns = strict || k < s[i]-'0';
        int nn = nonzero || k > 0;
        dp[nj][ns][nn] += old[j][strict][nonzero];
      }
    }

    ll res = 0;
    REP(i,10) REP(j,2) res += dp[i][j][1];
    return res;
  };

  cout << f(r) - f(l-1) << endl;
  return 0;
}