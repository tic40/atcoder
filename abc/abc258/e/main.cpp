#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n,q,x;
  cin >> n >> q >> x;
  vector<int> w(n);
  REP(i,n) cin >> w[i];
  // 1周の合計
  ll s = accumulate(w.begin(),w.end(),0LL);
  // 何周するか
  ll rd = x/s;
  // 周回分を引いてあとどれぐらいの重さ入るか
  ll rem = x%s;

  // 何個進むかを求める. しゃくとり法で求める
  vector<ll> a(n);
  ll na = rd * n;
  REP(i,n) {
    // 入るだけ入れる
    while (0 < rem) {
      rem -= w[(i+na)%n];
      na++;
    }
    a[i] = na;
    rem += w[i];
    na--;
  }

  // doublingテーブルを前計算する
  const int D = 41;
  vector d(D,vector<int>(n));
  REP(i,n) d[0][i] = (i+a[i])%n;
  REP(i,D-1) REP(j,n) {
    d[i+1][j] = d[i][ d[i][j] ];
  }

  REP(_,q) {
    ll k; cin >> k;
    k--;
    int si = 0;
    for(int i = D-1; i >= 0; i--) {
      if (k >> i & 1) si = d[i][si];
    }
    cout << a[si] << endl;
  }

  return 0;
}