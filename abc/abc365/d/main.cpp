#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
template<class T> void chmax(T& a, T b) { a = max(a,b); }

map<char,int> mp = {
  {'R', 0 },
  {'P', 1 },
  {'S', 2 }
};

int main() {
  int n; string s; cin >> n >> s;

  auto f = [&](char c, int i) {
    int ci = mp[c];
    if ((ci+1)%3 == i) return 1;
    if (ci == i) return 0;
    return -1;
  };

  // dp[i][j] := i 回目で j のてを出したときの最大勝ち数
  vector dp(n+1,vector<int>(3,-1));
  REP(j,3) dp[0][j] = 0;

  REP(i,n) REP(j,3) {
    if (dp[i][j] == -1) continue;
    int res = f(s[i],j);
    if (res == -1) continue;
    REP(k,3) if (k != j) chmax(dp[i+1][k], dp[i][j]+res);
  }

  cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
  return 0;
}