#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

int main() {
  int n,d; cin >> n >> d;
  const int M = 1e6+5;
  vector<int> cnt(M);
  REP(i,n) { int a; cin >> a; cnt[a]++; }

  auto solve = [](vector<int>& cnt) {
    int n = cnt.size();
    // dp[i][j] := i まで決めて、末尾が j であるとき削除した数
    // j: 0: 削除しない, 1: 削除する
    vector dp(n+1,vector<int>(2,INF));
    dp[0][0] = dp[0][1] = 0;
    REP(i,n) {
      // 削除しない遷移. 連続して削除しないことはできないたいめ、削除する状態からの遷移のみ
      dp[i+1][0] = dp[i][1];
      // 削除する遷移. 削除しない/するどちらからも遷移可能
      dp[i+1][1] = min(dp[i][0],dp[i][1]) + cnt[i];
    }
    return min(dp[n][0],dp[n][1]);
  };

  int ans = 0;
  if (d == 0) {
    REP(i,M) if (cnt[i] > 0) ans += cnt[i]-1;
  } else {
    REP(i,d) {
      vector<int> a;
      for(int j = i; j < M; j += d) a.push_back(cnt[j]);
      ans += solve(a);
    }
  }

  cout << ans << endl;
  return 0;
}