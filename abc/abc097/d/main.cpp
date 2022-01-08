#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n, -1) {} // -1で初期化(負の場合をrootとし、この値で木の深さも表す)
  int root(int x) {
    if (d[x] < 0) return x; // 負の場合はroot
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y]; // -1からさらに—1していくことで、-2,-3… となり木の深さを表現
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return -d[root(x)]; /* 木の深さを正の値で返す */ }
};

int main() {
  int n,m,ans=0;
  cin >> n >> m;
  vector<int> p(n);
  REP(i,n) cin >> p[i];

  UnionFind uf(n);

  REP(i,m) {
    int a,b; cin >> a >> b;
    uf.unite(a-1,b-1);
  }
  REP(i,n) {
    if (uf.same(i, p[i]-1)) ans++;
  }
  cout << ans << endl;
  return 0;
}
