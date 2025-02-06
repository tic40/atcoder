#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

int main() {
  int n,x; cin >> n >> x;
  vector g(3,vector<P>());
  REP(i,n) {
    int v,a,c; cin >> v >> a >> c; v--;
    g[v].emplace_back(a,c);
  }

  auto dpf = [&](int v) {
    // dp[i] := 総カロリー i のときの最大のビタミン v の摂取量
    vector<int> dp(x+1);
    for(auto [a,c]: g[v]) {
      vector<int> old(x+1);
      swap(dp,old);
      REP(i,x+1) {
        dp[i] = max(dp[i],old[i]);
        if (i-c >= 0) dp[i] = max(dp[i],old[i-c]+a);
      }
    }
    return dp;
  };

  vector dp(3,vector<int>());
  REP(v,3) dp[v] = dpf(v);

  // すべてのビタミンを mid 以上接種できるか？
  auto f = [&](int mid) {
    int tot = 0;
    REP(v,3) {
      auto it =lower_bound(dp[v].begin(),dp[v].end(),mid);
      if (it == dp[v].end()) return false;
      tot += it - dp[v].begin();
    }
    return tot <= x;
  };

  int ok = 0, ng = 1e9+5;
  while(ng-ok>1) {
    int mid = (ok+ng)/2;
    if (f(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}
