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

  const int b = sqrt(2*m); // 次数がb以上を大きい頂点とする
  vector<int> large; // b以上の頂点の集合
  REP(i,n) if ((int)g[i].size() >= b) large.push_back(i);

  // link[i] = iからlargeに向かっている集合
  vector<vector<int>> link(n);
  for(int i: large) {
    link[i].push_back(i);
    for(int j: g[i]) link[j].push_back(i);
  }

  // 最後に更新した時間(index)を入れる
  vector<int> update(n,-1), update_large(n,-1);

  int q; cin >> q;
  vector<int> x(q),y(q);
  REP(i,q) {
    cin >> x[i] >> y[i]; x[i]--;
    int last = update[x[i]];
    for(int j: link[x[i]]) last = max(last, update_large[j]);
    cout << (last == -1 ? 1 : y[last]) << endl;

    if ((int)g[x[i]].size() < b) {
      update[x[i]] = i;
      for (int j: g[x[i]]) update[j] = i;
    } else {
      update_large[x[i]] = i;
    }
  }

  return 0;
}