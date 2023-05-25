#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
template<class T> void chmax(T& a, T b) { a = max(a,b); }

int main() {
  int n; cin >> n;
  vector a(n,vector<int>(n));
  REP(i,n) REP(j,n) cin >> a[i][j];

  // dp[bit] := グループが決まったうさぎが bit である場合の点数の最大値
  // cst[bit] := bit のうさぎでグループを作るときの点数
  vector<ll> dp(1<<n), cst(1<<n);

  REP(bit,1<<n) {
    REP(i,n) for(int j = i+1; j < n; j++) {
      int ok = (bit&(1<<i)) && (bit&(1<<j));
      if (ok) cst[bit] += a[i][j];
    }
  }

  REP(bit, 1<<n) {
    for(int bit2 = bit; bit2 > 0; bit2 = (bit2-1) & bit) {
      ll nxt = dp[bit - bit2] + cst[bit2];
      chmax(dp[bit],nxt);
    }
  }

  cout<<dp[(1<<n)-1]<<endl;
  return 0;
}