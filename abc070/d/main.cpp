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

ll depth[100005];
vector<edge> g[100005];

void dfs(int v, int p, ll d) {
  depth[v] = d;
  for (auto e : g[v]) {
    if (e.to == p) continue;
    dfs(e.to, v, d + e.cost);
  }
}

int main() {
  IOS;

  int n; cin >> n;
  REP(i,n-1) {
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  int q,k; cin >> q >> k;
  k--;

  dfs(k, -1, 0);

  REP(i,q) {
    int x,y;
    cin >> x >> y;
    x--; y--;
    cout << depth[x] + depth[y] << endl;
  }

  return 0;
}