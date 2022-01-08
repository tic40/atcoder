#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

struct Work {
  int d,c,s;
  bool operator<(const Work& w) const { return d < w.d; }
};

int main() {
  int n; cin >> n;
  vector<Work> w(n);
  REP(i,n) cin >> w[i].d >> w[i].c >> w[i].s;

  sort(w.begin(),w.end()); // 締切日の昇順
  int maxD = w.back().d;
  vector<ll> dp(maxD+1, -1); // dp[i日目] = i日目で最大の報酬

  dp[0] = 0;
  REP(i,n) {
    vector<ll> p(maxD+1, -1);
    swap(p,dp);

    auto cur = w[i];
    REP(j,cur.d+1) {
      dp[j] = p[j];
      if (0 <= j-cur.c && p[j-cur.c] != -1) {
        dp[j] = max(dp[j], p[j-cur.c] + cur.s);
      }
    }
  }

  ll ans = 0;
  for(auto v: dp) ans = max(ans, v);
  cout << ans << endl;

  return 0;
}