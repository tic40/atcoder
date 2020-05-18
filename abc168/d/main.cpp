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
  int n,m; cin >> n >> m;
  Graph g(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> hist(n, -1);
  queue<int> que;
  hist[0] = 0;
  for(auto v: g[0]) {
    que.push(v);
    hist[v] = 0;
  }
  while(!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : g[v]) {
      if (hist[nv] != -1) continue;
      hist[nv] = v;
      que.push(nv);
    }
  }
  REP(i,n) {
    if (hist[i] == -1) { COUT("No"); return 0; }
  }
  COUT("Yes");
  for (int i = 1; i < n; ++i) cout << hist[i]+1 << endl;
  return 0;
}
