#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;
int n, ng[3];

bool NG(int n) {
  REP(i, 3) if (n == ng[i]) return true;
  return false;
}

int main() {
  cin >> n;
  int dp[n+1];
  REP(i, 3) cin >> ng[i];
  REP(i, n) dp[i] = 10000;
  dp[n] = 0;

  for(int i = n; i >= 0; i--) {
    if (NG(i)) continue;
    for (int j = 1; j <= 3; j++) {
      dp[i - j] = min(dp[i] + 1, dp[i - j]);
    }
  }
  cout << (dp[0] <= 100 ? "YES" : "NO") << endl;
}