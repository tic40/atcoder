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
using edge = struct { int to; int id; };
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

vector<vector<edge>> g;
vector<int> ans;

void dfs(int v, int c = -1, int p = -1) {
  int k = 1;
  REP(i, g[v].size()) {
    int u = g[v][i].to, ei = g[v][i].id;
    if (u == p) continue;
    if (k == c) k++;
    ans[ei] = k;
    k++;
    dfs(u, ans[ei], v);
  }
}

int main() {
  IOS;
  int n; cin >> n;
  g.resize(n);
  ans.resize(n);
  REP(i,n-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back({b, i});
    g[b].push_back({a, i});
  }

  dfs(0);

  int mx = 0;
  REP(i,n) chmax(mx, (int)g[i].size());

  COUT(mx);
  REP(i,n-1) COUT(ans[i]);
  return 0;
}
