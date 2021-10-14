#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 998244353;

struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%MOD+MOD)%MOD){}
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
  mint pow(ll t) const {
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

template <typename T>
struct fenwick_tree {
  int _n; // 配列の要素数
  vector<T> data; // データの格納先
  fenwick_tree() : _n(0) {}
  fenwick_tree(int n) : _n(n), data(n) {}

  void add(int p, T x) {
    assert(0 <= p && p < _n);
    p++;
    while (p <= _n) {
      data[p - 1] += x;
      p += p & -p;
    }
  }

  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    return sum(r) - sum(l);
  }

  private:
    T sum(int r) {
      T s(0);
      while (0 < r) {
        s += data[r - 1];
        r -= r & -r;
      }
      return s;
    }
};

ll n;
vector<ll> a;

// ナイーブ解(TLE)
void solve() {
  // left, right を決めたとき(left <= right)
  // 2^(r-l-1) 通り存在する
  // それを合計すれば良い

  mint ans = 0;
  REP(i,n) {
    for (int j = i+1; j < n; j++) {
      if (a[i] <= a[j]) ans += pow(2,j-i-1);
    }
  }
  cout << ans << endl;
  return;
}

// 座標圧縮 + fenwick_tree(BIT)
void solve2() {
  // 座標圧縮
  map<int,int> mp;
  REP(i,n) mp[a[i]] = 0;

  int m = 0;
  for(auto& p: mp) p.second = m++;

  fenwick_tree<mint> b(m);

  mint ans = 0;
  mint two = 1, itwo = 1;

  REP(i,n) {
    int x = mp[a[i]];
    ans += two * b.sum(0, x+1);
    two *= 2;
    itwo /= 2;
    b.add(x, itwo);
  }

  cout << ans << endl;
}


int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];

  // solve();
  solve2();
  return 0;
}