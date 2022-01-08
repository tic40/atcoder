#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
template<class T>bool chmax(T &a,const T &b) {if(a<b){a=b; return 1;} return 0;}
template<class T>bool chmin(T &a,const T &b) {if(b<a){a=b; return 1;} return 0;}

int n;
ll k;
vector<ll> a;

// [i][smaller] := 上からi桁目まで決めたとき、
// j=0: ちょうど一致する
// j=1: よりも小さくなっている
// についての最大値
ll dp[51][2];

void solve() {
  memset(dp, -1, sizeof(dp)); // DP 配列を-1で初期化

  dp[0][0] = 0;
  REP(d, 50) {
    ll mask = 1LL << (50 - d - 1);
    // a で元々 d 桁目にビットが立っているものの個数
    int num = 0;
    REP(i, n) if (a[i] & mask) num++;

    // x の d 桁目を 0, 1 にしたときのコスト
    ll cost0 = mask * num;
    ll cost1 = mask * (n-num);

    // smaller -> smaller
    if (dp[d][1] != -1) {
      // 0 でも 1 でも大きい方をとってよい
      chmax(dp[d+1][1], dp[d][1] + max(cost0, cost1));
    }

    // exact -> smaller
    if (dp[d][0] != -1) {
      // k の d 桁目が 1 だったら、x の d 桁目は 0 にする
      if (k & mask) {
        chmax(dp[d+1][1], dp[d][0] + cost0);
      }
    }

    // exact -> exact(kにぴったりあわせる)
    if (dp[d][0] != -1) {
      if (k & mask) chmax(dp[d+1][0], dp[d][0] + cost1);
      else chmax(dp[d+1][0], dp[d][0] + cost0);
    }
  }

  cout << max(dp[50][0], dp[50][1]) << endl;

  return;
}

int main() {
  cin >> n >> k;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}