#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

int main() {
  int n; ll k;
  cin >> n >> k;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  // dp[i][j] := 上からi桁目までを決めたとき、
  // j=0: k未満であることが確定
  // j=1: 今のところkと一致している
  // ときの最大値
  vector<ll> dp(2,-1);
  dp[1] = 0;

  REP(i,41) {
    vector<ll> p(2,-1);
    swap(dp,p);

    ll mask = 1LL << (40 - i);
    int bitcnt = 0;
    REP(j,n) if (a[j] & mask) bitcnt++;

    ll cost0 = mask * bitcnt;
    ll cost1 = mask * (n - bitcnt);

    if (p[0] != -1) {
      chmax(dp[0], p[0] + max(cost0, cost1));
    }

    if (p[1] != -1) {
      if (k & mask) {
        chmax(dp[0], p[1] + cost0);
        chmax(dp[1], p[1] + cost1);
      } else {
        chmax(dp[1], p[1] + cost0);
      }
    }
  }

  cout << max(dp[0],dp[1]) << endl;
  return 0;
}