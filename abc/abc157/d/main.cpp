#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n, -1) {}
  int root(int x) {
    if (d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return -d[root(x)]; }
};

int n,m,k;
vector<int> a,b,c,d;

void solve() {
  // friend list, block list
  vector<vector<int>> flist(n), blist(n);
  REP(i,m) {
    flist[a[i]].push_back(b[i]);
    flist[b[i]].push_back(a[i]);
  }
  REP(i,k) {
    blist[c[i]].push_back(d[i]);
    blist[d[i]].push_back(c[i]);
  }

  UnionFind uf(n);
  REP(i,m) uf.unite(a[i], b[i]);

  vector<int> ans(n);
  REP(i,n) {
    int cnt = uf.size(i) - 1 - flist[i].size();
    for (int v: blist[i]) if (uf.same(i, v)) cnt--;
    ans[i] = cnt;
  }

  REP(i,n) cout << ans[i] << " ";
  return;
}

int main() {
  cin >> n >> m >> k;

  a.resize(m); b.resize(m);
  REP(i,m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  c.resize(k); d.resize(k);
  REP(i,k) {
    cin >> c[i] >> d[i];
    c[i]--; d[i]--;
  }

  solve();
  return 0;
}