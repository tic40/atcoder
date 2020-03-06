#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
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

int deg[100005];
vector<int> to[100005];

int main() {
  int n,m,k;
  cin >> n >> m >> k;
  UnionFind uf(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    deg[a]++; deg[b]++;
    uf.unite(a,b);
  }
  REP(i,k) {
    int a,b; cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  REP(i,n) {
    // 友達関係をたどってたどり着ける人の数
    // 友達及び友達関係から辿れる人の合計 - 親の分の1 - 直接つながっている友達
    int ans = uf.size(i) - 1 - deg[i];
    // ブロック関係を引く
    for (int u: to[i]) if (uf.same(i,u)) ans--;
    if (i > 0) cout << " ";
    cout << ans;
  }
  cout << endl;
}