#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x) cout<<#x<<" = "<<(x)<<endl;
#define Yes(x) cout<<(x?"Yes":"No")<<endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int h,w; cin >> h >> w;
  string s[h]; REP(i,h) { cin >> s[i]; }

  int dp[h+1][w+1];
  REP(i,h) REP(j,w) dp[i][j] = INF;
  dp[0][0] = (s[0][0] == '.') ? 0 : 1;

  REP(i,h) {
    REP(j,w) {
      dp[i+1][j] = min(dp[i+1][j], (s[i][j] == '.' &&  s[i+1][j] == '#') ? dp[i][j]+1 : dp[i][j]);
      dp[i][j+1] = min(dp[i][j+1], (s[i][j] == '.' &&  s[i][j+1] == '#') ? dp[i][j]+1 : dp[i][j]);
    }
  }
  COUT(dp[h-1][w-1]);
  return 0;
}
