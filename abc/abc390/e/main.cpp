#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
template<class T> void chmax(T& x, T y) { x = max(x,y); }

int main() {
  int n,x; cin >> n >> x;
  // fodds[i][j] := ビタミン i が接種できる食べ物 j
  vector foods(3,vector<P>());
  REP(i,n) {
    int v,a,c; cin >> v >> a >> c; v--;
    foods[v].emplace_back(a,c);
  }

  vector d(3,vector<int>(x+1));
  REP(v,3) {
    vector<int> dp(x+1);
    for(auto [a,c]: foods[v]) {
      // dp[i] := 接種カロリーが i 以下のときの接種ビタミンの最大値
      vector<int> old(x+1);
      swap(dp,old);
      REP(i,x+1) {
        chmax(dp[i],old[i]);
        if (i-c >= 0) chmax(dp[i],old[i-c]+a);
      }
    }
    d[v] = dp;
  }

  // ビタミン1,2,3 から最も少ないビタミン摂取量を r 以上にできるか？
  auto f = [&](int r) {
    int tot = 0;
    REP(v,3) {
      if (d[v][x] < r) return false;
      int need = lower_bound(d[v].begin(),d[v].end(),r) - d[v].begin();
      tot += need;
    }
    return tot <= x;
  };

  int ok = 0, ng = 1e9+5;
  while(ng-ok > 1) {
    int mid = (ok+ng)/2;
    if (f(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
  return 0;
}
