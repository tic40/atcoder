#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
template<class T>bool chmax(T &a,const T &b) {if(a<b){a=b; return 1;} return 0;}
template<class T>bool chmin(T &a,const T &b) {if(b<a){a=b; return 1;} return 0;}

int n;
ll k;
vector<ll> a;
// [i][j] := 上からi桁目まで決めたとき、
// j=0: ちょうど一致する
// j=1: よりも小さくなっている
// についての最大値
ll dp[45][2];

void solve() {
  REP(i,45) dp[i][0] = dp[i][1] = -1;
  dp[40][0] = 0;

  for(int d = 40; 0 <= d; d--) {
    ll mask = 1LL<<d;
    int num = 0;
    REP(i,n) if (a[i] & mask) num++;

    if (dp[d+1][1] >= 0) {
      chmax(dp[d][1], dp[d+1][1] + mask * max(num, n-num));
    }
    if (dp[d+1][0] >= 0) {
      if (k & mask) {
        chmax(dp[d][1], dp[d+1][0] + mask * num);
        chmax(dp[d][0], dp[d+1][0] + mask * (n-num));
      } else {
        chmax(dp[d][0], dp[d+1][0] + mask * num);
      }
    }
  }

  cout << max(dp[0][0], dp[0][1]) << endl;
  return;
}

int main() {
  cin >> n >> k;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}