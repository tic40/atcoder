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
// using M = map<int,int>;
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

int N,M,R;
vector<int> r(8);
vector<int> a(40000),b(40000),c(40000);
vector<vector<P>> g(40000);
int dp[200][200];
int ans = INF;

void warshall_floyd() {
  REP(i,N) REP(j,N) {
    dp[i][j] = j==i ? 0 : INF; // 自分自身は0
  }

  REP(i,M) {
    dp[a[i]][b[i]] = c[i];
    dp[b[i]][a[i]] = c[i];
  }

  REP(k,N) { // 経由する頂点
    REP(i,N) { // 開始頂点
      REP(j,N) { // 終端
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
}

void dfs(vector<int> v) {
  if (v.size() == R) {
    int sum = 0;
    REP(i,R-1) {
      int from = r[v[i]], to = r[v[i+1]];
      sum += dp[from][to];
    }
    chmin(ans,sum);
    return;
  }

  REP(i,R) {
    if (find(ALL(v), i) != v.end()) continue;
    vector<int> nv = v;
    nv.push_back(i);
    dfs(nv);
  }
  return;
}

int main() {
  IOS;
  cin >> N >> M >> R;
  REP(i,R) {
    cin >> r[i];
    r[i]--;
  }
  REP(i,M) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
  }

  warshall_floyd();
  dfs(vector<int>()); // 順列

  COUT(ans);

  return 0;
}