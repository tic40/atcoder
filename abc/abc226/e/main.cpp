#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 998244353;
using P = pair<int,int>;

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

struct mint {
  long long x;
  mint(long long x=0):x((x%MOD+MOD)%MOD){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= MOD; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(long long t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  // for prime MOD
  mint inv() const { return pow(MOD-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int n,m;
int main() {
  cin >> n >> m;
  vector<P> edges;
  UnionFind uf(n);

  REP(i,m) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    edges.emplace_back(a,b);
    uf.unite(a,b);
  }
  // 連結成分毎の、numV: 頂点数 numE: 辺数
  vector<int> numV(n), numE(n);
  // 連結成分枚の頂点数と辺数を数える
  for (auto [a,b]: edges) numE[uf.root(a)]++;
  REP(i,n) numV[uf.root(i)]++;

  mint ans = 1;
  REP(i,n) {
    if (numV[i] == 0) continue;

    // ある連結成分についてその頂点数と辺数が一致していないならば0通り
    if (numV[i] != numE[i]) ans = 0;
    else ans *= 2;
  }

  cout << ans << endl;
  return 0;
}