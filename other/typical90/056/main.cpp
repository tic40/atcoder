#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n,s;
vector<int> a,b;
bool dp[105][100005];

void solve() {
  dp[0][0] = true;

  REP(i,n) REP(j,s) {
    if (dp[i][j]) {
      dp[i+1][j+a[i]] = true;
      dp[i+1][j+b[i]] = true;
    }
  }

  if (!dp[n][s]) {
    cout << "Impossible" << endl;
    return;
  }

  // DP復元
  string ans;
  for (int i = n-1; 0 <= i; i--) {
    if (dp[i][s-a[i]]) {
      s -= a[i];
      ans += "A";
    } else if (dp[i][s-b[i]]) {
      s -= b[i];
      ans += "B";
    }
  }

  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> s;
  a.resize(n); b.resize(n);
  REP(i,n) cin >> a[i] >> b[i];

  solve();
  return 0;
}