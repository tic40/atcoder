#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n, -1) {};
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
};

int main() {
  int n,q; cin >> n >> q;
  UnionFind uf(n);
  int p,a,b;
  REP(i,q) {
    cin >> p >> a >> b;
    if (p==0) uf.unite(a,b);
    else cout << (uf.same(a,b) ? "Yes" : "No") << endl;
  }
  return 0;
}
