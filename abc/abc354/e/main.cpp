#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;

int main() {
  int n; cin >> n;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i] >> b[i];

  // メモ化 DFS
  auto solve1 = [&]() {
    vector<int> used(20);
    auto f = [&](int i, int j) {
      if (used[i] || used[j]) return false;
      if (a[i] == a[j]) return true;
      if (b[i] == b[j]) return true;
      return false;
    };
    map<pair<int,vector<int>>,int> memo;
    auto dfs = [&](auto self, int turn) -> int {
      if (memo.count({turn,used})) return memo[{turn, used}];
      int res = 0;
      REP(i,n) for(int j = i+1; j < n; j++) {
        if (!f(i,j)) continue;
        used[i] = 1; used[j] = 1;
        res |= self(self,turn^1) ^ 1;
        used[i] = 0; used[j] = 0;
        if (res == 1) return memo[{turn, used}] = res;
      }
      return memo[{turn, used}] = res;
    };
    cout << (dfs(dfs,0) == 1 ? "Takahashi" : "Aoki") << endl;
  };

  // DP
  auto solve2 = [&]() {
    int n2 = 1<<n;
    vector<bool> dp(n2);
    REP(s,n2) {
      bool now = false;
      REP(i,n) REP(j,i) {
        // i桁目、j桁目の bit が立っている
        if ((s>>i)&1 && (s>>j)&1) {
          if (a[i] == a[j] || b[i] == b[j]) {
            // i, j 桁目を反転させる
            if (!dp[s^(1<<i)^(1<<j)]) now = true;
          }
        }
      }
      dp[s] = now;
    }
    cout << (dp[n2-1] ? "Takahashi" : "Aoki") << endl;
  };

  // solve1(); // dfs
  solve2(); // bitDP

  return 0;
}