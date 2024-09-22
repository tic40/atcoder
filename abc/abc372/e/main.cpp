#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

struct UnionFind {
  vector<int> d;
  vector<set<int>> st;
  UnionFind(int n = 0): d(n,-1), st(n) {
    REP(i,n) st[i].insert(i);
  }
  int root(int x) {
    return d[x] < 0 ? x : d[x] = root(d[x]);
  }
  int unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return 0;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;

    st[x].insert(st[y].begin(),st[y].end());
    while(st[x].size() > 10) st[x].erase(st[x].begin());
    return 1;
  }
  int kth_largest(int u, int k) {
    u = root(u);
    if ((int)st[u].size() < k) return -1;
    auto it = st[u].rbegin();
    advance(it,k-1);
    return *it+1;
  }
};

int main() {
  int n,q; cin >> n >> q;
  UnionFind uf(n);
  REP(_,q) {
    int t,u,v; cin >> t >> u >> v;
    u--; v--;
    if (t == 1) uf.unite(u,v);
    if (t == 2) cout << uf.kth_largest(u,v+1) << endl;
  }
  return 0;
}