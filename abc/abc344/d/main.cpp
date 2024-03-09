#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  string t; cin >> t;
  int n; cin >> n;
  vector s(n,vector<string>());
  REP(i,n) {
    int a; cin >> a;
    REP(j,a) {
      string x; cin >> x;
      s[i].push_back(x);
    }
  }

  int ts = t.size();
  vector dp(n+1, vector<int>(ts+1,INF));
  dp[0][0] = 0;
  REP(i,n) REP(j,ts+1) {
    if (dp[i][j] == INF) continue;
    chmin(dp[i+1][j],dp[i][j]);
    REP(k,(int)s[i].size()) {
      if (s[i][k] == t.substr(j,s[i][k].size())) {
        chmin(dp[i+1][j+s[i][k].size()], dp[i][j]+1);
      }
    }
  }

  cout << (dp[n][ts] == INF ? -1 : dp[n][ts]) << endl;
  return 0;
}