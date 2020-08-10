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

int main() {
  IOS;
  int n,m; cin >> n >> m;

  int g[n][n];
  int dp[n][n];
  REP(i,n) REP(j,n) {
    g[i][j] = 0;
    dp[i][j] = j==i ? 0 : INF;
  }

  REP(i,m) {
    int from, to, cost;
    cin >> from >> to >> cost;
    from--; to--;
    g[from][to] = cost;
    g[to][from] = cost;
    dp[from][to] = cost;
    dp[to][from] = cost; // 双方向
  }

  REP(k,n) { // 経由する頂点
    REP(i,n) { // 開始頂点
      REP(j,n) { // 終端
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }

  int ans = 0;
  REP(i,n) REP(j,n) {
    if (dp[i][j] < g[i][j]) ans++;
  }
  COUT(ans/2); // 逆方向分を/2する
  return 0;
}
