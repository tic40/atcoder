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

int ans[2005];
int n, x, y;

int main() {
  int n,x,y;
  cin >> n >> x >> y;
  x--; y--;
  Graph g(n);
  vector<int> ans(n+1,0);
  REP(i,n-1) {
    g[i].push_back(i+1);
    g[i+1].push_back(i);
  }
  g[x].push_back(y);
  g[y].push_back(x);

  REP(i,n) {
    vector<int> d(n, INF);
    queue<int> q;
    d[i] = 0;
    q.push(i);
    while(!q.empty()) {
      int v = q.front(); q.pop();
      for(auto nv : g[v]) {
        if (d[nv] != INF) continue;
        d[nv] = d[v]+1;
        q.push(nv);
      }
    }
    REP(j,n) if (d[j] != INF) ans[d[j]]++;
  }
  for (int i = 1; i < n; i++)  cout << ans[i]/2 << endl;
  return 0;
}