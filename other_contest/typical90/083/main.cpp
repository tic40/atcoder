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

  // 平方分割. 次数の総数の平方根
  int b = sqrt(m*2);
  // b 以上の次数を持つ頂点集合
  vector<int> large;
  // link[i] := 頂点 i と接続している large 頂点の集合
  // v と隣接している large 頂点の集合
  vector link(n, vector<int>());
  REP(i,n) {
    if ((int)g[i].size() >= b) {
      large.push_back(i);
      for(int j: g[i]) link[j].push_back(i);
    }
  }

  // 最後に更新した時刻
  vector<int> update(n,-1), update_l(n,-1);
  int q; cin >> q;
  vector<int> x(q),y(q),ans(q);
  REP(i,q) {
    cin >> x[i] >> y[i]; x[i]--;
    int last = max(update[x[i]], update_l[x[i]]);
    for(int v: link[x[i]]) last = max(last, update_l[v]);
    ans[i] = (last == -1 ? 1 : y[last]);

    if ((int)g[x[i]].size() >= b) {
      update_l[x[i]] = i;
    } else {
      update[x[i]] = i;
      for(int v: g[x[i]]) update[v] = i;
    }
  }

  REP(i,q) cout << ans[i] << endl;
  return 0;
}