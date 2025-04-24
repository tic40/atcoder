#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,x; cin >> n >> x;
  int n2 = 1<<n;
  vector<tuple<int,int,double>> ps;
  REP(i,n) {
    int s,c,p; cin >> s >> c >> p;
    ps.emplace_back(s,c,p/100.0);
  }
  // dp[i][s] := 残り i 円で解いた集合が s の状態からの期待値の最大
  vector dp(x+1,vector<double>(n2));

  REP(i,x+1) REP(s,n2) REP(j,n) if ((s>>j&1) == 0) {
    auto [score,c,p] = ps[j];
    if (c > i) continue; // cost > 現在の所持金のときは支払えないので skip
    // 失敗時
    //  dp[i-c][s] * (1-p)
    //  得点なし。解いた集合 s は変わらず。所持金は i-c へ
    // 成功時
    //  (dp[i-c][s|1<<j] + score) * p
    //  得点が入る。解いた集合は s|1<<j へ遷移、所持金は i-c へ
    double now = dp[i-c][s]*(1-p) + (dp[i-c][s|1<<j]+score)*p;
    dp[i][s] = max(dp[i][s],now);
  }

  printf("%.10f\n", dp[x][0]);
  return 0;
}