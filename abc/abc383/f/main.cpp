#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
template<class T> void chmax(T& a, T b) { a = max(a,b); }

int main() {
  int n,x,k; cin >> n >> x >> k;
  vector items(n,vector<P>());
  REP(i,n) {
    int p,u,c; cin >> p >> u >> c; c--;
    items[c].emplace_back(p,u);
  }

  // dp[i][j] := 使った金額が i, 今見ている商品を買った ? j = 1 : j = 0 のときの最大満足度
  vector dp(x+1,vector<ll>(2));
  for(auto item: items) {
    // 色が変わったらリセット
    REP(i,x+1) {
      chmax(dp[i][0],dp[i][1]);
      dp[i][1] = 0;
    }

    for(auto [p,u]: item) {
      vector old(x+1,vector<ll>(2));
      swap(dp,old);
      REP(i,x+1) {
        REP(j,2) chmax(dp[i][j],old[i][j]);
        int ni = i + p;
        if (ni > x) continue;
        chmax(dp[ni][1],old[i][0]+k+u);
        chmax(dp[ni][1],old[i][1]+u);
      }
    }
  }

  ll ans = 0;
  REP(i,x+1) ans = max({ans,dp[i][0],dp[i][1]});
  cout << ans << endl;
  return 0;
}