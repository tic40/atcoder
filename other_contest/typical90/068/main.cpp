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

int n,q;
vector<int> t,x,y,v;

void solve() {
  // x[i] + y[i] = v[i];
  // sum[i]:= a[i] + a[i+1]
  vector<int> sum(n);
  REP(i,q) if (t[i] == 0) sum[x[i]] = v[i];

  vector<ll> potential(n);
  REP(i,n-1) potential[i+1] = sum[i] - potential[i];

  UnionFind uf(n);
  REP(i,q) {
    if (t[i] == 0) {
      uf.unite(x[i], y[i]);
    } else {
      if (!uf.same(x[i], y[i])) {
        cout << "Ambiguous" << endl;
        continue;
      }

      ll diff = v[i] - potential[x[i]];
      // x, y の偶奇が同じとき
      if ((x[i] + y[i]) % 2 == 0) {
        cout << potential[y[i]] + diff << endl;
      } else {
        cout << potential[y[i]] - diff << endl;
      }
    }
  }
  return;
}

int main() {
  cin >> n >> q;
  t.resize(q);
  x.resize(q);
  y.resize(q);
  v.resize(q);

  REP(i,q) {
    cin >> t[i] >> x[i] >> y[i] >> v[i];
    x[i]--, y[i]--;
  }

  solve();
  return 0;
}