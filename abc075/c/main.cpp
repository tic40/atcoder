#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x)  cout << #x << " = " << (x) << endl;
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
  int n,m; cin >> n >> m;
  Graph g(n);
  vector<P> p(m);
  int a, b;
  REP(i,m) {
    cin >> a >> b; a--; b--;
    p[i] = {a, b};
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int ans = 0;
  REP(i,m) {
    queue<int> q;
    vector<int> visited(n, 0);
    const auto push = [&](int next){
      if (visited[next]) return;
      q.push(next); visited[next] = 1;
    };
    push(0);
    while(!q.empty()) {
      int v = q.front(); q.pop();
      for(auto nv : g[v]) {
        if (make_pair(v,nv) == p[i] || make_pair(nv,v) == p[i]) continue;
        push(nv);
      }
    }
    int add = false;
    REP(j,n) if (!visited[j]) add = true;
    if (add) ans++;
  }
  cout << ans << endl;
  return 0;
}