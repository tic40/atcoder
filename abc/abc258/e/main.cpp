#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,q,x; cin >> n >> q >> x;
  vector<int> w(n);
  REP(i,n) cin >> w[i];

  ll s = accumulate(w.begin(),w.end(),0LL);
  ll rd = x/s; // 箱をいっぱいにするのに何周するか
  ll rem = x%s; // 箱をいっぱいにする一周未満の数

  vector<int> a(n); // a[i] = i番目からスタートして箱をいっぱいにするのに何個進むか
  ll na = rd*n; // 何個進むか
  REP(i,n) {
    while(rem > 0) {
      rem -= w[ (na+i) % n];
      na++;
    }
    a[i] = na;
    rem += w[i];
    na--;
  }

  // doublingテーブル計算
  const int D = 41;
  vector dp(D, vector<int>(n));
  REP(i,n) dp[0][i] = (i + a[i]) % n;
  REP(i,D-1) REP(j,n) {
    dp[i+1][j] = dp[i][ dp[i][j] ];
  }

  REP(_,q) {
    ll k; cin >> k;
    k--;
    int si = 0;
    for(int i = D-1; i >= 0; i--) {
      if (k >> i & 1) si = dp[i][si];
    }
    cout << a[si] << endl;
  }
  return 0;
}