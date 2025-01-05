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
    //   l: 先頭から 0 が続いていないか
    vector dp(10,vector(2,vector<ll>(2)));
    // 先頭桁の処理(初期値)
    dp[0][1][0] = 1;
    for(int i = 1; i < (s[0]-'0'); i++) dp[i][1][1] = 1;
    dp[s[0]-'0'][0][1] = 1;

    for(int i = 1; i < (int)s.size(); i++) {
      vector old(10,vector(2,vector<ll>(2)));
      swap(dp,old);
      int now = s[i]-'0';
      // 先頭の数 / 次の末尾の数 / 未満フラグ / nonzeroフラグ
      REP(lead,10) REP(nx,10) REP(strict,2) REP(nonzero,2) {
        if (nonzero && lead <= nx) continue;
        if (!strict && nx > now) continue;
        int nlead = lead;
        int ns = strict;
        int nn = nonzero;

        // いままで先頭が 0 で初めて先頭の数が決まるケース
        if (!nonzero && nx!=0) nlead = nx;
        // 次の末尾が s の数より小さい場合は必ず ns = 1
        if (nx < now) ns ||= 1;
        // 次の末尾が 0 でない場合は必ず nn = 1
        if (nx > 0) nn ||= 1;

        dp[nlead][ns][nn] += old[lead][strict][nonzero];
      }
    }

    ll res = 0;
    REP(i,10) REP(j,2) res += dp[i][j][1];
    return res;
  };

  cout << f(r) - f(l-1) << endl;
  return 0;
}