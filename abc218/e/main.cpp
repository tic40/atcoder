#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

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

struct Edge {
  int from, to, cost;
  bool operator<(const Edge& o) const { // costで順序定義
    return cost < o.cost;
  }
};

int n,m;
vector<Edge> es;

void solve() {
  ll ans = 0;
  // costの昇順にソート
  sort(es.begin(), es.end());

  // 最初に全ての辺を削除して報酬をもらう
  for(auto v: es) ans += v.cost;

  UnionFind uf(n);
  for(auto [from, to, cost]: es) {
    if (cost < 0 || !uf.same(from,to)) {
      uf.unite(from,to);
      ans -= cost;
    }
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> m;
  REP(i,m) {
    int a,b,c;
    cin >> a >> b >> c;
    a--, b--;
    es.emplace_back((Edge){a,b,c});
  }

  solve();
  return 0;
}