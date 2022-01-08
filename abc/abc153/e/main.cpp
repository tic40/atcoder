#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;

int h,n;
vector<int> a,b;

void solve() {
  vector<int> dp(h+1, INF);
  dp[0] = 0;

  REP(i,h+1) REP(j,n) {
    int ni = min(h, i + a[j]);
    dp[ni] = min(dp[ni], dp[i] + b[j]);
  }

  cout << dp[h] << endl;
  return;
}

int main() {
  cin >> h >> n;
  a.resize(n); b.resize(n);
  REP(i,n) cin >> a[i] >> b[i];

  solve();
  return 0;
}