#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,m; cin >> n >> m;
  vector<vector<int>> g(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int q; cin >> q;
  vector<int> x(q),y(q);
  REP(i,q) { cin >> x[i] >> y[i]; x[i]--; }

  int b = sqrt(2*m); // 次数がb以上を大きい頂点とする
  vector<int> large; // largeにb以上の頂点を入れておく
  REP(i,n) if ((int)g[i].size() >= b) large.push_back(i);

  // link[i][j] = jからiへの辺がlargeに向かっている場合はtrue
  vector link(n, vector<bool>(large.size()));
  REP(i, (int)large.size()) {
    link[large[i]][i] = true;
    for(int j: g[large[i]]) link[j][i] = true;
  }

  vector<int> update(n,-1), update_large(large.size(),-1);
  REP(i,q) {
    int last = update[x[i]];
    REP(j, (int)large.size()) {
      if (link[x[i]][j]) last = max(last, update_large[j]);
    }
    cout << (last == -1 ? 1 : y[last]) << endl;

    if ((int)g[x[i]].size() < b) {
      update[x[i]] = i;
      for (int j: g[x[i]]) update[j] = i;
    } else {
      auto it = find(large.begin(), large.end(), x[i]);
      update_large[it - large.begin()] = i;
    }
  }

  return 0;
}