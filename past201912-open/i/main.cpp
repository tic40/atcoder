#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;

int n,m;
vector<string> s;
vector<int> c, sbit;

void solve() {
  vector<int> dp(1<<n, INF);

  dp[0] = 0;
  REP(i,m) {
    for(int j = 0; j < (1 << n); j++) {
      int nj = j | sbit[i];
      int nc = dp[j] + c[i];
      dp[nj] = min(dp[nj], nc);
    }
  }

  int ans = dp[(1<<n) - 1];
  cout << (ans == INF ? -1 : ans) << endl;
  return;
}

int main() {
  cin >> n >> m;
  s.resize(m);
  c.resize(m);
  sbit.resize(m);
  REP(i,m) cin >> s[i] >> c[i];

  // s文字列をY=1, N=0 のbitとする
  REP(i,m) REP(j,n) {
    sbit[i] <<= 1; // 1bit左シフト
    if (s[i][j] == 'Y') sbit[i]++;
  }

  solve();
  return 0;
}