#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<vector<P>> qs(n);
  REP(i,q) {
    int r,x; cin >> r >> x; r--;
    qs[r].emplace_back(i,x);
  }

  // dp[i] = 長さ i の LIS の末尾の値の min
  vector<int> dp(n,INF);
  vector<int> ans(q);
  REP(i,n) {
    int j = lower_bound(dp.begin(),dp.end(),a[i]) - dp.begin();
    dp[j] = a[i];
    for(auto [qi,x]: qs[i]) {
      ans[qi] = lower_bound(dp.begin(),dp.end(),x+1) - dp.begin();
    }
  }

  REP(i,q) cout << ans[i] << endl;
  return 0;
}