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
template<class T> void chmax(T& a, T b) { a = max(a,b); }
template<class T> void chmin(T& a, T b) { a = min(a,b); }

int main() {
  int n,s,m,l;
  cin >> n >> s >> m >> l;

  vector dp(101,vector<int>(101,INF));
  dp[0][0] = 0;
  REP(i,100) {
    REP(j,n) {
      if (dp[i][j] == INF) continue;
      chmin(dp[i+1][j], dp[i][j]);
      chmin(dp[i+1][min(n,j+6)], dp[i][j] + s);
      chmin(dp[i+1][min(n,j+8)], dp[i][j] + m);
      chmin(dp[i+1][min(n,j+12)],  dp[i][j] + l);
    }
  }

  cout << dp[100][n] << endl;
  return 0;
}