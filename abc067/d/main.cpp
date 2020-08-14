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

int n;
G g;

void bfs(int start, vector<int> &dist) {
  queue<int> q;
  q.push(start);

  while(!q.empty()) {
    int v = q.front(); q.pop();
    int nd = dist[v]+1;
    for (int nv: g[v]) {
      if (dist[nv] <= nd) continue;
      q.push(nv);
      dist[nv] = nd;
    }
  }

  return;
}

int main() {
  IOS;
  cin >> n;
  g.resize(n);

  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> distA(n,INF), distB(n,INF);
  distA[0] = 0; distB[n-1] = 0;
  bfs(0,distA);
  bfs(n-1,distB);

  int cnt = 0;
  REP(i,n) {
    if (distA[i] <= distB[i]) cnt++;
    else cnt--;
  }

  COUT(cnt > 0 ? "Fennec" : "Snuke");
  return 0;
}