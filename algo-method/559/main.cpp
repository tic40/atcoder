#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n, -1) {} // -1で初期化(負の場合をrootとし、この値で木の深さも表す)
  int root(int x) {
    if (d[x] < 0) return x; // 負の場合はroot
    return d[x] = root(d[x]); // 経路圧縮: 自身が親でないときは、親に設定する
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
  int size(int x) { return -d[root(x)]; /* 木の深さ */ }
};

int main() {
  int n,m;
  cin >> n >> m;
  UnionFind uf(n);

  REP(i,m) {
    int a,b; cin >> a >> b;
    if (uf.same(a,b)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
      uf.unite(a,b);
    }
  }

  return 0;
}