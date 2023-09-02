#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector d(n,vector<int>(n));
  REP(i,n-1) {
    for(int j = i+1; j < n; j++) cin >> d[i][j];
  }

  // dp[bit] := 頂点 i1,i2,i3... を端点とする辺を選んだ際の選んだ辺の重みの総和の最大値
  vector<ll> dp(1<<n,0LL);
  REP(bit,1<<n) {
    REP(i,n) for(int j = i+1; j < n; j++) {
      if ((bit & (1<<i)) || (bit & (1<<j))) continue;
      int nbit = bit | (1<<i) | (1<<j);
      dp[nbit] = max(dp[nbit], dp[bit] + d[i][j]);
    }
  }
  cout << dp[(1<<n)-1] << endl;
  return 0;
}