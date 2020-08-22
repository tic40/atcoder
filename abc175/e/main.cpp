#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i, n) for(int i=0;i<n;i++)
#define YES(x) cout<<(x?"YES":"NO")<<"\n"
#define Yes(x) cout<<(x?"Yes":"No")<<"\n"
#define dump(x) cout<<#x<<" = "<<(x)<<"\n"
#define endl "\n"
using G = vector<vector<int>>;
using M = map<int,int>;
using P = pair<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int,vector<int>,greater<int>>;
using V = vector<int>;
using ll = long long;
using edge = struct { int to; int cost; };
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

const int MX = 3010;
ll dp[MX][MX][4]; // [行][列][行で拾ったitemの個数]
ll items[MX][MX];

void solver(
  int R, int C, int K,
  vector<int> r, vector<int> c, vector<int> v
) {

  REP(i,K) items[ r[i]-1 ][ c[i]-1 ] = v[i];

  REP(i,R+1) REP(j,C+1) REP(k,4) dp[i][j][k] = -LINF;
  dp[0][0][0] = 0;

  REP(i,R) REP(j,C) {
    for (int k = 2; k >= 0; k--) {
      if (dp[i][j][k] < 0) continue;

      dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k] + items[i][j]);
    }

    REP(k,4) {
      if (dp[i][j][k] < 0) continue;

      dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][k]);
      dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]);
    }
  }

  ll ans = -LINF;
  REP(k,4) chmax(ans, dp[R-1][C-1][k]);
  COUT(ans);
  return;
}

int main() {
  IOS;

  int R,C,K;
  cin >> R >> C >> K;
  vector<int> r(K),c(K),v(K);
  REP(i,K) cin >> r[i] >> c[i] >> v[i];

  solver(R,C,K,r,c,v);

  return 0;
}