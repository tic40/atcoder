#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

struct Work {
  int d,c,s;
  bool operator<(const Work& o) const { return d < o.d; }
};

int main() {
  int n; cin >> n;
  vector<Work> w(n);

  REP(i,n) cin >> w[i].d >> w[i].c >> w[i].s;
  sort(w.begin(), w.end()); // 締切の昇順
  int maxd = w.back().d;

  vector<ll> dp(maxd+1, -1); // dp[i日目] = 最大の報酬
  dp[0] = 0;

  REP(i,n) {
    Work curW = w[i];
    vector<ll> p(maxd+1, -1);
    swap(p,dp);

    // pからdpへの遷移
    REP(j, curW.d+1) {
      dp[j] = p[j];
      if (0 <= j-curW.c && p[j-curW.c] != -1) {
        dp[j] = max(dp[j], p[j-curW.c] + curW.s);
      }
    }
  }

  ll ans = 0;
  REP(i,maxd+1) ans = max(ans, dp[i]);
  cout << ans << endl;
  return 0;
}