#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

struct UnionFind {
  vector<int> d;
  vector<set<int>> member; // 頂点番号を管理
  UnionFind(int n=0): d(n,-1), member(n) {
    REP(i,n) member[i].insert(i);
  }
  int root(int x) {
    return d[x] < 0 ? x : d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;

    member[x].insert(member[y].begin(),member[y].end());
    while(member[x].size() > 10) member[x].erase(member[x].begin());
    return true;
  }
  int kth_largest(int v, int k) {
    v = root(v);
    if ((int)member[v].size() < k) return -1;
    auto it = member[v].rbegin();
    advance(it,k-1); // k 番目
    return *it + 1;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return -d[root(x)]; }
};

int main() {
  int n, q; cin >> n >> q;
  UnionFind uf(n);
  REP(_,q) {
    int t, u, v; cin >> t >> u >> v;
    u--; v--;
    if (t == 1) { uf.unite(u,v); }
    if (t == 2) cout << uf.kth_largest(u,v+1) << endl;
  }
  return 0;
}