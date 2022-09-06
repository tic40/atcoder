#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();

int main() {
  string s,t; cin >> s >> t;
  string ss = s+s;

  // dp[i][j] := i番目から最も近いj(アルファベットのidx)の値
  vector dp(ss.size()+1, vector<int>(26,INF));

  for(int i = ss.size()-1; 0 <= i; i--) {
    REP(j,26) dp[i][j] = dp[i+1][j];
    dp[i][ss[i]-'a'] = i+1;
  }

  ll now = 0;
  for(char c: t) {
    int x = dp[ now%s.size() ][ c-'a' ];
    if (x == INF) { cout << -1 << endl; return 0; }

    now += x - now%s.size();
  }

  cout << now << endl;
  return 0;
}