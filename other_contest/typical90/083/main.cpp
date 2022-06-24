#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;
const int INF = 1e9+5;

vector<vector<int>> g;
vector<int> col;

int main() {
  int n,m; cin >> n >> m;
  g.resize(n);
  col.resize(n,1);

  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int q; cin >> q;
  vector<int> x(q),y(q);
  REP(i,q) { cin >> x[i] >> y[i]; x[i]--; }

  // 次数がb以上を大きい頂点とする
  // largeにb以上の頂点を入れておく
  int b = int(sqrt(2*m));
  vector<int> large;
  REP(i,n) {
    if ((int)g[i].size() >= b) large.push_back(i);
  }

  // link[i][j] = jからiへの辺がlargeに向かっている場合はtrue
  vector<vector<bool>> link(n,vector<bool>(large.size()));
  REP(i, (int)large.size()) {
    for(int j: g[large[i]]) link[j][i] = true;
    link[large[i]][i] = true;
  }

  vector<int> update(n,-1);
  vector<int> update_large(large.size(), -1);

  REP(i,q) {
    int last = update[x[i]];
    REP(j, (int)large.size()) {
      if (link[x[i]][j]) last = max(last, update_large[j]);
    }
    cout << (last != -1 ? y[last] : 1) << endl;

    if ((int)g[x[i]].size() < b) {
      update[x[i]] = i;
      for (int j: g[x[i]]) update[j] = i;
    } else {
      int ptr = find(large.begin(), large.end(), x[i]) - large.begin();
      update_large[ptr] = i;
    }
  }
  return 0;
}